#pragma once
#include <string>

using namespace std;

class Administrator
{
public:
	Administrator(void);
	~Administrator(void);
private:
	string name;
	string surname;
	string father_name;
	string position;
	string responsible;
};

