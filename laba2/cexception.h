#ifndef CEXCEPTION_H
#define CEXCEPTION_H
#include <exception>
#include <cstring>
#include <string>
#include "QDebug"

class CBaseException : public std::exception
{
public:

    const char* what();

    explicit CBaseException() = default;

    explicit CBaseException(const char* error);

    explicit CBaseException(const char* error, const char* addmsg);

    explicit CBaseException(const std::string& error);

    CBaseException(const CBaseException& ex);

    ~CBaseException();

private:

    char* msg = nullptr;
};

class CMemoryError : public CBaseException
{
public:

    explicit CMemoryError();

    explicit CMemoryError(char* addmsg);

    explicit CMemoryError(std::string& addmsg);

private:

    static const char defaultMsg[];

};


class CRangeError : public CBaseException
{
public:

    explicit CRangeError();

    explicit CRangeError(char* addmsg);

    explicit CRangeError(std::string& addmsg);

private:

    static const char defaultMsg[];

};

class CSizeError : public CBaseException
{
public:

    explicit CSizeError();

    explicit CSizeError(char *addmsg);

    explicit CSizeError(std::string& addmsg);

private:

    static const char defaultMsg[];

};
#endif // CEXCEPTION_H
