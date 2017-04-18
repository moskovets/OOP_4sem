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
    explicit CBaseException(char *error, char *addmsg)
    {
        int n = strlen(error) + strlen(addmsg);
        msg = new char[n];
        if(!msg) { return; } //???????????????
        strcpy(msg, error);
        strcat(msg, addmsg);
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

class CMemoryError : public CBaseException
{
public:

    explicit CMemoryError() : CBaseException("Error memory allocate") {}
    explicit CMemoryError(char *addmsg) : CBaseException("Error memory allocate", addmsg) {}

};

class CRangeError : public CBaseException
{
public:

    explicit CRangeError() : CBaseException("Error out of range") {}

};

class CSizeError : public CBaseException
{
public:

    explicit CSizeError() : CBaseException("Error size") {}

};
#endif // CEXCEPTION_H
