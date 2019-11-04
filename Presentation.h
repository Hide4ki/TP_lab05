#pragma once
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Presentation
{
public:
	Presentation(void);
	Presentation(time_t,string&); 
	Presentation(const Presentation&);
	~Presentation(void);
	void setName(string&);
	void setDate(time_t);
	string &getName(void);
	time_t getDate(void);
	friend ofstream &operator<<(ofstream &stream, Presentation &myPresent);
	friend ifstream &operator>>(ifstream &stream, Presentation &myPresent);
	friend istream &operator>>(istream &stream, Presentation &myPresent);
private:
	time_t stTime;
	string name;
};

