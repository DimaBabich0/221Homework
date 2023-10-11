#include "ArrayDataException.h"

ArrayDataException::ArrayDataException(const char* message) : Exception(message)
{}

const char* ArrayDataException::GetMessage() const
{
	return m_message;
}
