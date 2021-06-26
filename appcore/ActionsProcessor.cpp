#include "ActionsProcessor.h"
#include "Halfedge.h"

namespace appcore {
    double GetDistance(Vector2& a, Vector2& b) {
        return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    }

    bool InSegment(Vector2& a, Vector2& b, Vector2& c) {
        return std::abs(GetDistance(a, c) + GetDistance(c, b) - GetDistance(a, b)) < 1;
    }

    void ActionsProcessor::AddNewEdge(Vector2& potential_point, Storage& storage, SelectionProcessor& selectionProcessor) {
        bool left = true;
        if(potential_point.x > 100000) left = false;
        TriangleStorage* triangle;
        int new_index = 0;
        DoubleEdgeListHalfEdge* new_edge;
        if(left)
            triangle = &storage._left;
        else
            triangle = &storage._right;
        for(auto &edge: triangle->triangle.edges) {
            if(InSegment(edge->origin->point, edge->getDestination()->point, potential_point)) {
                new_index = edge->origin->index + edge->getDestination()->index;
                new_edge = triangle->triangle.addVertex(edge, potential_point, new_index);
                break;
            }
        }

        /// update potential points
        Vector2 new_potential;
        triangle->_potential_vertices.extract(potential_point);
        triangle->_vertices.emplace(potential_point);

        double m1 = 1. * new_edge->origin->index / (new_edge->origin->index + new_edge->getDestination()->index);
        double m2 = 1. * new_edge->getDestination()->index / (new_edge->origin->index + new_edge->getDestination()->index);
        new_potential.x = m1 * new_edge->origin->point.x + m2 * new_edge->getDestination()->point.x;
        new_potential.y = m1 * new_edge->origin->point.y + m2 * new_edge->getDestination()->point.y;
//        new_potential.x =(new_edge->origin->point.x +  new_edge->getDestination()->point.x) / 2;
//        new_potential.y = ( new_edge->origin->point.y +  new_edge->getDestination()->point.y) / 2;
        triangle->_potential_vertices.emplace(new_potential);
//
        m1 = 1. * new_edge->getPrevious()->origin->index / (new_edge->getPrevious()->origin->index + new_edge->origin->index);
        m2 = 1. * new_edge->origin->index / (new_edge->getPrevious()->origin->index + new_edge->origin->index);
        new_potential.x = m1 * new_edge->getPrevious()->origin->point.x + m2 * new_edge->origin->point.x;
        new_potential.y = m1 * new_edge->getPrevious()->origin->point.y + m2 * new_edge->origin->point.y;
//        new_potential.x = (new_edge->getPrevious()->origin->point.x +  new_edge->origin->point.x) /2;
//        new_potential.y = ( new_edge->getPrevious()->origin->point.y +  new_edge->origin->point.y) / 2;
        triangle->_potential_vertices.emplace(new_potential);

        auto p1 = new_edge->next->getDestination();
        auto p2 = new_edge->twin->getPrevious()->origin;
        new_edge->origin->index = new_index;

        //// переделать с учётом индексов!!!
        if (new_edge->face != nullptr) {
            triangle->triangle.addHalfEdges(p1, new_edge->origin, new_edge->next, new_edge->getPrevious());
            m1 = 1. * p1->index / (p1->index + new_edge->origin->index);
            m2 = 1. * new_edge->origin->index / (p1->index + new_edge->origin->index);
            new_potential.x = m1 * p1->point.x + m2 * potential_point.x;
            new_potential.y = m1 * p1->point.y + m2 * potential_point.y;
//            new_potential.x = (p1->point.x + potential_point.x)/2;
//            new_potential.y = (p1->point.y +  potential_point.y)/2;
            triangle->_potential_vertices.emplace(new_potential);
            box b(point(new_potential.x - 0.1, new_potential.y - 0.1), point(new_potential.x + 0.1, new_potential.y + 0.1));
            selectionProcessor._rtree.insert(std::make_pair(b, new_potential));
        }
        if (new_edge->twin->face != nullptr) {
            triangle->triangle.addHalfEdges(p2, new_edge->origin, new_edge->twin->next->next, new_edge->twin);
            m1 = 1. * p2->index / (p2->index + new_edge->origin->index);
            m2 = 1. * new_edge->origin->index / (p2->index + new_edge->origin->index);
            new_potential.x = m1 * p2->point.x + m2 * potential_point.x;
            new_potential.y = m1 * p2->point.y + m2 * potential_point.y;
//            new_potential.x = (p2->point.x + potential_point.x)/2;
//            new_potential.y = (p2->point.y +  potential_point.y)/2;
            triangle->_potential_vertices.emplace(new_potential);
            box b(point(new_potential.x - 0.1, new_potential.y - 0.1), point(new_potential.x + 0.1, new_potential.y + 0.1));
            selectionProcessor._rtree.insert(std::make_pair(b, new_potential));
        }
    }

}