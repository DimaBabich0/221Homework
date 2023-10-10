#include "IndexException.h"
IndexException::IndexException(const char* message) : Exception(message)
{}

const char* IndexException::GetMessage() const
{
	return m_message;
}