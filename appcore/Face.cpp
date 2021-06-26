#include "Face.h"
#include "Halfedge.h"

namespace appcore {

    int DoubleEdgeListFace::getEdgeCount() const
    {
        DoubleEdgeListHalfEdge* edge = this->edge;
        int count = 0;
        if (edge != nullptr) {
            count++;
            while (edge->next != this->edge) {
                count++;
                edge = edge->next;
            }
        }
        return count;
    }

}