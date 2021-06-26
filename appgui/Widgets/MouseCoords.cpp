#include "MouseCoords.h"

#include <QHBoxLayout>

namespace appgui {

    MouseCoords::MouseCoords(QWidget *parent)  : QWidget(parent){
        auto* layout = new QHBoxLayout(this);
        layout->setAlignment(Qt::AlignLeft);

        _xL = new QLabel("0", this);
        _yL = new QLabel("0", this);

        layout->addWidget(_xL);
        layout->addWidget(_yL);

        this->setLayout(layout);
    }

    void MouseCoords::SetCoords(QPoint p) {
        _xL->setText(QString::number(p.x(), 'g', 10));
        _yL->setText(QString::number(p.y(), 'g', 10));
    }

}