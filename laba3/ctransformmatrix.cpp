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
