#pragma once

#include <list>
#include <vector>

#include "Vector2.h"
#include "Triangle.h"

namespace appcore {
    class DoubleEdgeListFace;
    class DoubleEdgeListHalfEdge;
    class DoubleEdgeListVertex;
    class MonotonePolygon;

    class DoubleEdgeList
    {
    public:
        std::list<DoubleEdgeListVertex *>	vertices;
        std::list<DoubleEdgeListHalfEdge *>	edges;
        std::list<DoubleEdgeListFace *>		faces;

        DoubleEdgeList() = default;
        explicit DoubleEdgeList(const std::vector<Vector2>& points);
        ~DoubleEdgeList() = default;

        void initialize(const std::vector<Vector2>& points);
        void initialize(std::initializer_list<Vector2> points);
//        void addHalfEdges(int i, int j);
//        void addHalfEdges(DoubleEdgeListVertex* v1, DoubleEdgeListVertex* v2);
        DoubleEdgeListHalfEdge* addVertex(DoubleEdgeListHalfEdge* edge, Vector2 point, int new_index);
        void addHalfEdges(DoubleEdgeListVertex* v1, DoubleEdgeListVertex* v2,
                DoubleEdgeListHalfEdge* e1, DoubleEdgeListHalfEdge* e2);
//        void removeHalfEdges(int index);
//        void removeHalfEdges(DoubleEdgeListHalfEdge* edge);
//        void triangulateYMonotonePolygons();
//        void getTriangulation(std::vector<Triangle>& triangles) const;

//        static DoubleEdgeListHalfEdge*	getPreviousEdge(DoubleEdgeListVertex* vertex, DoubleEdgeListFace* face);
//        static DoubleEdgeListFace*		getReferenceFace(DoubleEdgeListVertex* v1, DoubleEdgeListVertex* v2);

//    private:
//        void triangulateYMonotonePolygon(const MonotonePolygon& monotonePolygon);
//        void getYMonotonePolygons(std::vector<MonotonePolygon>& monotonePolygons);
    };
}