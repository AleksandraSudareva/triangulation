#pragma once

#include "DCEL.h"

#include <set>

namespace appcore {
    class TriangleStorage  {
    public:
        TriangleStorage() = default;
        ~TriangleStorage() = default;

        DoubleEdgeList triangle;
//        std::list<std::pair<Vector2, DoubleEdgeListHalfEdge> > _potential_vertices;
//        std::list<std::pair<Vector2, DoubleEdgeListVertex> > _vertices;
        std::set<Vector2> _potential_vertices;
        std::set<Vector2> _vertices;
    };

    class Storage{
    public:
        Storage();
        ~Storage() = default;
        TriangleStorage _left;
        TriangleStorage _right;
    private:

    };
}