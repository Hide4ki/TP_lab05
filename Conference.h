#pragma once

#include <string>
#include<fstream>

using namespace std;

class Conference
{
public:
	Conference(const string&);
	Conference(const Conference&);
	virtual ~Conference(void);
	virtual void WriteInFile(ofstream) = 0;
};