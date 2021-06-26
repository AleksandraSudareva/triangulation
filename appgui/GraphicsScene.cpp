#include "GraphicsScene.h"

#include "../Session.h"

namespace appgui
{

    GraphicsScene::GraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject* parent) :
            QGraphicsScene(x, y, width, height, parent)
    {
        setBackgroundBrush(Qt::black);
    }

    OctagonGraphicsItem* GraphicsScene::addOctagon(Points points)
    {
        auto* item = new OctagonGraphicsItem(points);
        addItem(item);
        return item;
    }

    TraceGraphicsItem* GraphicsScene::addTrace(Points points, int32_t semiWidth)
    {
        auto* item = new TraceGraphicsItem(points, semiWidth);
        addItem(item);
        return item;
    }


    void GraphicsScene::ClearScene()
    {
        this->clear();
        _selectedGraphicsItems.clear();
        _individualSelection.clear();

    }

    OctagonGraphicsItem *GraphicsScene::addSelectionOctagon(const std::list<QPoint> &points) {
        auto* item = addOctagon(points);
        _selectedGraphicsItems.emplace_back(item);
        return item;
    }

    void GraphicsScene::ClearSelection() {
        for (auto* item : _selectedGraphicsItems)
        {
            if (item->scene() != nullptr)
            {
                removeItem(item);
                delete item;
            }
        }

        _selectedGraphicsItems.clear();
    }

    OctagonGraphicsItem* GraphicsScene::addIndividualSelectionOctagon(Points points)
    {
        auto* item = addOctagon(points);
        _individualSelection.push_back(item);
        return item;
    }

    void GraphicsScene::ClearIndividualSelection()
    {
        for (auto* item : _individualSelection)
        {
            if (item->scene() != nullptr)
            {
                removeItem(item);
                delete item;
            }
        }

        _individualSelection.clear();
    }
}
