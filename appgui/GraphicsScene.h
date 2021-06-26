#pragma once

#include <QGraphicsScene>

#include "GUIPoint.h"
#include "GUITrace.h"

namespace appgui {

    class GraphicsScene : public QGraphicsScene {

    protected:
        using Points = const std::list<QPoint>&;

    public:
        GraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject* parent = nullptr);

        OctagonGraphicsItem* addOctagon(Points points);
        TraceGraphicsItem* addTrace(Points points, int32_t semiWidth);

        OctagonGraphicsItem* addSelectionOctagon(Points points);
        OctagonGraphicsItem* addIndividualSelectionOctagon(Points points);

        virtual void ClearSelection();
        virtual void ClearIndividualSelection();
        virtual void ClearScene();

    private:
        std::vector<QGraphicsItem*> _selectedGraphicsItems;
        std::vector<QGraphicsItem*> _individualSelection;

    };
}