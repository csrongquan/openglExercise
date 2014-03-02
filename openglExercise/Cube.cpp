#include "stdafx.h"
#include "Cube.h"

Cube::Cube()
{
}

Cube::~Cube()
{
}

void Cube::init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}

display_func Cube::warper_display()
{
	return Cube::cube_display;
}

reshape_func Cube::warper_reshape()
{
	return Cube::cube_reshape;
}

void Cube::cube_display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glLoadIdentity();

	gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
	glScalef(1.0,2.0,1.0);
	glutWireCube(1.0);
	glFlush();
}

void Cube::cube_reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-1.0,1.0,-1.0,1.0,1.5,20.0);
	gluPerspective(60.0,1.0,1.5,20.0);
	glMatrixMode(GL_MODELVIEW);
}
