#pragma once
#include "base.h"
class planet :
	public Base
{
public:
	planet(void);
	~planet(void);
	
	virtual void init();
	virtual display_func warper_display();
	virtual reshape_func warper_reshape();
	virtual keyboard_func warper_keyboard();

private:
	static void display();
	static void reshape(int w,int h);
	static void keyboard(unsigned char key,int x,int y);

	static int year;
	static int day;

};

