#pragma once
#include "base.h"
class Robot :
	public Base
{
public:
	Robot(void);
	~Robot(void);

	virtual void init();
	virtual display_func warper_display();
	virtual reshape_func warper_reshape();
	virtual keyboard_func warper_keyboard();

private:
	static int shoulder;
	static int elbow;

	static void display();
	static void reshape(int w,int h);
	static void keyboard(unsigned char key,int x,int y);
};

