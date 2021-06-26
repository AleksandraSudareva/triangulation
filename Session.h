#pragma once

#include <string>
#include <vector>
#include <map>

#include "appcore/Storage.h"
#include "appgui/GraphicsScene.h"
#include "appcore/SelectionProcessor.h"

#include "appcore/DCEL.h"
#include "appcore/Halfedge.h"

#include <QPoint>

class QPoint;

namespace appgui {
    class MainWindow;
}

namespace appcore {
    class Storage;
    class DoubleEdgeListVertex;
    class DoubleEdgeListHalfEdge;
    class DoubleEdgeListFace;
    class DoubleEdgeList;
}

struct Converter {
    inline static appcore::Vector2 Do(QPoint p) {
        return appcore::Vector2(double(p.x()), double(p.y()));
    }

    inline static QPoint Do(appcore::Vector2 p) {
        return QPoint(p.x, p.y);
    }

//    static std::list<QPoint> Do(appcore::Octagon o);
//    static std::list<QPoint> Do(const appcore::Trajectory<appcore::Vector2>& t);
//    static QStringList Do(const std::list<std::string>& list);

};

class Session {
public:
    Session() = default;

    ~Session();
//    appcore::Storage* storage;
//    appcore::Storage GetStorage() { return *storage; }
//};

//public:
    appgui::MainWindow* mainWindow;
    appcore::Storage* storage;
    std::vector<appcore::Vector2> selected;
    appcore::SelectionProcessor* selectionProcessor; ///////////// ?????????????
    static Session* info;

    static int Start(int argc, char *argv[]);

//    static void OpenFile(const std::string& path);
//    static void SaveFile(const std::string& path);

    void UpdateScene() const;

//    static void LayersTurnedOnOff(int layer, bool isOn);
//    static void TimeChanged(int time);

    static void SelectionOccurs(QPoint q1, QPoint q2);
    static void IndividualSelectionOccurs(QPoint q1, QPoint q2);
    static void ClearSelection();
    static void ClearIndividualSelection();

    static void DoAction();
    static void Undo();
    static void Redo();
    static void AddToScene(appcore::Vector2 location, appgui::GraphicsScene& scene, double r = 100., bool gray=true);
    static void AddToScene(std::list<appcore::Vector2> location, appgui::GraphicsScene& scene);

private:
    explicit Session(bool debug);

    void UpdateStorage();

//    std::vector<int> GetTurnedOnLayers();
};