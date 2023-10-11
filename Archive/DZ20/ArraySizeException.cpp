#include "ArraySizeException.h"

ArraySizeException::ArraySizeException(const char* message) : Exception(message)
{}

const char* ArraySizeException::GetMessage() const
{
	return m_message;
}
