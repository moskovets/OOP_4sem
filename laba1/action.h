#ifndef ACTION_H
#define ACTION_H

#define FILE_NAME_SIZE 200
enum ERRORS { OK, FILE_NOT_FIND, FILE_ERROR };

struct Rotate {
    double x_angle;
    double y_angle;
    double z_angle;
};
struct Scale {
    double kx;
    double ky;
    double kz;
};
struct Move {
    double dx;
    double dy;
    double dz;
};
struct Create {
    char fileName[FILE_NAME_SIZE];
};

#endif // ACTION_H
