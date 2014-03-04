#include "stdafx.h"
#include "Smooth.h"


Smooth::Smooth(void)
{
}


Smooth::~Smooth(void)
{
}

void Smooth::init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);
}

display_func Smooth::warper_display()
{
	return Smooth::display;
}

reshape_func Smooth::warper_reshape()
{
	return Smooth::reshape;
}

void Smooth::triangle()
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(5.0,5.0);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(25.0,5.0);
	glColor3f(0.0,0.0,1.0);
	glVertex2f(5.0,25.0);
	glEnd();
}

void Smooth::display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	triangle();
	glFlush();
}

void Smooth::reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
	{
		gluOrtho2D(0.0,30.0,0.0,30.0*(GLfloat)h/(GLfloat)w);
	}
	else
	{
		gluOrtho2D(0.0,30.0*(GLfloat)w/(GLfloat)h,0.0,30.0);
	}
	glMatrixMode(GL_MODELVIEW);
}
