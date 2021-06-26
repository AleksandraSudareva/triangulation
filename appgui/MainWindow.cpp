#include "MainWindow.h"

#include "../Session.h"

#include <QMenuBar>
#include <QVBoxLayout>
#include <QFileDialog>

#include <iostream>

namespace appgui {

    MainWindow::MainWindow(int width, int height, QWidget *parent) : QMainWindow(parent) {
        this->setFixedWidth(width);
        this->setFixedHeight(height);
        this->setWindowTitle("Oda's conjecture");

//        CreateTimeMachine();
//        CreateLayersLayout();
//        CreateSelectionLayout();
        CreateActionsLayout();
        CreateMouseCoords();

        CreateMenus();

        _view = new GraphicsView(centralWidget());
        setCentralWidget(_view);

        _scene = new GraphicsScene(0, 0, 0, 0, _view);
        _view->setScene(_scene);
    }

//    TimeMachine& MainWindow::GetTimeMachine()
//    {
//        return *_timeMachineWidget;
//    }
//
//    SelectionLayout &MainWindow::GetSelectionLayout() {
//        return *_selectionLayout;
//    }
//
//    LayersLayout &MainWindow::GetLayersLayout() {
//        return *_layersLayout;
//    }

    MouseCoords &MainWindow::GetMouseCoords() {
        return *_mouseCoords;
    }

    GraphicsView& MainWindow::GetPcbView()
    {
        return *_view;
    }

    GraphicsScene& MainWindow::GetScene()
    {
        return *_scene;
    }

    ActionsLayout &MainWindow::GetActionsLayout() {
        return *_actionsLayout;
    }

//    void MainWindow::CreateTimeMachine()
//    {
//        auto* dockWidget = new QDockWidget(tr("Time Machine"), this);
//        dockWidget->setAllowedAreas(Qt::BottomDockWidgetArea);
//        _timeMachineWidget = new TimeMachine(this);
//
//        dockWidget->setWidget(_timeMachineWidget);
//        addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
//    }

//    void MainWindow::CreateSelectionLayout() {
//        _selectionGroup.dock = new QDockWidget(tr("Selection"), this);
//        _selectionGroup.dock->setAllowedAreas(Qt::LeftDockWidgetArea |
//                                              Qt::RightDockWidgetArea);
//
//        _selectionLayout = new SelectionLayout(this);
//        _selectionGroup.dock->setWidget(_selectionLayout);
//        addDockWidget(Qt::LeftDockWidgetArea, _selectionGroup.dock);
//    }
//
//    void MainWindow::CreateLayersLayout() {
//        _layersGroup.dock = new QDockWidget(tr("Layers"), this);
//        _layersGroup.dock->setAllowedAreas(Qt::LeftDockWidgetArea |
//                                           Qt::RightDockWidgetArea);
//
//        _layersLayout = new LayersLayout(1, _debugLayers, this);
//        _layersGroup.dock->setWidget(_layersLayout);
//        addDockWidget(Qt::LeftDockWidgetArea, _layersGroup.dock);
//    }

    void MainWindow::CreateMouseCoords() {
        _mouseGroup.dock = new QDockWidget(tr("Coordinates"), this);
        _mouseGroup.dock->setAllowedAreas(Qt::BottomDockWidgetArea | Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
        _mouseCoords = new MouseCoords(this);

        _mouseGroup.dock->setWidget(_mouseCoords);
        addDockWidget(Qt::BottomDockWidgetArea, _mouseGroup.dock);
    }

    void MainWindow::CreateActionsLayout() {
        _actionsGroup.dock = new QDockWidget(tr("Actions"), this);
        _actionsGroup.dock->setAllowedAreas(Qt::LeftDockWidgetArea |
                                            Qt::RightDockWidgetArea);

        _actionsLayout = new ActionsLayout(this);
        _actionsGroup.dock->setWidget(_actionsLayout);
        addDockWidget(Qt::RightDockWidgetArea, _actionsGroup.dock);
    }

//    void MainWindow::CreateModeMenu() {
//        auto modeGroup = new QActionGroup(this);
//        modeGroup->setExclusive(true);
//
//        auto saMode = new QAction("&Selection-Action", modeGroup);
//        saMode->setCheckable(true);
//        saMode->setChecked(true);
//        connect(saMode, SIGNAL(triggered()), this, SLOT(SAModeOn()));
//
//        auto irMode = new QAction("&Interactive routing", modeGroup);
//        irMode->setCheckable(true);
//        irMode->setChecked(false);
//        connect(irMode, SIGNAL(triggered()), this, SLOT(IRModeOn()));
//
//        auto modeMenu = menuBar()->addMenu("&Mode");
//        modeMenu->addAction(saMode);
//        modeMenu->addAction(irMode);
//    }

    void MainWindow::CreateViewMenu() {

//        _layersGroup.action = new QAction("&Layers", this);
//        _layersGroup.action->setCheckable(true);
//        _layersGroup.action->setChecked(true);
//        connect(_layersGroup.action, SIGNAL(triggered()), this, SLOT(WidgetViewChanged()));

        _selectionGroup.action = new QAction("&Selection", this);
        _selectionGroup.action->setCheckable(true);
        _selectionGroup.action->setChecked(true);
        connect(_selectionGroup.action, SIGNAL(triggered()), this, SLOT(WidgetViewChanged()));

        _mouseGroup.action = new QAction("&Coordinates", this);
        _mouseGroup.action->setCheckable(true);
        _mouseGroup.action->setChecked(true);
        connect(_mouseGroup.action, SIGNAL(triggered()), this, SLOT(WidgetViewChanged()));

        _actionsGroup.action = new QAction("&Actions", this);
        _actionsGroup.action->setCheckable(true);
        _actionsGroup.action->setChecked(true);
        connect(_actionsGroup.action, SIGNAL(triggered()), this, SLOT(WidgetViewChanged()));


        _viewMenu = menuBar()->addMenu(tr("&View"));
        _viewMenu->addAction(_selectionGroup.action);
        _viewMenu->addAction(_mouseGroup.action);
        _viewMenu->addAction(_actionsGroup.action);
    }

    void MainWindow::CreateMenus()
    {
        auto* fileMenu = menuBar()->addMenu(tr("&File"));

        auto* openAction = fileMenu->addAction("&Open");
        openAction->setShortcut(QKeySequence(tr("Ctrl+O")));
        connect(openAction, &QAction::triggered, this, &MainWindow::OpenFileShowDialog);

        auto* saveAsAction = fileMenu->addAction("&Save as");
        saveAsAction->setShortcut(QKeySequence(tr("Ctrl+S")));
        connect(saveAsAction, &QAction::triggered, this, &MainWindow::SaveAsFileShowDialog);


        auto* editMenu = menuBar()->addMenu(tr("&Edit"));

//        auto* undoAction = editMenu->addAction("&Undo");
//        undoAction->setShortcut(QKeySequence(tr("Ctrl+Z")));
//        connect(undoAction, &QAction::triggered, [](){ Session::Undo(); });
//
//        auto* redoAction = editMenu->addAction("&Redo");
//        redoAction->setShortcut(QKeySequence(tr("Ctrl+Y")));
//        connect(redoAction, &QAction::triggered, [](){ Session::Redo(); });
//
//        auto* deleteAction = editMenu->addAction("&Delete selected");
//        deleteAction->setShortcut(QKeySequence(tr("Ctrl+D")));
//        connect(deleteAction, &QAction::triggered,  [this](){_actionsLayout->type = Actions::ActionType::Delete; Session::DoAction(); });

        CreateViewMenu();

        auto modeGroup = new QActionGroup(this);
        modeGroup->setExclusive(true);
        auto saMode = new QAction("&Selection-Action", modeGroup);
        saMode->setCheckable(true);
        saMode->setChecked(true);
        connect(saMode, SIGNAL(triggered()), this, SLOT(SAModeOn()));
//        auto modeMenu = menuBar()->addMenu("&Mode");
//        modeMenu->addAction(saMode);
    }

    void MainWindow::OpenFileShowDialog()
    {
        auto fileName = QFileDialog::getOpenFileName(this,
                                                     tr("Open json Pcb Layout"), /*tr(DEFAULT_FILE),*/ tr("Json Files (*.json)"));
//        if (!fileName.isEmpty())
//            Session::OpenFile(fileName.toStdString());
    }

    void MainWindow::SaveAsFileShowDialog()
    {
        auto fileName = QFileDialog::getSaveFileName(this,
                                                     tr("Save json Pcb Layout"), /*tr(DEFAULT_FILE),*/ tr("Json Files (*.json)"));
//        if (!fileName.isEmpty())
//            Session::SaveFile(fileName.toStdString());
    }

    void MainWindow::AdjustView()
    {
        auto rect = _scene->itemsBoundingRect();

        auto rect2 = rect.adjusted(-rect.width(), -rect.height(), rect.width(), rect.height());
        _scene->setSceneRect(rect2);

        _view->fitInView(rect, Qt::KeepAspectRatio);
    }

    void MainWindow::WidgetViewChanged() {
        _selectionGroup.Check();
        _mouseGroup.Check();
        _actionsGroup.Check();
    }

    void MainWindow::Update(int numberOfLayers, int endTime) {
//        _layersLayout->SetNumberOfLayers(numberOfLayers, _debugLayers);

//        _timeMachineWidget->SetMaxTime(endTime);
    }

    void MainWindow::closeEvent(QCloseEvent *event) {
        delete Session::info;
        QWidget::closeEvent(event);
    }

    void MainWindow::SAModeOn() {

        Session::ClearIndividualSelection();
        _scene->ClearScene();

        delete _scene;
        delete _view;

        _view = new GraphicsView(centralWidget());
        setCentralWidget(_view);

        _scene = new GraphicsScene(0, 0, 0, 0, _view);
        _view->setScene(_scene);

        _viewMenu->setEnabled(true);
        WidgetViewChanged();

        Session::info->UpdateScene();
        AdjustView();
    }
}
