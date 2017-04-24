#ifndef CVECTORITERATOR_H
#define CVECTORITERATOR_H

#include "cmathvector.h"
#include "cbaseiterator.h"

template <typename T>
class CVectorIterator : public CBaseIterator<T>
{
public:

    CVectorIterator(const CVectorIterator<T> &iter);

    T& operator*();

    const T operator*() const;

    T& operator->();

    const T operator->() const;

    //friend class CMathVector;

    CVectorIterator(T *p);

//private:


};

template <typename T>
class CConstVectorIterator : public CBaseIterator<T>
{
public:

    CConstVectorIterator(const CConstVectorIterator<T> &iter);

    const T operator*() const;

    const T operator->() const;

    friend class CMathVector;

private:

    CConstVectorIterator(T *p);
};

#include "cvectoriterator_imp.h"

#endif // CVECTORITERATOR_H

