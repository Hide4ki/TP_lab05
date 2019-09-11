#pragma once

#include <string>
#include "List.h"
#include "SpeakerBilder.h"
#include "Conference.h"

using namespace std;

class Speaker:public Conference
{
public:
	Speaker(SpeakerBilder&); 
	Speaker(const Speaker&);
	~Speaker(void);
	void WriteInFile(ofstream) override;
private:
	string name;
	string surname;
	string father_name;
	string organization;
	string myLecture;
	string annotation;
};