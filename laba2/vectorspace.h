#ifndef VECTORSPACE_H
#define VECTORSPACE_H
#include <iostream>
#include "cexception.h"

namespace myVector
{
    namespace vectorBase
    {
        template <typename T>
        class CBaseIterator;

        class CBaseVector;
    }

    template <typename T>
    class CVectorIterator;

    template <typename T>
    class CConstVectorIterator;

    template <typename T>
    class CMathVector;
}

#endif // VECTORSPACE_H
