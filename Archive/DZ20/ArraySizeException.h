#pragma once
#include "Exception.h"
class ArraySizeException : public Exception
{
public:
    ArraySizeException(const char* message);
    const char* GetMessage() const;
};

