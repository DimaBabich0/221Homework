#pragma once
#include "Exception.h"
class ArrayDataException : public Exception
{
public:
    ArrayDataException(const char* message);
    const char* GetMessage() const;
};