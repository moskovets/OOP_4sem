#ifndef CMATHVECTOR_IMP_H
#define CMATHVECTOR_IMP_H
#include "cmathvector.h"

template <typename T>
CMathVector<T>::CMathVector(size_t n) : CBaseVector(n)
{
    arr = new T[n]; //нулями нужно забивать?
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
CMathVector<T>::CMathVector(const CMathVector<T> &obj) : CBaseVector(obj.Size())
{
    arr = new T[obj.Size()];
    if(!arr)
        throw CMemoryError();
    memcpy(arr, obj.arr, obj.Size() * sizeof(T));
}

template <typename T>
CMathVector<T>::CMathVector(CMathVector<T> &&obj) : CBaseVector(obj.Size())
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
    for(int i = 0; i < this->Size(); i++) {
        res += arr[i] * arr[i];
    }
    return res;
}

template <typename T>
T CMathVector<T>::GetElement(unsigned int index) const
{
    if(index >= this->Size())
        throw CRangeError();

    return arr[index];
}
template <typename T>
T& CMathVector<T>::GetElement(unsigned int index)
{
    if(index >= this->Size())
        throw CRangeError();

    return arr[index];
}
template <typename T>
void CMathVector<T>::SetElement(unsigned int index, const T &value)
{
    if(index >= this->Size())
        throw CRangeError();

    arr[index] = value;
}

template <typename T>
T CMathVector<T>::operator*(const CMathVector<T> &obj)
{
    if(obj.Size() != this->Size())
        throw CSizeError();
    T res = 0;
    for(int i = 0; i < obj.Size(); i++) {
        res += arr[i] * obj.arr[i];
    }
    return res;
}

template <typename U>
bool operator==(const CMathVector<U> &a, const CMathVector<U> &b)
{
    if(a.Size() != b.Size())
        throw CSizeError();
    return a.GetAbsoluteValue() == b.GetAbsoluteValue();
}
template <typename U>
bool operator<(const CMathVector<U> &a, const CMathVector<U> &b)
{
    if(a.Size() != b.Size())
        throw CSizeError();
    return a.GetAbsoluteValue() < b.GetAbsoluteValue();
}
template <typename T>
T &CMathVector<T>::operator[](unsigned int index)
{
    if(index >= this->Size())
        throw CRangeError();

    return arr[index];
}

template <typename T>
T CMathVector<T>::operator[](unsigned int index) const
{
    if(index >= this->Size())
        throw CRangeError();

    return arr[index];
}

template <typename T>
T &CMathVector<T>::operator()(unsigned int index)
{
    if(index >= this->Size())
        throw CRangeError();

    return arr[index];
}

template <typename T>
T CMathVector<T>::operator()(unsigned int index) const
{
    if(index >= this->Size())
        throw CRangeError();

    return arr[index];
}

template <typename U>
CMathVector<U> operator-(const CMathVector<U> &a)
{
    CMathVector<U> res(a.Size());
    for(int i = 0; i < a.Size(); i++) {
        res.arr[i] = -a.arr[i];
    }
    return res;
}

template <typename T>
CMathVector<T> &CMathVector<T>::operator =(const CMathVector<T> &obj)
{
    //(*this) = CMathVector(obj);
    //return *this;

    if(obj.Size() != this->Size())
        throw CSizeError();
    memcpy(arr, obj.arr, obj.Size() * sizeof(T));
    return *this;
}

template <typename T>
CMathVector<T> &CMathVector<T>::operator +=(const CMathVector<T> &obj)
{
    if(obj.Size() != this->Size())
        throw CSizeError();

    for(int i = 0; i < obj.Size(); i++) {
        arr[i] += obj.arr[i];
    }
    return *this;
}

template <typename T>
CMathVector<T> &CMathVector<T>::operator -=(const CMathVector<T> &obj)
{
    if(obj.Size() != this->Size())
        throw CSizeError();

    for(int i = 0; i < obj.Size(); i++) {
        arr[i] -= obj.arr[i];
    }
    return *this;
}

template <typename U>
CMathVector<U> operator+(const CMathVector<U> &a, const CMathVector<U> &b)
{
    if(b.Size() != a.Size())
        throw CSizeError();

    CMathVector<U> res(b.Size());

    for(int i = 0; i < b.Size(); i++) {
        res.arr[i] = a.arr[i] + b.arr[i];
    }
    return res;
}
template <typename U>
CMathVector<U> operator-(const CMathVector<U> &a, const CMathVector<U> &b)
{
    if(b.Size() != a.Size())
        throw CSizeError();

    CMathVector<U> res(b.Size());

    for(int i = 0; i < b.Size(); i++) {
        res.arr[i] = a.arr[i] - b.arr[i];
    }
    return res;
}
template <typename U>
CMathVector<U> operator+(const CMathVector<U> &a, U &value)
{
    CMathVector<U> res(a.Size());

    for(int i = 0; i < a.Size(); i++) {
        res.arr[i] = a.arr[i] + value;
    }
    return res;
}
template <typename U>
CMathVector<U> operator-(const CMathVector<U> &a, U &value)
{
    CMathVector<U> res(a.Size());

    for(int i = 0; i < a.Size(); i++) {
        res.arr[i] = a.arr[i] - value;
    }
    return res;
}
template <typename U>
CMathVector<U> operator*(const CMathVector<U> &a, U &value)
{
    CMathVector<U> res(a.Size());

    for(int i = 0; i < a.Size(); i++) {
        res.arr[i] = a.arr[i] * value;
    }
    return res;
}
template <typename U>
CMathVector<U> operator/(const CMathVector<U> &a, U &value)
{
    CMathVector<U> res(a.Size());

    for(int i = 0; i < a.Size(); i++) {
        res.arr[i] = a.arr[i] / value;
    }
    return res;
}


template <typename U>
std::ostream& operator <<(std::ostream& os, const CMathVector<U> &obj)
{
    os << "[ ";
    for(int i = 0; i < obj.Size(); i++) {
        os << obj.arr[i] << " ";
    }
    os << "]" << std::endl;
}



#endif // CMATHVECTOR_IMP_H
