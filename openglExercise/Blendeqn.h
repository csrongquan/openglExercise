#pragma once
#include "base.h"
class Blendeqn :
	public Base
{
public:
	Blendeqn(void);
	~Blendeqn(void);
	
	virtual void init();
	virtual display_func warper_display();
	virtual keyboard_func warper_keyboard();

private:
	static void display();
	static void keyboard(unsigned char key,int x,int y);
};

