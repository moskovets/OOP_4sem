#ifndef CBASEVECTOR_H
#define CBASEVECTOR_H
#include "iostream"

class CBaseVector
{
public:

    explicit CBaseVector();

    explicit CBaseVector(size_t len);

    virtual ~CBaseVector();

    size_t size() const;

    bool empty() const;

protected:
    size_t length;
};

#endif // CBASEVECTOR_H
