#ifndef CVECTORITERATOR_IMP_H
#define CVECTORITERATOR_IMP_H

#include "cvectoriterator.h"

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

#endif // CVECTORITERATOR_IMP_H
