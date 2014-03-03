#pragma once
#include "base.h"
class planet :
	public Base
{
public:
	planet(void);
	~planet(void);
	
	virtual void init();

private:
	static int year;
	static int day;

};

