#ifndef CTRANSFORMMATRIX_H
#define CTRANSFORMMATRIX_H

#include "cmatrix.h"

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

private:

    unsigned int n_d; // dimension

};

#endif // CTRANSFORMMATRIX_H
