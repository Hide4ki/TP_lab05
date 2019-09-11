#pragma once

#include "Bilder.h"
#include "Speaker.h"

class SpeakerBilder:Bilder
{
public:
	SpeakerBilder(void);
	SpeakerBilder(string&);
	SpeakerBilder(const SpeakerBilder&);
	~SpeakerBilder(void);
	void ReadInFile(ostream&)override;
	SpeakerBilder &SetName(string&);
	SpeakerBilder &SetSurname(string&);
	SpeakerBilder &SetOrganization(string&);
	SpeakerBilder &SetLecture(string&);
	SpeakerBilder &SetAnnotation(string&);
private:
	friend Speaker;
	string name;
	string surname;
	string fathername;
	string organization;
	string myLecture;
	string annotation;
};

