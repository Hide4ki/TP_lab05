#pragma once

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Builder
{
public:
	Builder(void);
	Builder(string&);
	Builder(const Builder&);
	virtual ~Builder(void);
	virtual void ReadInFile(ifstream&) = 0;
};

