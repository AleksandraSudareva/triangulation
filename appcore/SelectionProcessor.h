#pragma once

#include "Vector2.h"
#include "Storage.h"

#include <optional>
#include <functional>
#include <vector>
#include <set>

#include <boost/geometry.hpp>
#include <boost/geometry/index/rtree.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/geometries/box.hpp>
#include <boost/geometry/algorithms/equals.hpp>

namespace appcore {

    class Storage;

    namespace bg = boost::geometry;
    namespace bgi = boost::geometry::index;
    typedef bg::model::point<int32_t, 2, bg::cs::cartesian> point;
    typedef bg::model::box<point> box;
//    typedef std::pair<box, Vector2> value;

    template<typename T>
    using value = std::pair<box, T>;

    template<typename T>
    using rtree = bgi::rtree<value<T>, bgi::rstar<20, 5> >;

    class SelectionProcessor {

    public:
        SelectionProcessor() = default;
        explicit SelectionProcessor(Storage & storage);
        ~SelectionProcessor() = default;

//        Vector2 SelectObjects(Vector2 p1, Vector2 p2);
        std::optional<Vector2> GetObject(Vector2 p1, Vector2 p2);

        rtree<Vector2> _rtree;
    private:

    };
}