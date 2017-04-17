#ifndef CMATHVECTOR_H
#define CMATHVECTOR_H
#include "cbasevector.h"

template <typename T>
class CMathVector : public CBaseVector
{
public:

    CMathVector(size_t n);

    CMathVector(size_t n, const T* array);

    CMathVector(const CMathVector<T> &obj);

    CMathVector(CMathVector<T> &&obj);

    ~CMathVector();

    CMathVector<T> &operator= (const CMathVector<T> &obj);

    CMathVector<T> &operator+=(const CMathVector<T> &obj);

    CMathVector<T> &operator-=(const CMathVector<T> &obj);

    T GetAbsoluteValue() const;

    T GetElement(int index) const;

    void SetElement(int index, const T &value);

    T operator*(const CMathVector<T> &obj);

    template <typename U>
    friend CMathVector<U> operator+(const CMathVector<U> &obj);

    template <typename U>
    friend CMathVector<U> operator-(const CMathVector<U> &obj);

    template <typename U>
    friend CMathVector<U> operator+(U &value);

    template <typename U>
    friend CMathVector<U> operator-(U &value);

    template <typename U>
    friend CMathVector<U> operator*(U &value);

    template <typename U>
    friend CMathVector<U> operator/(U &value);

    template <typename U>
    friend std::ostream& operator <<(std::ostream& os, const CMathVector<U> &obj);


private:

    T* arr = nullptr;
};

#endif // CMATHVECTOR_H
