#ifndef BASEVECTOR_H
#define BASEVECTOR_H
#include "iostream"

class BaseVector
{
public:

    explicit BaseVector();

    explicit BaseVector(size_t len);

    virtual ~BaseVector();

    size_t size() const;

    bool empty() const;

protected:
    size_t length;
};

#endif // BASEVECTOR_H
