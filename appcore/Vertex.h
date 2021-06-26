#pragma once

#include "Vector2.h"

namespace appcore {
    class DoubleEdgeListHalfEdge;

    class DoubleEdgeListVertex
    {
    public:

        /* The comparable data for this node */
        Vector2 point;
        int index = 1;

        /* The leaving edge */
        DoubleEdgeListHalfEdge* leaving;

        explicit DoubleEdgeListVertex(const Vector2& point);

        DoubleEdgeListHalfEdge* getEdgeTo(DoubleEdgeListVertex* node) const;
    };

}