#ifndef CMATHVECTOR_IMP_H
#define CMATHVECTOR_IMP_H
#include "cmathvector.h"

template <typename T>
CMathVector<T>::CMathVector(size_t n) : CBaseVector(n)
{
    arr = new T[n];
    if(!arr)
        throw CMemoryError();
}

template <typename T>
CMathVector<T>::CMathVector(size_t n, const T* array) : CBaseVector(n)
{
    arr = new T[n];
    if(!arr)
        throw CMemoryError();
    memcpy(arr, array, n * sizeof(T));
}

template <typename T>
CMathVector<T>::CMathVector(const CMathVector<T> &obj) : CBaseVector(obj.size())
{
    arr = new T[obj.size()];
    if(!arr)
        throw CMemoryError();
    memcpy(arr, obj.arr, obj.size() * sizeof(T));
}

template <typename T>
CMathVector<T>::CMathVector(CMathVector<T> &&obj) : CBaseVector(obj.size())
{
    arr = obj.arr;
    obj.arr = 0;
}

template <typename T>
CMathVector<T>::~CMathVector()
{
    delete[] arr;
    arr = nullptr;
}

#endif // CMATHVECTOR_IMP_H
