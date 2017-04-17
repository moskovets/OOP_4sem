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

template <typename T>
T CMathVector<T>::GetAbsoluteValue() const
{
    T res = 0;
    for(int i = 0; i < obj.size(); i++) {
        res += arr[i] * arr[i];
    }
    return res;
}

template <typename T>
T CMathVector<T>::GetElement(unsigned int index) const
{
    if(index >= this->size())
        throw CRangeError();

    return arr[index];
}
template <typename T>
T& CMathVector<T>::GetElement(unsigned int index)
{
    if(index >= this->size())
        throw CRangeError();

    return arr[index];
}
template <typename T>
void CMathVector<T>::SetElement(unsigned int index, const T &value)
{
    if(index >= this->size())
        throw CRangeError();

    arr[index] = value;
}

template <typename T>
T CMathVector<T>::operator*(const CMathVector<T> &obj)
{
    if(obj.size() != this->size())
        throw CSizeError();
    T res = 0;
    for(int i = 0; i < obj.size(); i++) {
        res += arr[i] * obj.arr[i];
    }
    return res;
}

template <typename U>
bool operator==(const CMathVector<U> &a, const CMathVector<U> &b)
{
    if(a.size() != b.size())
        throw CSizeError();
    return a.GetAbsoluteValue() == b.GetAbsoluteValue();
}

template <typename T>
CMathVector<T> &CMathVector<T>::operator[](unsigned int index)
{
    if(index >= this->size())
        throw CRangeError();

    return arr[index];
}

template <typename T>
CMathVector<T> CMathVector<T>::operator[](unsigned int index) const
{
    if(index >= this->size())
        throw CRangeError();

    return arr[index];
}

template <typename T>
CMathVector<T> &CMathVector<T>::operator-() const
{
    CMathVector<T> res(this->size());
    for(int i = 0; i < n; i++) {
        res.arr[i] = -arr[i];
    }
    return res;
}

template <typename T>
CMathVector<T> &CMathVector<T>::operator =(const CMathVector<T> &obj)
{
    if(obj.size() != this->size())
        throw CSizeError();
    memcpy(arr, obj.arr, obj.size() * sizeof(T));
    return *this;
}

template <typename T>
CMathVector<T> &CMathVector<T>::operator +=(const CMathVector<T> &obj)
{
    if(obj.size() != this->size())
        throw CSizeError();

    for(int i = 0; i < obj.size(); i++) {
        arr[i] += obj.arr[i];
    }
    return *this;
}

template <typename T>
CMathVector<T> &CMathVector<T>::operator -=(const CMathVector<T> &obj)
{
    if(obj.size() != this->size())
        throw CSizeError();

    for(int i = 0; i < obj.size(); i++) {
        arr[i] -= obj.arr[i];
    }
    return *this;
}

template <typename U>
CMathVector<U> operator+(const CMathVector<U> &a, const CMathVector<U> &b)
{
    if(b.size() != a.size())
        throw CSizeError();

    CMathVector<U> res(b.size());

    for(int i = 0; i < b.size(); i++) {
        res = a.arr[i] + b.arr[i];
    }
    return res;
}

template <typename U>
CMathVector<U> operator+(const CMathVector<U> &a, U &value)
{
    CMathVector<U> res(a.size());

    for(int i = 0; i < a.size(); i++) {
        res = a.arr[i] + value;
    }
    return res;
}

template <typename U>
friend std::ostream& operator <<(std::ostream& os, const CMathVector<U> &obj)
{
    os << "[";
    for(int i = 0; i < obj.size(); i++) {
        os << obj.arr[i] << ", ";
    }
    os << "]\n";
}



#endif // CMATHVECTOR_IMP_H
