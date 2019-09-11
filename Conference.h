#pragma once

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

typedef enum{ADM, SPE, PRO} TYPE;

class Conference
{
public:
	Conference(void);
	Conference(const string&);
	Conference(const Conference&);
	virtual ~Conference(void);
	virtual void WriteInFile(ofstream&) = 0;
	TYPE getType(void)const{return myType;}
protected:
	TYPE myType;
};