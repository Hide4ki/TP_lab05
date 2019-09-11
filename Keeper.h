#pragma once

#include <fstream>
#include "List.h"
#include "IteratorPtr.h"
#include "Conference.h"
#include "AdministratorBilder.h"
#include "SpeakerBilder.h"
#include "ProgramBilder.h"

using namespace std;

class Keeper
{
public:
	Keeper(void);
	Keeper(ifstream&);
	Keeper(const Keeper&);
	~Keeper(void);
	void addObj(Conference *);
	void deleteObj(Conference *);
	bool findObj(const Conference *);
	void LoadFromFile(ifstream&);  
	void SafeToFile(ofstream&);
private:
	List<Conference*> *ConParts;
};

