#pragma once
#include "base.h"
class Alpha :
	public Base
{
public:
	Alpha(void);
	~Alpha(void);

	virtual void init();
	virtual display_func warper_display();
	virtual reshape_func warper_reshape();
	virtual keyboard_func warper_keyboard();

private:
	static int leftFirst;
	static void drawLeftTriangle();
	static void drawRightTriangle();
	static void display();
	static void reshape(int w,int h);
	static void keyboard(unsigned char key,int x,int y);
};

