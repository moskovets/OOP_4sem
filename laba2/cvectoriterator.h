#ifndef CVECTORITERATOR_H
#define CVECTORITERATOR_H

#include "cmathvector.h"
#include "cbaseiterator.h"

template <typename T>
class CVectorIterator : public CBaseIterator<T>
{
public:

    CVectorIterator(const CVectorIterator<T>& iter);

    T& operator*();

    const T operator*() const;

    T& operator->();

    const T operator->() const;

    CVectorIterator(T *p);

};

template <typename T>
class CConstVectorIterator : public CBaseIterator<T>
{
public:

    CConstVectorIterator(const CConstVectorIterator<T>& iter);

    const T operator*() const;

    const T operator->() const;

    CConstVectorIterator(T* p);
};

#include "cvectoriterator_imp.h"

#endif // CVECTORITERATOR_H

