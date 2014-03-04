#include "stdafx.h"
#include "Alpha.h"

int Alpha::leftFirst = GL_TRUE;

Alpha::Alpha(void)
{
}


Alpha::~Alpha(void)
{
}

display_func Alpha::warper_display()
{
	return Alpha::display;
}

reshape_func Alpha::warper_reshape()
{
	return Alpha::reshape;
}

keyboard_func Alpha::warper_keyboard()
{
	return Alpha::keyboard;
}

void Alpha::init()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_FLAT);
	glClearColor(0.0,0.0,0.0,0.0);
}

void Alpha::drawLeftTriangle()
{
	glBegin(GL_TRIANGLES);
	glColor4f(1.0,1.0,0.0,0.75);
	glVertex3f(0.1,0.9,0.0);
	glVertex3f(0.1,0.1,0.0);
	glVertex3f(0.7,0.5,0.0);
	glEnd();
}

void Alpha::drawRightTriangle()
{
	glBegin(GL_TRIANGLES);
	glColor4f(0.0,1.0,1.0,0.75);
	glVertex3f(0.9,0.9,0.0);
	glVertex3f(0.3,0.5,0.0);
	glVertex3f(0.9,0.1,0.0);
	glEnd();
}

void Alpha::display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	if(leftFirst)
	{
		drawLeftTriangle();
		drawRightTriangle();
	}
	else
	{
		drawRightTriangle();
		drawLeftTriangle();
	}
	glFlush();
}

void Alpha::reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
	{
		gluOrtho2D(0.0,1.0,0.0,1.0*(GLfloat)h/(GLfloat)w);
	}
	else
	{
		gluOrtho2D(0.0,1.0*(GLfloat)w/(GLfloat)h,0.0,1.0);
	}
}

void Alpha::keyboard(unsigned char key,int x,int y)
{
	switch (key)
	{
	case 't':
	case 'T':
		leftFirst = !leftFirst;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}