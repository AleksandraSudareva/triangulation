#include "ActionsLayout.h"

#include "../../Session.h"

#include <QGroupBox>
#include <QVBoxLayout>
#include <QPushButton>

namespace appgui {

    ActionsLayout::ActionsLayout(QWidget *parent) : QWidget(parent) {

        auto groupBox = new QGroupBox(this);
        auto layout = new QVBoxLayout(this);

        for (auto & t : Actions::AllSelectionTypes) {
            auto button = new QPushButton(tr(Actions::ToString(t)), this);
            connect(button, &QPushButton::pressed, [this, t](){ type = t; Session::DoAction(); });
            layout->addWidget(button);
        }

        groupBox->setLayout(layout);
        layout->setAlignment(Qt::AlignTop);

        this->setLayout(layout);
    }
}