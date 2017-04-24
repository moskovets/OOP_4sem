#ifndef CBASEITERATOR_H
#define CBASEITERATOR_H

template <typename T>
class CBaseIterator
{
public:
    CBaseIterator(const CBaseIterator<T> &iter);


    virtual ~CBaseIterator();

    CBaseIterator<T>& operator=(const CBaseIterator<T> &iter);

    CBaseIterator<T>& operator++();
    CBaseIterator<T>& operator++(int);
    CBaseIterator<T>& operator--();
    CBaseIterator<T>& operator--(int);

    bool operator ==(const CBaseIterator &iter);
    bool operator !=(const CBaseIterator &iter);

protected:
    CBaseIterator(T *p) : ptr(p) {}

    T* ptr = nullptr;

};

#include "cbaseiterator_imp.h"

#endif // СBASEITERATOR_H
