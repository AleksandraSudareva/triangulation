#pragma once

//#include "Halfedge.h"

namespace appcore {

    class DoubleEdgeListHalfEdge;

    class DoubleEdgeListFace
    {
    public:

        DoubleEdgeListHalfEdge* edge;

        DoubleEdgeListFace()
                : edge(nullptr)
        {}

        int getEdgeCount() const;
    };


}
