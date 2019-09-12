#pragma once

#include <string>
#include "List.h"
#include "SpeakerBilder.h"
#include "Conference.h"

using namespace std;
class SpeakerBilder;

class Speaker:public Conference
{
public:
	Speaker(SpeakerBilder&); 
	Speaker(const Speaker&);
	~Speaker(void);
	void WriteInFile(ofstream&)const override;
	bool operator == (const Speaker&)const;
private:
	string name;
	string surname;
	string father_name;
	string organization;
	string myLecture;
	string annotation;
	Speaker(void);
};