#pragma once

#include <QGraphicsView>
#include <QKeyEvent>

namespace appgui {

    class GraphicsView : public QGraphicsView {
    Q_OBJECT

    public:
        explicit GraphicsView(QWidget* parent = nullptr);

        void keyPressEvent(QKeyEvent *event) override;

        void keyReleaseEvent(QKeyEvent *event) override;

        void mousePressEvent(QMouseEvent *event) override;

        void mouseReleaseEvent(QMouseEvent *event) override;

    private:
        QPoint _startMouse;
        QPoint _endMouse;
        bool _isSelecting = false;

    protected:
        void mouseMoveEvent(QMouseEvent* event) override;

        void wheelEvent(QWheelEvent* event) override;
    };

}
