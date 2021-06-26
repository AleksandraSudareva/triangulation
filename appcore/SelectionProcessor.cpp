#include "SelectionProcessor.h"

#include "../Session.h"

#include <utility>



namespace appcore {
    SelectionProcessor::SelectionProcessor(Storage & storage) : _rtree() {
        for ( auto& item : storage._left._vertices )
        {
            // create a box
            box b(point(item.x - 0.1, item.y - 0.1), point(item.x + 0.1, item.y + 0.1));
            // insert new value
            _rtree.insert(std::make_pair(b, item));
        }
        for ( auto& item : storage._right._vertices )
        {
            // create a box
            box b(point(item.x - 0.1, item.y - 0.1), point(item.x + 0.1, item.y + 0.1));
            // insert new value
            _rtree.insert(std::make_pair(b, item));
        }
        for ( auto& item : storage._left._potential_vertices )
        {
            // create a box
            box b(point(item.x - 0.1, item.y - 0.1), point(item.x + 0.1, item.y + 0.1));
            // insert new value
            _rtree.insert(std::make_pair(b, item));
        }
        for ( auto& item : storage._right._potential_vertices )
        {
            // create a box
            box b(point(item.x - 0.1, item.y - 0.1), point(item.x + 0.1, item.y + 0.1));
            // insert new value
            _rtree.insert(std::make_pair(b, item));
        }
    }

    std::optional<Vector2> SelectionProcessor::GetObject(Vector2 p1, Vector2 p2) {

        std::vector<value<Vector2> > result;
        double min_x = std::min(p1.x, p2.x);
        double max_x = std::max(p1.x, p2.x);
        double min_y = std::min(p1.y, p2.y);
        double max_y = std::max(p1.y, p2.y);

        box query_box(point(min_x, min_y), point(max_x, max_y));
//        _rtree.query(bgi::nearest(point(p1.x, p1.y), 1), std::back_inserter(result_n));
//        auto b = value<Vector2>(box(point(min_x, min_y), point(max_x, max_y)), Vector2());
        _rtree.query(bgi::intersects(query_box), std::back_inserter(result));

        if(result.empty()) return {};
        return result.front().second;
    }
}