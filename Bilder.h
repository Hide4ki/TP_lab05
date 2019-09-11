#pragma once

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Bilder
{
public:
	Bilder(void);
	Bilder(string&);
	Bilder(const Bilder&);
	virtual ~Bilder(void);
	virtual void ReadInFile(ifstream&) = 0;
};

