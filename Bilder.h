#pragma once

#include <string>
#include <fstream>

using namespace std;

class Bilder
{
public:
	Bilder(const Bilder&);
	virtual ~Bilder(void);
	virtual void ReadInFile(ostream&);
};

