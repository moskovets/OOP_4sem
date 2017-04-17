#ifndef CEXCEPTION_H
#define CEXCEPTION_H
#include <exception>
#include <cstring>
#include <string>

class CBaseException : public std::exception
{

public:

    const char *what()
    {
        return msg;
    }

    explicit CBaseException() = default;

    explicit CBaseException(char *error)
    {
        int n = strlen(error);
        msg = new char[n];
        if(!msg) { return; } //???????????????
        strcpy(msg, error);
    }

    explicit CBaseException(std::string &error)
    {
        int n = error.size();
        msg = new char[n];
        if(!msg) { return; } //???????????????
        strcpy(msg, error.c_str());
    }

    ~CBaseException()
    {
        delete[] msg;
    }

private:

    char *msg = nullptr;
};

#endif // CEXCEPTION_H
