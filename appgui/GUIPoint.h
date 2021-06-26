#pragma once

#include <QGraphicsItem>
#include <QPen>
#include <QBrush>


namespace appgui{
    class OctagonGraphicsItem : public QGraphicsItem {
    private:
        QPen _pen;
        QBrush _brush;
        bool _filled = false;
        std::list<QPoint> _points;

    public:
        explicit OctagonGraphicsItem(const std::list<QPoint>& points, QGraphicsItem* parent = nullptr, const QColor &color = Qt::darkBlue);

        [[nodiscard]] QRectF boundingRect() const override;

        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

        void setColor(const QColor& color);
        void setWidth(int width);
        void setFilled(bool filled);
    };
}