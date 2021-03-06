#include "stdafx.h"
#include "Clip.h"


Clip::Clip(void)
{
}


Clip::~Clip(void)
{
}

void Clip::init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}

display_func Clip::warper_display()
{
	return Clip::display;
}

reshape_func Clip::warper_reshape()
{
	return Clip::reshape;
}

void Clip::display()
{
	GLdouble eqn[4] = {0.0,1.0,0.0,0.0};
	GLdouble eqn2[4] = {1.0,0.0,0.0,0.0};

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glPushMatrix();
	glTranslatef(0.0,0.0,-5.0);

	glClipPlane(GL_CLIP_PLANE0,eqn);
	glEnable(GL_CLIP_PLANE0);
	glClipPlane(GL_CLIP_PLANE1,eqn2);
	glEnable(GL_CLIP_PLANE1);

	glRotatef(90.0,1.0,0.0,0.0);
	glutWireSphere(1.0,20,16);
	glPopMatrix();
	glFlush();
}

void Clip::reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0,(GLfloat)w/(GLfloat)h,1.0,20.0);
	glMatrixMode(GL_MODELVIEW);
}