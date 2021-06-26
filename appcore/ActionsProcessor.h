#pragma once

#include "Vector2.h"
#include "Storage.h"
#include "SelectionProcessor.h"



#include <vector>
#include <set>

namespace appcore {
    class ActionsProcessor {
    public:
        static void AddNewEdge(Vector2& potential_point, Storage& storage, SelectionProcessor& selectionProcessor);
    };
}