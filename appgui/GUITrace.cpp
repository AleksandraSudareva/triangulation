#include "GUITrace.h"

#include <QPainter>
#include <QPainterPath>


namespace appgui {

    TraceGraphicsItem::TraceGraphicsItem(const std::list<QPoint>& points, int32_t semiWidth, QGraphicsItem *parent) :
            _semiWidth(semiWidth),
            QGraphicsItem(parent)
    {
        _points = points;

        if (semiWidth == 0) {
            _pen.setCosmetic(true);
            _pen.setWidthF(2);
        } else {
            _pen.setCapStyle(Qt::RoundCap);
            _pen.setJoinStyle(Qt::RoundJoin);
            _pen.setWidthF(2 * _semiWidth);
        }
    }

    QRectF TraceGraphicsItem::boundingRect() const {
        auto p = _points.front();
        auto minX = p.x();
        auto minY = p.y();
        auto maxX = p.x();
        auto maxY = p.y();

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

        return QRectF(minX - _semiWidth, minY - _semiWidth,
                      maxX - minX + (_semiWidth * 2), maxY - minY + (_semiWidth * 2));
    }

    void TraceGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

        auto p = _points.front();
        QPainterPath path({static_cast<double>(p.x()), static_cast<double>(p.y())});
        for (auto &point : _points) {
            path.lineTo({static_cast<double>(point.x()), static_cast<double>(point.y())});
        }

        painter->setPen(_pen);
        painter->drawPath(path);
    }

    void TraceGraphicsItem::SetColor(const QColor &color) {
        _pen.setColor(color);
    }
}