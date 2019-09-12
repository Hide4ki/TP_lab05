#pragma once

#include "Bilder.h"
#include "Speaker.h"

typedef enum{SNAME, SSURNAME, SFATHERNAME, SORG, SANNO, SLEC, SFIN, SENDBILD} SBILD;

class Speaker;

class SpeakerBilder:Bilder
{
public:
	SpeakerBilder(void);
	SpeakerBilder(string&);
	SpeakerBilder(const SpeakerBilder&);
	~SpeakerBilder(void);
	void ReadInFile(ifstream&)override;
	SpeakerBilder &SetName(string&);
	SpeakerBilder &SetSurname(string&);
	SpeakerBilder &SetFathername(string&);
	SpeakerBilder &SetOrganization(string&);
	SpeakerBilder &SetLecture(string&);
	SpeakerBilder &SetAnnotation(string&);
	friend istream &operator >> (istream&, SpeakerBilder&);
private:
	friend Speaker;
	string name;
	string surname;
	string father_name;
	string organization;
	string myLecture;
	string annotation;
};

