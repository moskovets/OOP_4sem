#ifndef CDOOR_H
#define CDOOR_H

#include <QObject>
#include "times.h"

class CDoor : public QObject
{
    Q_OBJECT
    enum StateDoor {
        OPEN,
        CLOSE,
        OPENING,
        CLOSING
    };
public:
    explicit CDoor()
    {
        state = CLOSE;
        QObject::connect(this, SIGNAL(OpenDoor()), this, SLOT(slotOpening()));
        QObject::connect(&timerOpen,    SIGNAL(QTimer::timeout()), this, SLOT(CDoor::slotOpen()));
        QObject::connect(&timerClose,   SIGNAL(QTimer::timeout()), this, SLOT(CDoor::slotClose()));
        QObject::connect(&timerWaitOpen,SIGNAL(QTimer::timeout()), this, SLOT(CDoor::slotClosing()));
    }
signals:
    void DoorIsClosed();
    void OpenDoor();
public slots:

    void slotOpen()
    {
        if(state == OPENING) {
            state = OPEN;
            qDebug() << "doors opened";
            timerWaitOpen.start(TIME_DOOR_WAIT);
        }
    }

    void slotClose()
    {
        if(state == CLOSING) {
            state = CLOSE;
            qDebug() << "doors closed";
            emit DoorIsClosed();
        }
    }

private slots:

    void slotOpening()
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

    void slotClosing()
    {
        if(state == OPEN) {
            state = CLOSING;
            qDebug() << "doors are closing";
            timerClose.start(TIME_DOOR);
        }
    }

private:

    StateDoor state;
    QTimer timerOpen;
    QTimer timerClose;
    QTimer timerWaitOpen;
};

#endif // CDOOR_H
