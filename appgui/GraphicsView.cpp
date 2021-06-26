#include "GraphicsView.h"
#include <QScrollBar>

#include "../Session.h"
#include "MainWindow.h"


namespace appgui
{
    GraphicsView::GraphicsView(QWidget* parent) : QGraphicsView(parent)
    {
        horizontalScrollBar()->setStyleSheet("QScrollBar {height:0px;}");
        verticalScrollBar()->setStyleSheet("QScrollBar {width:0px;}");

        setMouseTracking(true);
        setDragMode(QGraphicsView::ScrollHandDrag);
        scale(1, -1);
        setGeometry(200, 0, 1600, 1000);
    }

    void GraphicsView::mouseMoveEvent(QMouseEvent *event) {
        Session::info->mainWindow->GetMouseCoords().SetCoords(mapToScene(event->pos()).toPoint());

        QGraphicsView::mouseMoveEvent(event);
    }

    void GraphicsView::wheelEvent(QWheelEvent* event)
    {
        if (event->angleDelta().y() > 0)
            scale(1.25, 1.25);
        else
            scale(0.8, 0.8);

        Session::info->mainWindow->GetMouseCoords().SetCoords(mapToScene(event->pos()).toPoint());
    }

    void GraphicsView::keyPressEvent(QKeyEvent* event)
    {
        if (event->key() == Qt::Key_Control)
            setDragMode(QGraphicsView::RubberBandDrag);

        if (event->key() == Qt::Key_Escape) {
            Session::ClearSelection();
            Session::ClearIndividualSelection();
        }

        QGraphicsView::keyPressEvent(event);

    }

    void GraphicsView::keyReleaseEvent(QKeyEvent* event)
    {
        if (event->key() == Qt::Key_Control && !_isSelecting)
            setDragMode(QGraphicsView::ScrollHandDrag);
        QGraphicsView::keyReleaseEvent(event);
    }

    void GraphicsView::mousePressEvent(QMouseEvent* event)
    {
        QGraphicsView::mousePressEvent(event);

        if (event->modifiers().testFlag(Qt::ControlModifier))
        {
            _startMouse = event->pos();
            _isSelecting = true;
        }
    }

    void GraphicsView::mouseReleaseEvent(QMouseEvent* event)
    {
        QGraphicsView::mouseReleaseEvent(event);

        if (!_isSelecting)
            return;

        _endMouse = event->pos();
        _isSelecting = false;
        setDragMode(QGraphicsView::ScrollHandDrag);

        auto p1 = mapToScene(_startMouse).toPoint();
        auto p2 = mapToScene(_endMouse).toPoint();

        if (event->modifiers().testFlag(Qt::ShiftModifier))
        {
            Session::IndividualSelectionOccurs(p1, p2);
        } else
        {
            Session::SelectionOccurs(p1, p2);
        }
    }

}