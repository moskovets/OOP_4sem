#ifndef CVECTORITERATOR_IMP_H
#define CVECTORITERATOR_IMP_H

#include "cvectoriterator.h"

template <typename T>
CVectorIterator<T>::CVectorIterator(const CVectorIterator<T> &iter)
{
    this->ptr = iter.ptr;
}

template <typename T>
CVectorIterator<T>::CVectorIterator(T *p)
{
    this->ptr = p;
}

template <typename T>
T& CVectorIterator<T>::operator*()
{
    return *(this->ptr);
}

template <typename T>
const T CVectorIterator<T>::operator*() const
{
    return *(this->ptr);
}

template <typename T>
T& CVectorIterator<T>::operator->()
{
    return this->ptr;
}

template <typename T>
const T CVectorIterator<T>::operator->() const
{
    return this->ptr;
}


template <typename T>
CConstVectorIterator<T>::CConstVectorIterator(const CConstVectorIterator<T> &iter)
{
    this->ptr = iter.ptr;
}

template <typename T>
CConstVectorIterator<T>::CConstVectorIterator(T *p)
{
    this->ptr = p;
}

template <typename T>
const T CConstVectorIterator<T>::operator*() const
{
    return *(this->ptr);
}

template <typename T>
const T CConstVectorIterator<T>::operator->() const
{
    return this->ptr;
}
#endif // CVECTORITERATOR_IMP_H
