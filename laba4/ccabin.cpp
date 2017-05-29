#include "ccabin.h"

CCabin::CCabin(QObject *parent)
{
    state = FREE;
    currentFloor = 0;
    targetFloor = 0;
    flagTarget = false;
    direct = NO_DIRECTION;
    QObject::connect(&door, SIGNAL(CDoor::DoorIsClosed()), this, SLOT(slotOpening()));
    QObject::connect(&timerMoveFloor, SIGNAL(QTimer::timeout()), this, SLOT(slotMoving()));
    QObject::connect(this, SIGNAL(FloorAchieved()), this, SLOT(slotFree()));
    QObject::connect(this, SIGNAL(Move()), this, SLOT(slotMoving()));
}

void CCabin::slotMoving()
{
    if(state == FREE || state == BUSY)  {
        if(currentFloor == targetFloor) {
            emit FloorAchieved();
        }
        else {
            emit FloorVisited(currentFloor, direct);
            if(currentFloor < targetFloor) {
                direct = UP;
                currentFloor += 1;
            }
            else {
                direct = DOWN;
                currentFloor -= 1;
            }
            timerMoveFloor.start(TIME_MOVING_FLOOR);
        }
    }

}

void CCabin::slotFree()
{
    flagTarget = false;
    state = FREE;
    emit FloorTargetAchieved(currentFloor, direct);
    emit door.OpenDoor();
}

void CCabin::slotBusy(int floor)
{
    state = BUSY;
    flagTarget = true;
    targetFloor = floor;
    if(currentFloor == targetFloor) {
        emit FloorAchieved();
    }
    else {
        if(currentFloor < targetFloor) {
            direct = UP;
        }
        else {
            direct = DOWN;
        }
        emit Move();
    }
}
