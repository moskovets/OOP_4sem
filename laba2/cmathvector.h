#ifndef CMATHVECTOR_H
#define CMATHVECTOR_H
#include "cbasevector.h"

template <typename T>
class CMathVector : public CBaseVector
{
public:

    CMathVector(size_t n);

    CMathVector(size_t n, const T* array);

    CMathVector(const CMathVector<T> &obj);

    CMathVector(CMathVector<T> &&obj);

    ~CMathVector();

private:

    T* arr = nullptr;
};

#endif // CMATHVECTOR_H
