#ifndef CPOINT_H
#define CPOINT_H


class CPoint
{
public:
    CPoint();
    CPoint(double X, double Y, double Z);

    void SetX(double value);
    void SetY(double value);
    void SetZ(double value);

    double GetX();
    double GetY();
    double GetZ();

private:

    double x;
    double y;
    double z;
};

#endif // CPOINT_H
