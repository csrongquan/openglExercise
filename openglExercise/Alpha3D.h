#pragma once
#include "base.h"

#define MAXZ 8.0
#define MINZ -8.0
#define ZINC 0.4

class Alpha3D :
	public Base
{
public:
	Alpha3D(void);
	~Alpha3D(void);
	virtual void init();
	virtual display_func warper_display();
	virtual reshape_func warper_reshape();
	virtual keyboard_func warper_keyboard();

private:
	static float solidZ;
	static float transparentZ;
	static GLuint spherreList,cubeList;

	static void display();
	static void reshape(int w,int h);
	static void keyboard(unsigned char key,int x,int y);
	static void animate();
};

