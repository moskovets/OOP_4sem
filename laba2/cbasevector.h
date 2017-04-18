#ifndef CBASEVECTOR_H
#define CBASEVECTOR_H
#include "iostream"
#include "cexception.h"

class CBaseVector
{
public:

    explicit CBaseVector();

    explicit CBaseVector(size_t len);

    virtual ~CBaseVector();

    size_t Size() const;

    bool Empty() const;

protected:
    size_t length;
};

#endif // CBASEVECTOR_H
