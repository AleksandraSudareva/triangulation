#include "HalfEdge.h"

namespace appcore {

    DoubleEdgeListVertex* DoubleEdgeListHalfEdge::getDestination() const
    {
        return this->next->origin;
    }

    DoubleEdgeListHalfEdge* DoubleEdgeListHalfEdge::getPrevious()
    {
//        DoubleEdgeListHalfEdge* edge = twin->next->twin;
        DoubleEdgeListHalfEdge* _edge = this;
        if (this == nullptr) return nullptr;
//         walk around the face
        //traverse through edges to target vertex
        while (_edge->next != this) {
//            edge = edge->next->twin;
            _edge = _edge->next;
        }
        return _edge;
    }

    DoubleEdgeListFace* DoubleEdgeListHalfEdge::getFace() const
    {
        return this->face;
    }

}