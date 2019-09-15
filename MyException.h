#pragma once
#include <iostream>

using namespace std;

class MyException
{
private: 
	const string message;
public:
	MyException(void);
	MyException(const string);
	MyException(const MyException &);
	~MyException(void);
	friend ostream &operator << (ostream &stream,const MyException &);
};

