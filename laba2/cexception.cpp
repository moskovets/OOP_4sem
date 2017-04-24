#include "cexception.h"

const char CMemoryError::defaultMsg[] = "Error memory allocate ";

const char CRangeError::defaultMsg[]  = "Error out of range ";

const char CSizeError::defaultMsg[]   = "Error size ";

const char* CBaseException::what()
{
    return msg;
}

CBaseException::CBaseException(const char* error)
{
    int n = strlen(error) + 1;
    msg = new char[n];
    if(!msg) { return; } //???????????????
    strcpy(msg, error);
}

CBaseException::CBaseException(const char* error, const char* addmsg)
{
    int n = strlen(error) + strlen(addmsg) + 1;
    msg = new char[n];
    if(!msg) { return; } //???????????????
    strcpy(msg, error);
    strcat(msg, addmsg);
}

CBaseException::CBaseException(const std::string& error)
{
    int n = error.size() + 1;
    msg = new char[n];
    if(!msg) { return; } //???????????????
    strcpy(msg, error.c_str());
}

CBaseException::CBaseException(const CBaseException& ex)
{
    msg = new char[strlen(ex.msg) + 1];
    if(!msg)
        return; //????
    strcpy(msg, ex.msg);
}

CBaseException::~CBaseException()
{
    delete[] msg;
}

CMemoryError::CMemoryError() : CBaseException(defaultMsg) {}

CMemoryError::CMemoryError(char* addmsg) : CBaseException(defaultMsg, addmsg) {}

CMemoryError::CMemoryError(std::string& addmsg) : CBaseException(defaultMsg, addmsg.c_str()) {}


CRangeError::CRangeError() : CBaseException(defaultMsg) {}

CRangeError::CRangeError(char* addmsg) : CBaseException(defaultMsg, addmsg) {}

CRangeError::CRangeError(std::string& addmsg) : CBaseException(defaultMsg, addmsg.c_str()) {}


CSizeError::CSizeError() : CBaseException(defaultMsg) {}

CSizeError::CSizeError(char* addmsg) : CBaseException(defaultMsg, addmsg) {}

CSizeError::CSizeError(std::string& addmsg) : CBaseException(defaultMsg, addmsg.c_str()) {}
