#ifndef CVECTOR_IMP_H
#define CVECTOR_IMP_H
#include "cvector.h"

template <typename T>
CVector<T>::CVector(std::size_t n) : CBaseVector(n)
{
    try {
        arr = new T[n];
    }
    catch (std::bad_alloc) {
        throw CMemoryError();
    }
    for(int i = 0; i < n; i++) {
        arr[i] = 0;
    }
}

template <typename T>
CVector<T>::CVector(std::size_t n, const T* array) : CBaseVector(n)
{
    try {
        arr = new T[n];
    }
    catch (std::bad_alloc) {
        throw CMemoryError();
    }
    memcpy(arr, array, n * sizeof(T));
}

template <typename T>
CVector<T>::CVector(const std::initializer_list<T>& list) : CBaseVector(list.size())
{
    try {
        arr = new T[list.size()];
    }
    catch (std::bad_alloc) {
        throw CMemoryError();
    }
    std::copy(list.begin(), list.end(), arr);
}

template <typename T>
CVector<T>::CVector(const CVector<T>& obj) : CBaseVector(obj.Size())
{
    try {
        arr = new T[obj.Size()];
    }
    catch (std::bad_alloc) {
        throw CMemoryError();
    }
    memcpy(arr, obj.arr, obj.Size() * sizeof(T));
}

template <typename T>
CVector<T>::CVector(CVector<T>&& obj) : CBaseVector(obj.Size())
{
    arr = obj.arr;
    this->length = obj.length;

    obj.arr = nullptr;
    obj.length = 0;
}

template <typename T>
CVector<T>::~CVector()
{
    delete[] arr;
    arr = nullptr;
}

template <typename T>
T CVector<T>::GetElement(unsigned int index) const
{
    if(index >= this->Size())
        throw CRangeError();

    return arr[index];
}

template <typename T>
T& CVector<T>::GetElement(unsigned int index)
{
    if(index >= this->Size())
        throw CRangeError();

    return arr[index];
}

template <typename T>
void CVector<T>::SetElement(unsigned int index, const T& value)
{
    if(index >= this->Size())
        throw CRangeError();

    arr[index] = value;
}

template <typename T>
T& CVector<T>::operator[](unsigned int index)
{
    if(index >= this->Size())
        throw CRangeError();

    return arr[index];
}

template <typename T>
T CVector<T>::operator[](unsigned int index) const
{
    if(index >= this->Size())
        throw CRangeError();

    return arr[index];
}

template <typename T>
T& CVector<T>::operator()(unsigned int index)
{
    if(index >= this->Size())
        throw CRangeError();

    return arr[index];
}

template <typename T>
T CVector<T>::operator()(unsigned int index) const
{
    if(index >= this->Size())
        throw CRangeError();

    return arr[index];
}

template <typename T>
CVector<T>& CVector<T>::operator =(const CVector<T>& obj)
{
    T* new_arr = nullptr;
    try {
        new_arr = new T[obj.Size()];
    }
    catch (std::bad_alloc) {
        throw CMemoryError();
    }
    memcpy(new_arr, obj.arr, obj.Size() * sizeof(T));

    delete[] arr;
    arr = new_arr;
    this->length = obj.Size();
    return *this;
}

template <typename T>
CVector<T>& CVector<T>::operator =(CVector<T>&& obj)
{
    if(this != &obj) {
        delete[] arr;

        arr = obj.arr;
        this->length = obj.length;

        obj.arr = nullptr;
        obj.length = 0;
    }
    return *this;
}

#endif // CMATHVECTOR_IMP_H
