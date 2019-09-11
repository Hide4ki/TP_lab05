#pragma once
#include <iostream>

using namespace std;

class Item
{
	char a;
public:
	Item(){}
	Item(char a):a(a){}
	~Item(void);
	
	friend ostream &operator <<(ostream &stream, const Item &myItem);
	bool operator == (const Item &myItem)
	{
		return a == myItem.a;
	}
};

