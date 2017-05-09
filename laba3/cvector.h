#ifndef CVECTOR_H
#define CVECTOR_H

#include "cbasevector.h"

template <typename T>
class CVector : public CBaseVector
{
public:

    CVector(std::size_t n);

    CVector(std::size_t n, const T* array);

    CVector(const std::initializer_list<T>& list);

    CVector(const CVector<T>& obj);

    CVector(CVector<T>&& obj);

    virtual ~CVector();

    CVector<T>& operator= (const CVector<T>& obj);

    CVector<T>& operator= (CVector<T>&& obj);

    T operator[](unsigned int index) const;

    T& operator[](unsigned int index);

    T GetElement(unsigned int index) const;

    T& GetElement(unsigned int index);

    void SetElement(unsigned int index, const T& value);

    T operator()(unsigned int index) const;

    T& operator()(unsigned int index);

private:

    T* arr = nullptr;
};

#include <cvector_imp.h>

#endif // CMATHVECTOR_H
