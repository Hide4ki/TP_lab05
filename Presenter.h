#pragma once
#include <string>
#include "Lecture.h"
#include "List.h"
#include "PresenterBilder.h"

using namespace std;

class Presenter
{
public:
	Presenter(void);
	Presenter(PresenterBilder&); 
	Presenter(const Presenter&);
	~Presenter(void);
private:
	string name;
	string surname;
	string father_name;
	string organization;
	List<Lecture*> myLectures;
	string annotation;
};