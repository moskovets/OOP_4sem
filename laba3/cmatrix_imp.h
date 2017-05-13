#ifndef CMATRIX_IMP_H
#define CMATRIX_IMP_H

#include "cmatrix.h"

template <typename T>
CMatrix<T>::CMatrix(std::size_t n, std::size_t m) : CBaseVector(n * m)
{
    try {
        arr = new T[n * m];
    }
    catch (std::bad_alloc) {
        throw CMemoryError();
    }
    for(int i = 0; i < n * m; i++) {
        arr[i] = 0;
    }
    this->n = n;
    this->m = m;
}

template <typename T>
CMatrix<T>::CMatrix(std::size_t n, std::size_t m, const T* array) : CBaseVector(n * m)
{
    try {
        arr = new T[n * m];
    }
    catch (std::bad_alloc) {
        throw CMemoryError();
    }
    this->n = n;
    this->m = m;
    memcpy(arr, array, n * m * sizeof(T));
}

template <typename T>
CMatrix<T>::CMatrix(const CMatrix<T>& obj) : CBaseVector(obj.Size())
{
    try {
        arr = new T[obj.Size()];
    }
    catch (std::bad_alloc) {
        throw CMemoryError();
    }
    this->n = obj.n;
    this->m = obj.m;
    memcpy(arr, obj.arr, obj.Size() * sizeof(T));
}

template <typename T>
CMatrix<T>::CMatrix(CMatrix<T>&& obj) : CBaseVector(obj.Size())
{
    arr = obj.arr;
    this->length = obj.length;
    this->n = obj.n;
    this->m = obj.m;


    obj.arr = nullptr;
    obj.length = 0;
    obj.n = 0;
    obj.m = 0;
}

template <typename T>
CMatrix<T>::~CMatrix()
{
    delete[] arr;
    arr = nullptr;
}

template <typename T>
T CMatrix<T>::GetElement(unsigned int i, unsigned int j) const
{
    if(index >= this->Size())
        throw CRangeError();

    return arr[index];
}

template <typename T>
T& CMatrix<T>::GetElement(unsigned int i, unsigned int j)
{
    if(index >= this->Size())
        throw CRangeError();

    return arr[index];
}

template <typename T>
void CMatrix<T>::SetElement(unsigned int i, unsigned int j, const T& value)
{
    if(index >= this->Size())
        throw CRangeError();

    arr[index] = value;
}

template <typename T>
typename CMatrix<T>::CRow CMatrix<T>::operator[](unsigned int index)
{
    if(index >= n)
        throw CRangeError();

    return CRow(arr + index*m, m);
}

template <typename T>
typename CMatrix<T>::CRow CMatrix<T>::operator[](unsigned int index) const
{
    if(index >= n)
        throw CRangeError();

    return CRow(arr + index*m, m);
}

template <typename T>
T& CMatrix<T>::operator()(unsigned int i, unsigned int j)
{
    if(index >= this->Size())
        throw CRangeError();

    return arr[index];
}

template <typename T>
T CMatrix<T>::operator()(unsigned int i, unsigned int j) const
{
    if(index >= this->Size())
        throw CRangeError();

    return arr[index];
}

template <typename T>
CMatrix<T>& CMatrix<T>::operator =(const CMatrix<T>& obj)
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
    this->n = obj.n;
    this->m = obj.m;
    return *this;
}

template <typename T>
CMatrix<T>& CMatrix<T>::operator =(CMatrix<T>&& obj)
{
    if(this != &obj) {
        delete[] arr;

        arr = obj.arr;
        this->length = obj.length;
        this->n = obj.n;
        this->m = obj.m;

        obj.arr = nullptr;
        obj.length = 0;
        obj.n = 0;
        obj.m = 0;
    }
    return *this;
}
#endif // CMATRIX_IMP_H
