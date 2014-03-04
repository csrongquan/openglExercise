#pragma once
#include "base.h"
class Smooth :
	public Base
{
public:
	Smooth(void);
	~Smooth(void);

	virtual void init();
	virtual display_func warper_display();
	virtual reshape_func warper_reshape();

private:
	static void triangle();

	static void display();
	static void reshape(int w,int h);
};

