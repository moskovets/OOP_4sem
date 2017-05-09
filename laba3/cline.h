#ifndef CLINE_H
#define CLINE_H
#include "cpoint.h"

class CLine
{
public:

    CLine();
    CLine(CPoint *p1, CPoint *p2);

    void SetPoint1(CPoint *p1);
    void SetPoint2(CPoint *p1);

    CPoint* GetPoint1();
    CPoint* GetPoint2();

private:

    CPoint* point1 = nullptr;
    CPoint* point2 = nullptr;



};

#endif // CLINE_H
