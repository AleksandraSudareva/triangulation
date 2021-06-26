#include "Session.h"
#include "appcore/ActionsProcessor.h"
#include "appcore/SelectionProcessor.h"
#include "appgui/MainWindow.h"
#include "appgui/GraphicsScene.h"


//#include "IO/JsonVersions.h"

#include <QPoint>
#include <QColor>
#include <QDebug>
#include <QApplication>

using namespace appcore;

Session* Session::info = nullptr;

int Session::Start(int argc, char *argv[]) {

    QApplication a(argc, argv);

    info = new Session(false);

    info->mainWindow->show();
    info->UpdateScene();
//    OpenFile();

    return QApplication::exec();
}

Session::Session(bool debug) {
    mainWindow = new appgui::MainWindow(1900, 1000, 0);
    storage = new appcore::Storage();
    selectionProcessor = new appcore::SelectionProcessor(*storage);
}

Session::~Session() {
    delete selectionProcessor;
    delete storage;
}

void Session::SelectionOccurs(QPoint q1, QPoint q2) {

    qDebug() << QString("Selection");
    qDebug() << QString("---------") << q1;
    qDebug() << QString("---------") << q2;

    auto & scene = dynamic_cast<appgui::GraphicsScene&>(info->mainWindow->GetScene());
    scene.ClearSelection();

    auto p1 = Converter::Do(q1);
    auto p2 = Converter::Do(q2);
    auto rect_p = info->selectionProcessor->GetObject(p1, p2);
    if (rect_p.has_value()) {
        auto x1 = rect_p.value().x - 2000.;
        auto y1 = rect_p.value().y - 2000.;
        auto x2 = rect_p.value().x + 2000.;
        auto y2 = rect_p.value().y + 2000.;

        auto *item = scene.addSelectionOctagon({Converter::Do(Vector2(x1, y1)), Converter::Do(Vector2(x1, y2)),
                                                Converter::Do(Vector2(x2, y2)), Converter::Do(Vector2(x2, y1))});
        item->setWidth(5);
        item->setColor(Qt::red);
    }

    ClearIndividualSelection();
}

void Session::IndividualSelectionOccurs(QPoint q1, QPoint q2) {
    qDebug() << QString("IndividualSelection");
    qDebug() << QString("---------") << q1;
    qDebug() << QString("---------") << q2;

    auto & scene = dynamic_cast<appgui::GraphicsScene&>(info->mainWindow->GetScene());
    scene.ClearSelection();

    auto p1 = Converter::Do(q1);
    auto p2 = Converter::Do(q2);

    ClearIndividualSelection();
    auto rect_p = info->selectionProcessor->GetObject(p1, p2);
    if (!rect_p.has_value()) {
        ClearIndividualSelection();
    } else {
        auto x1 = rect_p.value().x - 2000.;
        auto y1 = rect_p.value().y - 2000.;
        auto x2 = rect_p.value().x + 2000.;
        auto y2 = rect_p.value().y + 2000.;

        info->selected.insert(std::end(info->selected), rect_p.value());

        auto *item = scene.addIndividualSelectionOctagon(
                {Converter::Do(Vector2(x1, y1)), Converter::Do(Vector2(x1, y2)),
                 Converter::Do(Vector2(x2, y2)), Converter::Do(Vector2(x2, y1))});
        item->setWidth(5);
        item->setColor(Qt::white);
    }

}

//void Session::OpenFile(const std::string &path) {
//
//    if (auto reader = pcbio::PcbJsonFactory::GetReader(path)) {
//
//        delete info->storage;
//        info->storage = new pcbcore::Storage();
//
//        reader->Read();
//
//        info->UpdateStorage();
//    }
//
//}
//
//void Session::SaveFile(const std::string &path) {
//    if (auto writer = pcbio::PcbJsonFactory::GetWriter("0.2", path)) {
//        writer->Write();
//    }
//}

void Session::UpdateStorage() {
//    mainWindow->Update(appcore::PrimitivesUtils::GetNumberOfLayers(), storage->GetCurrentEnd());
    UpdateScene();
    mainWindow->AdjustView();
}

void Session::AddToScene(appcore::Vector2 location, appgui::GraphicsScene& scene, double r, bool gray) {
    QPen pen;
    pen.setCosmetic(true);

    if(gray) {
        auto item = scene.addEllipse(location.x - r, location.y - r, 2 * r, 2 * r, pen, Qt::white);
        item->setOpacity(1);
        item->setZValue(100);

    } else {
        auto item = scene.addEllipse(location.x - r, location.y - r, 2 * r, 2 * r, pen, Qt::cyan);
        item->setOpacity(1);
        item->setZValue(100);
    }
}

void Session::AddToScene(std::list<appcore::Vector2> location, appgui::GraphicsScene& scene) {
    std::list<QPoint> points;
    points.emplace_back(Converter::Do(location.front()));
    points.emplace_back(Converter::Do(location.back()));
    auto *lineItem = scene.addTrace(points, 0);
    lineItem->SetColor(Qt::yellow);
    lineItem->setZValue(200);
}

void Session::UpdateScene() const {
    if (!storage)
        return;

    auto& scene = mainWindow->GetScene();
    scene.ClearScene();

    for (auto& ob : info->storage->_right._vertices) {
        AddToScene(ob, scene, 1000., true);
    }
    for (auto& ob : info->storage->_right._potential_vertices) {
        AddToScene(ob, scene, 1000., false);
    }
    for (auto& ob : info->storage->_left._vertices) {
        AddToScene(ob, scene, 1000., true);
    }
    for (auto& ob : info->storage->_left._potential_vertices) {
        AddToScene(ob, scene, 1000., false);
    }
    for (auto& edge : info->storage->_left.triangle.edges) {
        AddToScene(std::list<appcore::Vector2>{edge->origin->point, edge->getDestination()->point}, scene);
    }
    for (auto& edge : info->storage->_right.triangle.edges) {
        AddToScene(std::list<appcore::Vector2>{edge->origin->point, edge->getDestination()->point}, scene);
    }
}

void Session::ClearSelection() {
    info->mainWindow->GetScene().ClearSelection();
}

void Session::ClearIndividualSelection() {
    info->selected.clear();
    info->mainWindow->GetScene().ClearIndividualSelection();
}

void Session::DoAction() {
    if (info->selected.empty()) return;

    switch (info->mainWindow->GetActionsLayout().type) {

        case appgui::Actions::ActionType::MakeNewEdge:
            appcore::ActionsProcessor::AddNewEdge(info->selected.front(), *info->storage, *info->selectionProcessor);
            break;
        default:
            break;
    }

    ClearIndividualSelection();
    info->UpdateScene();
}



