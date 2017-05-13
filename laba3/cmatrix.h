#ifndef CMATRIX_H
#define CMATRIX_H

#include "cbasevector.h"

template <typename T>
class CMatrix : public CBaseVector
{
protected:
    class CRow;

public:
    CMatrix(std::size_t n, std::size_t m);
    CMatrix(std::size_t n, std::size_t m, const T* array);

    CMatrix(const CMatrix<T>& obj);

    CMatrix(CMatrix<T>&& obj);

    virtual ~CMatrix();

    CMatrix<T>& operator= (const CMatrix<T>& obj);

    CMatrix<T>& operator= (CMatrix<T>&& obj);

    CRow operator[](unsigned int index) const;

    CRow operator[](unsigned int index);

    T GetElement(unsigned int i, unsigned int j) const;

    T& GetElement(unsigned int i, unsigned int j);

    void SetElement(unsigned int i, unsigned int j, const T& value);

    T operator()(unsigned int i, unsigned int j) const;

    T& operator()(unsigned int i, unsigned int j);

protected:

    class CRow
    {
    public:
        CRow() = delete;

        CRow(T* array, unsigned int n)
            : arr_row(array), m(n) {}

        T& operator[](unsigned int index) {
            if(index >= this->m)
                throw CRangeError();

            return arr_row[index];
        }

        T operator[](unsigned int index) const {
            if(index >= this->m)
                throw CRangeError();

            return arr_row[index];
        }

    private:
        unsigned int m;
        T* arr_row = nullptr;
    };

private:

    std::size_t n;
    std::size_t m;

    T* arr = nullptr;
};

#include "cmatrix_imp.h"
#endif // CMATRIX_H
