#ifndef CVECTORITERATOR_H
#define CVECTORITERATOR_H

#include "cbaseiterator.h"

namespace myVector
{
    template <typename T>
    class CVectorIterator : public vectorBase::CBaseIterator<T>
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
    class CConstVectorIterator : public vectorBase::CBaseIterator<T>
    {
    public:

        CConstVectorIterator(const CConstVectorIterator<T>& iter);

        const T operator*() const;

        const T operator->() const;

        CConstVectorIterator(T* p);
    };

}

#include "cvectoriterator_imp.h"

#endif // CVECTORITERATOR_H

