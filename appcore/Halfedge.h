#pragma once

#include "Vertex.h"
#include "Face.h"


namespace appcore {
    class DoubleEdgeListHalfEdge
    {

    public:
//        DoubleEdgeListVertex(const DoubleEdgeListVertex &edge){
//            origin = edge.origin;
//        }

        DoubleEdgeListVertex	*origin;

        DoubleEdgeListHalfEdge	*twin;

        /* The incident half edge in the list having the same face */
        DoubleEdgeListHalfEdge	*next;

        /* The incident face of this half edge */
        DoubleEdgeListFace		*face;

        bool visited;

        DoubleEdgeListHalfEdge()
                : origin(nullptr)
                , twin(nullptr)
                , next(nullptr)
                , face(nullptr)
                ,visited(false)
        {}

        /* Return this half edge's destination. */
        DoubleEdgeListVertex* getDestination() const;

        /* Returns the previous half edge having the same face as this half edge. */
        DoubleEdgeListHalfEdge* getPrevious();

        /* Returns this half edge's face. */
        DoubleEdgeListFace* getFace() const;
    };

}