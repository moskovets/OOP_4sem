#include "cdoor.h"


CDoor::CDoor()
{
    state = CLOSE;
    QObject::connect(this, SIGNAL(OpenDoor()), this, SLOT(slotOpening()));
    QObject::connect(&timerOpen,    SIGNAL(QTimer::timeout()), this, SLOT(CDoor::slotOpen()));
    QObject::connect(&timerClose,   SIGNAL(QTimer::timeout()), this, SLOT(CDoor::slotClose()));
    QObject::connect(&timerWaitOpen,SIGNAL(QTimer::timeout()), this, SLOT(CDoor::slotClosing()));
}

void CDoor::slotOpen()
{
    if(state == OPENING) {
        state = OPEN;
        qDebug() << "doors opened";
        timerWaitOpen.start(TIME_DOOR_WAIT);
    }
}

void CDoor::slotClose()
{
    if(state == CLOSING) {
        state = CLOSE;
        qDebug() << "doors closed";
        emit DoorIsClosed();
    }
}

void CDoor::slotOpening()
{
    if(state == CLOSE) {
        state = OPENING;
        qDebug() << "doors opening";
        timerOpen.start(TIME_DOOR);
    }
    if(state == CLOSING) {
        state = OPENING;
        qDebug() << "doors opening";
        int t = timerClose.remainingTime();
        timerClose.stop();
        timerOpen.start(TIME_DOOR - t);
    }
}

void CDoor::slotClosing()
{
    if(state == OPEN) {
        state = CLOSING;
        qDebug() << "doors are closing";
        timerClose.start(TIME_DOOR);
    }
}
