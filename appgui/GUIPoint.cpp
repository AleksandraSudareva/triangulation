#include "GUIPoint.h"

#include <QPainter>
#include <QPainterPath>

namespace appgui {

    OctagonGraphicsItem::OctagonGraphicsItem(const std::list<QPoint>& points, QGraphicsItem *parent, const QColor &color) : QGraphicsItem(parent)
    {
        _pen.setCosmetic(true);
        _pen.setWidth(2);
        _pen.setColor(color);
        _brush = QBrush(color);
        _points = points;
    }

    void OctagonGraphicsItem::setColor(const QColor& color)
    {
        _pen.setColor(color);
        _brush.setColor(color);
    }

    void OctagonGraphicsItem::setWidth(int width)
    {
        _pen.setWidth(width);
    }

    void OctagonGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
    {
        QPainterPath path;
        bool start = true;

        for (auto& point : _points)
        {
            if (start)
            {
                path.moveTo(point);
                start = false;
                continue;
            }

            path.lineTo(point);
        }

        path.closeSubpath();

        painter->setPen(_pen);
        if (_filled) {
            painter->fillPath(path, _brush);
        }
        painter->drawPath(path);
    }

    QRectF OctagonGraphicsItem::boundingRect() const {
        auto minX = _points.back().x();
        auto minY = _points.back().y();

        auto maxX = _points.back().x();
        auto maxY = _points.back().y();

        for (auto &point : _points) {
            if (point.x() > maxX)
                maxX = point.x();
            if (point.y() > maxY)
                maxY = point.y();

            if (point.x() < minX)
                minX = point.x();
            if (point.y() < minY)
                minY = point.y();
        }

        return QRectF(minX, minY, maxX - minX, maxY - minY);
    }

    void OctagonGraphicsItem::setFilled(bool filled) {
        _filled = filled;
    }
}