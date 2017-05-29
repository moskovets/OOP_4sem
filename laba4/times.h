#ifndef TIMES_H
#define TIMES_H

#include <QTimer>
#include <QDebug>

#define TIME_DOOR 100
#define TIME_DOOR_WAIT 10
#define TIME_MOVING_FLOOR 20
#define FLOOR_NUMBERS 5

enum Direction {
    UP = 1,
    DOWN = -1,
    NO_DIRECTION = 0
};

#endif // TIMES_H
