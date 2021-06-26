#pragma once

#include <array>

namespace appgui {
    struct Actions {
        enum class ActionType
        {
            MakeNewEdge
        };

        static constexpr std::array<ActionType, 1> AllSelectionTypes {
                ActionType::MakeNewEdge
        };

        static const char* ToString(ActionType type) {
            switch (type) {

                case ActionType::MakeNewEdge:
                    return "Add new edge";
                default:
                    return "";
            }
        }
    };
}