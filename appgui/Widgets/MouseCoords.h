#pragma once

#include <QWidget>
#include <QLabel>

namespace appgui {

    class MouseCoords : public QWidget {
        Q_OBJECT
    public:
        explicit MouseCoords(QWidget* parent = nullptr);

        void SetCoords(QPoint p);

    private:
        QLabel* _xL;
        QLabel* _yL;
    };
}