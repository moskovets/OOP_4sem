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
