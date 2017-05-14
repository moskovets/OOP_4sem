#ifndef CTRANSFORMMATRIX_H
#define CTRANSFORMMATRIX_H

#include "cmatrix.h"
#include "cvector.h"

class CTransformMatrix : public CMatrix<double>
{
    typedef  CMatrix<double> CDoubleMatrix;

public:
    CTransformMatrix(unsigned int dimension = 4);

    CTransformMatrix(const CTransformMatrix& obj);

    CTransformMatrix(CTransformMatrix&& obj);

    virtual ~CTransformMatrix();

    CTransformMatrix& operator= (const CTransformMatrix& obj);

    CTransformMatrix& operator= (CTransformMatrix&& obj);

    friend CTransformMatrix operator*(const CTransformMatrix& a, const CTransformMatrix& b);

    //friend CVector<double> operator*(const CVector<double>& vect, const CTransformMatrix& matr);

    friend CVector<double> operator*(const CTransformMatrix& matr, const CVector<double>& vect);

private:

    unsigned int n_d; // dimension

};

#endif // CTRANSFORMMATRIX_H
