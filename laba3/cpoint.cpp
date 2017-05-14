#include "cpoint.h"

CPoint::CPoint()
{
    x = y = z = 0;
}

CPoint::CPoint(double X, double Y, double Z)
{
    x = X;
    y = Y;
    z = Z;
}

CPoint::CPoint(const CVector<double> &vect)
{
    x = y = z = 0;
    try {
        x = vect[0];
        y = vect[1];
        z = vect[2];
    }
    catch (CRangeError) {

    }
}

void CPoint::SetX(double value)
{
    x = value;
}

void CPoint::SetY(double value)
{
    y = value;
}

void CPoint::SetZ(double value)
{
    z = value;
}

double CPoint::GetX()
{
    return x;
}

double CPoint::GetY()
{
    return y;
}

double CPoint::GetZ()
{
    return z;
}

CVector<double> CPoint::GetVector(unsigned int dimension)
{
    CVector<double> vect(dimension);

    try {
        vect[0] = x;
        vect[1] = y;
        vect[2] = z;
    }
    catch (CRangeError) {

    }

    return vect;
}
