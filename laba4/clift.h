#ifndef CLIFT_H
#define CLIFT_H

#include <QObject>
#include "times.h"
#include "ccontroller.h"
#include "ccabin.h"

class CLift : public QObject
{
    Q_OBJECT
public:
    explicit CLift(QObject *parent = 0) : QObject(parent)
    {
        QObject::connect(&cabina,  SIGNAL(FloorVisited(int, Direction)),
                         &control, SLOT(slotChangeCurrentFloor(int, Direction)));
        QObject::connect(&cabina,  SIGNAL(FloorTargetAchieved(int, Direction)),
                         &control, SLOT(slotAchieveFloor(int, Direction)));
        QObject::connect(&control, SIGNAL(SendTarget(int)),
                         &cabina,  SLOT(slotBusy(int)));
    }

    QWidget* GetWidget()
    {
        return &control;
    }

signals:

public slots:

private:
    CController control;
    CCabin      cabina;
};

#endif // CLIFT_H
