#pragma once
#include "base.h"
class Light :
	public Base
{
public:
	Light(void);
	~Light(void);

	virtual void init();
	virtual display_func warper_display();
	virtual reshape_func warper_reshape();

private:
	static void display();
	static void reshape(int w,int h);
};

