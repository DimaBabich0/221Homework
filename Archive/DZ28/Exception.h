#pragma once
class Exception
{
protected:
    char m_message[30];
public:
    Exception(const char* message);
    const char* GetMessage() const;
};