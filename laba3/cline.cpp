#include "cline.h"

CLine::CLine()
{

}

CLine::CLine(CPoint *p1, CPoint *p2)
{
    point1 = p1;
    point2 = p2;
}

void CLine::SetPoint1(CPoint *p1)
{
    point1 = p1;
}

void CLine::SetPoint2(CPoint *p2)
{
    point1 = p2;
}

CPoint *CLine::GetPoint1()
{
    return point1;
}

CPoint *CLine::GetPoint2()
{
    return point2;
}
