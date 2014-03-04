#pragma once
#include "base.h"
class Unproject :
	public Base
{
public:
	Unproject(void);
	~Unproject(void);

	virtual display_func warper_display();
	virtual reshape_func warper_reshape();
	virtual mouse_func warper_mouse();

private:
	static void display();
	static void reshape(int w,int h);
	static void mouse(int button,int state,int x,int y);
};

