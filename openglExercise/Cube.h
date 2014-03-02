#ifndef CUBE_H
#define CUBE_H

#include "Base.h"

class Cube : public Base
{
public:
	Cube();
	~Cube();

	virtual void init();
	virtual display_func warper_display();
	virtual reshape_func warper_reshape();

private:

	static void cube_display();
	static void cube_reshape(int w,int h);
};

#endif