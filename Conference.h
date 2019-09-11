#pragma once

#include "List.h"
#include "Administrator.h"
#include "Presenter.h"
#include "Program.h"

enum {ADMIN, PREDENTER, PROGRAM};

class Conference
{
public:
	Conference(void);
	~Conference(void);
private:
	List<Administrator*> admins;
	List<Presenter*> presenters;
	Program myProgram;
};

MyException(void);
	MyException(const char *);
	MyException(const MyException &);
	~MyException(void);