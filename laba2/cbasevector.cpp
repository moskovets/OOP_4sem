#include "cbasevector.h"


CBaseVector::CBaseVector() : length(0) {}

CBaseVector::CBaseVector(size_t len) : length(len) {}

CBaseVector::~CBaseVector()
{
    length = 0;
}

size_t CBaseVector::size() const
{
    return length;
}

bool CBaseVector::empty() const
{
    return length;
}
