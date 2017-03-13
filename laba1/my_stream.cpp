#include <my_stream.h>
#include "errors.h"

int Open_Stream(IN_Stream &stream, const char* filename)
{
    if(stream.inp) {
        stream.inp.close();
    }
    stream.inp.open(filename);
    if(!stream.inp) {
        return FILE_NOT_FIND;
    }
    return 0;
}

int Open_Stream(OUT_Stream &stream, const char* filename)
{
    if(stream.out) {
        stream.out.close();
    }
    stream.out.open(filename);
    if(!stream.out) {
        return FILE_NOT_FIND;
    }
    return 0;
}

int Close_Stream(IN_Stream &stream)
{
    if(stream.inp) {
        stream.inp.close();
    }
    return 0;
}

int Close_Stream(OUT_Stream &stream)
{
    if(stream.out) {
        stream.out.close();
    }
    return 0;
}


int Print_Stream(OUT_Stream &stream, const char* str)
{
    if(!stream.out)
        return FILE_NOT_FIND;
    stream.out << str;
    return 0;
}

int Read_Stream(double &x, IN_Stream &stream)
{
    if(!stream.inp)
        return FILE_NOT_FIND;
    double y = 0;
    if(!(stream.inp >> y))
        return FILE_ERROR;
    x = y;
    return 0;
}
int Read_Stream(int &x, IN_Stream &stream)
{
    if(!stream.inp)
        return FILE_NOT_FIND;
    int y = 0;
    if(!(stream.inp >> y))
        return FILE_ERROR;
    x = y;
    return 0;
}

