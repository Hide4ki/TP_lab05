#pragma once
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Presetion
{
public:
	Presetion(void);
	Presetion(time_t,string&); 
	Presetion(const Presetion&);
	~Presetion(void);
	void setName(string&);
	void setDate(time_t);
	string &getName(void);
	time_t getDate(void);
	friend ofstream &operator<<(ofstream &stream, Presetion &myPresent);
	friend ifstream &operator>>(ifstream &stream, Presetion &myPresent);
	friend istream &operator>>(istream &stream, Presetion &myPresent);
private:
	time_t stTime;
	string name;
};

