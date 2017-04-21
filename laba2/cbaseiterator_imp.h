#ifndef CBASEITERATOR_IMP_H
#define CBASEITERATOR_IMP_H

#include "cbaseiterator.h"

template <typename T>
CBaseIterator<T>::CBaseIterator(const CBaseIterator<T> &iter)
{
    ptr = iter.ptr;
}

template <typename T>
CBaseIterator<T>::~CBaseIterator()
{
    ptr = nullptr;
}

template <typename T>
CBaseIterator<T>& CBaseIterator<T>::operator=(const CBaseIterator<T> &iter)
{
    if(this != &iter)
        ptr = iter.ptr;
    return *this;
}

template <typename T>
CBaseIterator<T>& CBaseIterator<T>::operator++()
{
    ++ptr;
    return *this;
}

template <typename T>
CBaseIterator<T>& CBaseIterator<T>::operator++(int)
{
    CBaseIterator<T> tmp(*this);
    this->operator++();
    return tmp;
}

template <typename T>
CBaseIterator<T>& CBaseIterator<T>::operator--()
{
    --ptr;
    return *this;
}

template <typename T>
CBaseIterator<T>& CBaseIterator<T>::operator--(int)
{
    CBaseIterator<T> tmp(*this);
    this->operator--();
    return tmp;
}

template <typename T>
bool CBaseIterator<T>::operator==(const CBaseIterator &iter)
{
    return ptr == iter.ptr;
}

template <typename T>
bool CBaseIterator<T>::operator!=(const CBaseIterator &iter)
{
    return ptr != iter.ptr;
}

#endif // CBASEITERATOR_IMP_H
