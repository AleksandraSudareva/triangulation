#include "Storage.h"

namespace appcore {
    Storage::Storage() /*:
            _left(), _right()*/ {
//        _left=TriangleStorage();
//        _right=TriangleStorage();
        _left.triangle.initialize({Vector2(0., 0.), Vector2(100000., 0.), Vector2(50000., 86602.54)});
        _right.triangle.initialize({Vector2(200000., 0.), Vector2(300000., 0.), Vector2(250000., 86602.54)});


        _left._vertices.emplace(0., 0.);
        _left._vertices.emplace(100000., 0.);
        _left._vertices.emplace(50000., 86602.54);
        _right._vertices.emplace(200000., 0.);
        _right._vertices.emplace(300000., 0.);
        _right._vertices.emplace(250000., 86602.54);

        _left._potential_vertices.emplace(50000., 0.);
        _left._potential_vertices.emplace(25000.,43301.27);
        _left._potential_vertices.emplace(75000.,43301.27);
        _right._potential_vertices.emplace(250000., 0.);
        _right._potential_vertices.emplace(225000.,43301.27);
        _right._potential_vertices.emplace(275000.,43301.27);
    }

}