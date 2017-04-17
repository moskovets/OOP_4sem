#include "basevector.h"


BaseVector::BaseVector() : length(0) {}

BaseVector::BaseVector(size_t len) : length(len) {}

BaseVector::~BaseVector()
{
    length = 0;
}

size_t BaseVector::size() const
{
    return length;
}

bool BaseVector::empty() const
{
    return length;
}
