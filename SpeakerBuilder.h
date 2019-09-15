#pragma once

#include "Builder.h"
#include "Speaker.h"

typedef enum{SNAME, SSURNAME, SFATHERNAME, SORG, SANNO, SLEC, SFIN, SENDBILD} SBILD;

class Speaker;

class SpeakerBuilder:Builder
{
public:
	SpeakerBuilder(void);
	SpeakerBuilder(string&);
	SpeakerBuilder(const SpeakerBuilder&);
	~SpeakerBuilder(void);
	void ReadInFile(ifstream&)override;
	SpeakerBuilder &SetName(string&);
	SpeakerBuilder &SetSurname(string&);
	SpeakerBuilder &SetFathername(string&);
	SpeakerBuilder &SetOrganization(string&);
	SpeakerBuilder &SetLecture(string&);
	SpeakerBuilder &SetAnnotation(string&);
	friend istream &operator >> (istream&, SpeakerBuilder&);
private:
	friend Speaker;
	string name;
	string surname;
	string father_name;
	string organization;
	string myLecture;
	string annotation;
};

