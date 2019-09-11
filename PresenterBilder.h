#pragma once

class PresenterBilder
{
public:
	PresenterBilder(void);
	~PresenterBilder(void);
private:
	string name;
	string surname;
	string fathername;
	string organization;
	List<Lecture*> myLectures;
	string annotation;
	friend Presenter;
};

