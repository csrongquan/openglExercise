#ifndef MODE_H
#define MODE_H

#include "Base.h"

class Mode : public Base
{
public:
	Mode();
	~Mode();

	virtual display_func warper_display();
	virtual void init();

private:
	static void display();

	static void draw_triangle();
};

#endif