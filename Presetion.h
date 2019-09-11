#pragma once
#include <ctime>
#include <string>

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
private:
	time_t stTime;
	string name;
};

