#ifndef MY_STREAM_H
#define MY_STREAM_H

#include <fstream>

struct IN_Stream {
    std::ifstream inp;
};

struct OUT_Stream {
    std::ofstream out;
};

int Open_Stream(IN_Stream &stream, const char* filename);
int Open_Stream(OUT_Stream &stream, const char* filename);

int Close_Stream(IN_Stream &stream);
int Close_Stream(OUT_Stream &stream);

int Print_Stream(OUT_Stream &stream, const char* str);

int Read_Stream(double &x, IN_Stream &stream);
int Read_Stream(int &x, IN_Stream &stream);

#endif // MY_STREAM_H
