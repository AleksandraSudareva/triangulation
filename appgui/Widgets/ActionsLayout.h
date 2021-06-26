#pragma once

#include <QWidget>

#include "Actions.h"

namespace appgui {
    class ActionsLayout : public QWidget {
    Q_OBJECT
    public:
        explicit ActionsLayout(QWidget *parent = nullptr);

        Actions::ActionType type;
    };
}