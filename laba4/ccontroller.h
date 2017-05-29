#ifndef CCONTROLLER_H
#define CCONTROLLER_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include "cbutton.h"
#include "times.h"

class CController : public QWidget
{
    Q_OBJECT
    enum StateController {
        NO_TARGET,
        BUSY
    };

public:

    explicit CController(QWidget *parent = 0) : QWidget(parent)
    {
        layout = new QVBoxLayout;
        this->setFixedSize(200, 300);
        this->setLayout(layout);
        for(int i = 0; i < FLOOR_NUMBERS; i++) {
            buttons[i] = new CButton;
            layout->addWidget(dynamic_cast<QPushButton*>(buttons[i]));
            buttons[i]->SetNumberFloor(i);
            buttons[i]->setText(QString::number(i));
            targetArray[i] = false;
            QObject::connect(buttons[i], SIGNAL(floorRequest(int)), this, SLOT(slotAddNewFloor(int)));
        }

    }
    ~CController()
    {
        for(int i = 0; i < FLOOR_NUMBERS; i++) {
            delete buttons[i];
        }
        delete layout;
    }

signals:

    void SendTarget(int floor);

public slots:

    void slotChangeCurrentFloor(int floor, Direction d) 
    {
        currentFloor = floor;
        direct = d;
    }

    void slotAchieveFloor(int floor, Direction d)
    {
        if(state == BUSY) {
            currentFloor = floor;
            direct = d;
            targetArray[floor] = false;
            if(GetNewTarget(floor)) {
                emit SendTarget(floor);
            }
            else {
                state = NO_TARGET;
            }
        }
    }
    
private slots:

    void slotAddNewFloor(int floor)
    {
        state = BUSY;
        targetArray[floor] = true;
        GetNewTarget(floor);
        emit SendTarget(floor);
    }

private:
    bool GetNewTarget(int &newFloor)
    {
        int step = direct == 0 ? -1 : direct;
        for(int i = currentFloor; i < FLOOR_NUMBERS && i >= 0; i += step) {
            if(targetArray[i])  {
                newFloor = i;
                return true;
            }
        }
        step *= -1;
        for(int i = currentFloor; i < FLOOR_NUMBERS && i >= 0; i += step) {
            if(targetArray[i])  {
                newFloor = i;
                return true;
            }
        }
        return false;
    }

    bool         targetArray[FLOOR_NUMBERS];
    CButton*     buttons[FLOOR_NUMBERS];
    int          currentFloor;
    Direction    direct;
    QVBoxLayout* layout;
    StateController state;

};

#endif // CCONTROLLER_H
