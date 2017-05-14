#ifndef CPOINT_H
#define CPOINT_H

#include "cvector.h"

class CPoint
{
public:
    CPoint();
    CPoint(double X, double Y, double Z);
    CPoint(const CVector <double> &vect);

    void SetX(double value);
    void SetY(double value);
    void SetZ(double value);

    double GetX();
    double GetY();
    double GetZ();

    CVector<double> GetVector(unsigned int dimension);

private:

    double x;
    double y;
    double z;
};

#endif // CPOINT_H
