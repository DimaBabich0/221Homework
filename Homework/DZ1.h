#pragma once

const int SIZE_STR = 32;
const char pathEmployee[] = "DataEmployee.txt";
const char pathTemp[] = "Temp.txt";

struct Employee
{
	char firstName[SIZE_STR];
	char lastName[SIZE_STR];
	char phoneNumber[SIZE_STR];
	double salary;
};

enum actionsCodeMain
{
	codeAddEmployee = 1, codeDelEmployee, codeMenuReport, codeExitProgram
};
enum actionsCodeReport
{
	codePrintAllEmployee = 1, codePrintInfoEmployee, codeExitReport
};

char* lowercase(char* str);

void printInfoStruct(Employee point);

void printAllEmployee(const char pathEmployee[]);
void printInfoEmployee(const char pathEmployee[]);

void addEmployee(const char pathEmployee[]);

void delEmployee(const char pathEmployee[], const char pathTemp[]);

void printMenuMain();
void printMenuReport();