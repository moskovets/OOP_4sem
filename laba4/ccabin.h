#ifndef CCABIN_H
#define CCABIN_H

#include <QObject>
#include "cdoor.h"
#include "times.h"

class CCabin : public QObject
{
    Q_OBJECT
    enum StateCabin {
        MOVING,
        BUSY,
        FREE
    };

public:
    explicit CCabin(QObject *parent = 0);


signals:

    void FloorVisited(int floor, Direction d); // union?
    void FloorTargetAchieved(int floor, Direction d); // union?
    void Move();

public slots:

    void slotMoving();
    void slotFree();
    void slotBusy(int floor);

private:

    int       currentFloor = 0;
    int       targetFloor;
    bool      flagTarget;
    Direction direct;
    StateCabin state;
    CDoor     door;
    QTimer    timerMoveFloor;

signals:

    void FloorAchieved();

};

#endif // CCABIN_H
