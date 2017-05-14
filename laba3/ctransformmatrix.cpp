#include "ctransformmatrix.h"

CTransformMatrix::CTransformMatrix(unsigned int dimension) :
    CDoubleMatrix(dimension, dimension)
{
    n_d = dimension;
}

CTransformMatrix::CTransformMatrix(const CTransformMatrix &obj) :
    CDoubleMatrix(obj)
{
    this->n_d = obj.n_d;
}

CTransformMatrix::CTransformMatrix(CTransformMatrix &&obj) :
    CDoubleMatrix(obj)
{
   /* this->arr = obj.arr;
    this->length = obj.length;
    this->n = obj.n;
    this->m = obj.m;*/
    this->n_d = obj.n_d;

    obj.arr = nullptr;
    obj.length = 0;
    obj.n = 0;
    obj.m = 0;
}

CTransformMatrix::~CTransformMatrix()
{

}

CTransformMatrix &CTransformMatrix::operator=(const CTransformMatrix &obj)
{
    this->CMatrix::operator =(obj);
    this->n_d = obj.n_d;
/*
    double* new_arr = nullptr;
    try {
        new_arr = new T[obj.Size()];
    }
    catch (std::bad_alloc) {
        throw CMemoryError();
    }
    memcpy(new_arr, obj.arr, obj.Size() * sizeof(T));

    delete[] arr;
    arr = new_arr;
    this->length = obj.Size();
    this->n = obj.n;
    this->m = obj.m;
    this->*/
    return *this;
}

CTransformMatrix &CTransformMatrix::operator=(CTransformMatrix &&obj)
{
    if(this != &obj) {
        this->CMatrix::operator =(obj);
        this->n_d = obj.n_d;
        obj.n_d = 0;
    }
    return *this;
}

/*CVector<double> operator*(const CVector<double> &vect, const CTransformMatrix &matr)
{
    if(vect.Size() != matr.n_d)
        throw CSizeError();

    CVector<double> res(matr.n_d);

    for(int i = 0; i < matr.n_d; i++) {
        for(int j = 0; j < matr.n_d; j++) {
            res[i] += matr[j][i] * vect[j];
        }
    }

    return res;
}*/

CVector<double> operator*(const CTransformMatrix &matr, const CVector<double> &vect)
{
    if(vect.Size() != matr.n_d)
        throw CSizeError();

    CVector<double> res(matr.n_d);

    for(int i = 0; i < matr.n_d; i++) {
        for(int j = 0; j < matr.n_d; j++) {
            res[i] += matr[i][j] * vect[j];
        }
    }

    return res;
}

CTransformMatrix operator*(const CTransformMatrix &a, const CTransformMatrix &b)
{
    if(b.n_d != a.n_d)
        throw CSizeError();

    CTransformMatrix res(a.n_d);

    for(int i = 0; i < a.n_d; i++) {
        for(int j = 0; j < a.n_d; j++) {
            res[i][j] = 0;
            for(int k = 0; k < a.n_d; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return res;
}
