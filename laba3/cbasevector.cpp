#include "cbasevector.h"

CBaseVector::CBaseVector() : length(0) {}

CBaseVector::CBaseVector(std::size_t len) : length(len) {}

CBaseVector::~CBaseVector()
{
    length = 0;
}

size_t CBaseVector::Size() const
{
    return length;
}

bool CBaseVector::Empty() const
{
    return length;
}
