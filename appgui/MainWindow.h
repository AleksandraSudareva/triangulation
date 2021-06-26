#pragma once

#include "Widgets/MouseCoords.h"
#include "Widgets/ActionsLayout.h"
#include "GraphicsScene.h"
#include "GraphicsView.h"

#include <QMainWindow>
#include <QDockWidget>
#include <QAction>

namespace appgui {

    class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
        explicit MainWindow(int width, int height, QWidget *parent = nullptr);

        GraphicsView& GetPcbView();
        GraphicsScene& GetScene();

        MouseCoords& GetMouseCoords();
        ActionsLayout& GetActionsLayout();

        void Update(int numberOfLayers, int endTime);

        void AdjustView();

        void closeEvent(QCloseEvent* event) override;

    public slots:

        void OpenFileShowDialog();
        void SaveAsFileShowDialog();

        void WidgetViewChanged();

        void SAModeOn();

    private:
        struct WidgetGroup {
            QDockWidget* dock;
            QAction* action;
            void Check() const {
                if (dock->isHidden() == action->isChecked()) {
                    dock->setHidden(!action->isChecked());
                }
            }
        };

//        int _debugLayers;


        MouseCoords* _mouseCoords;
        ActionsLayout* _actionsLayout;

        WidgetGroup _selectionGroup;
//        WidgetGroup _layersGroup;
        WidgetGroup _mouseGroup;
        WidgetGroup _actionsGroup;
//        WidgetGroup _clearanceGroup;

        GraphicsView* _view;
        GraphicsScene* _scene;

        QMenu* _viewMenu;

        void CreateMenus();
        void CreateViewMenu();
        void CreateModeMenu();

//        void CreateTimeMachine();
//        void CreateSelectionLayout();
//        void CreateLayersLayout();
        void CreateMouseCoords();
        void CreateActionsLayout();
        void CreateClearanceWidget();

    };
}
