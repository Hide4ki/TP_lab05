#pragma once

#include <fstream>
#include "List.h"
#include "IteratorPtr.h"
#include "Conference.h"

using namespace std;

class Keeper
{
public:
	Keeper(void);
	Keeper(ifstream&);
	Keeper(const Keeper&);
	~Keeper(void);
	void addObj(const Conference *);
	void deleteObj(const Conference *);
	bool findObj(const Conference &);
	void LoadFromFile(ifstream&);  
	void SafeToFile(ofstream&);
private:
	List<Conference*>ListConferense;
};

