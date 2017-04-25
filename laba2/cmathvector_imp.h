#ifndef CMATHVECTOR_IMP_H
#define CMATHVECTOR_IMP_H
#include "cmathvector.h"

namespace myVector
{
    template <typename T>
    CMathVector<T>::CMathVector(std::size_t n) : vectorBase::CBaseVector(n)
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
    CMathVector<T>::CMathVector(std::size_t n, const T* array) : vectorBase::CBaseVector(n)
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
    CMathVector<T>::CMathVector(const std::initializer_list<T>& list) : vectorBase::CBaseVector(list.size())
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
    CMathVector<T>::CMathVector(const CMathVector<T>& obj) : vectorBase::CBaseVector(obj.Size())
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
    CMathVector<T>::CMathVector(CMathVector<T>&& obj) : vectorBase::CBaseVector(obj.Size())
    {
        arr = obj.arr;
        this->length = obj.length;

        obj.arr = nullptr;
        obj.length = 0;
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
    void CMathVector<T>::SetElement(unsigned int index, const T& value)
    {
        if(index >= this->Size())
            throw CRangeError();

        arr[index] = value;
    }

    template <typename T>
    T CMathVector<T>::operator*(const CMathVector<T>& obj)
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
    bool operator==(const CMathVector<U>& a, const CMathVector<U>& b)
    {
        if(a.Size() != b.Size())
            throw CSizeError();

        return a.GetAbsoluteValue() == b.GetAbsoluteValue();
    }

    template <typename U>
    bool operator<(const CMathVector<U>& a, const CMathVector<U>& b)
    {
        if(a.Size() != b.Size())
            throw CSizeError();

        return a.GetAbsoluteValue() < b.GetAbsoluteValue();
    }

    template <typename U>
    bool operator>(const CMathVector<U>& a, const CMathVector<U>& b)
    {
        if(a.Size() != b.Size())
            throw CSizeError();

        return a.GetAbsoluteValue() > b.GetAbsoluteValue();
    }

    template <typename U>
    bool operator>=(const CMathVector<U>& a, const CMathVector<U>& b)
    {
        return !(a < b);
    }

    template <typename U>
    bool operator<=(const CMathVector<U>& a, const CMathVector<U>& b)
    {
        return !(a > b);
    }

    template <typename T>
    T& CMathVector<T>::operator[](unsigned int index)
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
    T& CMathVector<T>::operator()(unsigned int index)
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

    template <typename T>
    CMathVector<T> CMathVector<T>::operator -() const
    {
        CMathVector<T> res(this->Size());
        for(int i = 0; i < this->Size(); i++) {
            res.arr[i] = -arr[i];
        }
        return res;
    }

    template <typename T>
    CMathVector<T> CMathVector<T>::operator +() const
    {
        CMathVector<T> res(*this);
        return res;
    }

    template <typename T>
    CMathVector<T>& CMathVector<T>::operator =(const CMathVector<T>& obj)
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
    CMathVector<T>& CMathVector<T>::operator =(CMathVector<T>&& obj)
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

    template <typename T>
    CMathVector<T>& CMathVector<T>::operator +=(const CMathVector<T>& obj)
    {
        if(obj.Size() != this->Size())
            throw CSizeError();

        for(int i = 0; i < obj.Size(); i++) {
            arr[i] += obj.arr[i];
        }
        return *this;
    }

    template <typename T>
    CMathVector<T>& CMathVector<T>::operator -=(const CMathVector<T>& obj)
    {
        if(obj.Size() != this->Size())
            throw CSizeError();

        for(int i = 0; i < obj.Size(); i++) {
            arr[i] -= obj.arr[i];
        }
        return *this;
    }

    template <typename U>
    CMathVector<U> operator+(const CMathVector<U>& a, const CMathVector<U>& b)
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
    CMathVector<U> operator-(const CMathVector<U>& a, const CMathVector<U>& b)
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
    CMathVector<U> operator+(const CMathVector<U>& a, U& value)
    {
        CMathVector<U> res(a.Size());

        for(int i = 0; i < a.Size(); i++) {
            res.arr[i] = a.arr[i] + value;
        }
        return res;
    }

    template <typename U>
    CMathVector<U> operator-(const CMathVector<U>& a, U& value)
    {
        CMathVector<U> res(a.Size());

        for(int i = 0; i < a.Size(); i++) {
            res.arr[i] = a.arr[i] - value;
        }
        return res;
    }

    template <typename U>
    CMathVector<U> operator*(const CMathVector<U>& a, U& value)
    {
        CMathVector<U> res(a.Size());

        for(int i = 0; i < a.Size(); i++) {
            res.arr[i] = a.arr[i] * value;
        }
        return res;
    }

    template <typename U>
    CMathVector<U> operator/(const CMathVector<U>& a, U& value)
    {
        CMathVector<U> res(a.Size());

        for(int i = 0; i < a.Size(); i++) {
            res.arr[i] = a.arr[i] / value;
        }
        return res;
    }


    template <typename U>
    std::ostream& operator <<(std::ostream& os, const CMathVector<U>& obj)
    {
        os << "[ ";
        for(int i = 0; i < obj.Size(); i++) {
            os << obj.arr[i] << " ";
        }
        os << "]" << std::endl;
        return os;
    }

    template <typename T>
    CVectorIterator<T> CMathVector<T>::begin()
    {
        CVectorIterator<T> it(arr);
        return it;
    }

    template <typename T>
    CVectorIterator<T> CMathVector<T>::end()
    {
        return CVectorIterator<T>(arr + this->Size());
    }

    template <typename T>
    CConstVectorIterator<T> CMathVector<T>::begin() const
    {
        return CConstVectorIterator<T>(arr);
    }

    template <typename T>
    CConstVectorIterator<T> CMathVector<T>::end() const
    {
        return CConstVectorIterator<T>(arr + this->Size());
    }
}
#endif // CMATHVECTOR_IMP_H
