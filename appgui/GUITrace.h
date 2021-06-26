#pragma once

#include <QGraphicsItem>
#include <QPen>

namespace appgui {
    class TraceGraphicsItem : public QGraphicsItem {
    private:
        QPen _pen;
        std::list<QPoint> _points;
        int32_t _semiWidth;

    public:
        TraceGraphicsItem(const std::list<QPoint>& points, int32_t semiWidth, QGraphicsItem* parent = nullptr);

        [[nodiscard]] QRectF boundingRect() const override;

        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
        void SetColor(const QColor& color);
    };
}
