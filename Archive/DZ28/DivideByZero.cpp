#include "DivideByZero.h"
DivideByZero::DivideByZero(const char* message) : Exception(message)
{}

const char* DivideByZero::GetMessage() const
{
	return m_message;
}