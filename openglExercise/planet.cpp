#include "stdafx.h"
#include "planet.h"

int planet::year = 0;
int planet::day = 0;

planet::planet(void)
{
}


planet::~planet(void)
{
}

display_func planet::warper_display()
{
	return planet::display;
}

reshape_func planet::warper_reshape()
{
	return planet::reshape;
}

keyboard_func planet::warper_keyboard()
{
	return planet::keyboard;
}

void planet::init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}

void planet::display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glPushMatrix();
	glutWireSphere(1.0,20,16); //draw sun
	glRotatef((GLfloat)year,0.0,1.0,0.0);
	glTranslatef(2.0,1.0,0.0);
	glRotatef((GLfloat)day,0.0,1.0,0.0);
	glutWireSphere(0.2,10,8);  //draw small planet
	glPopMatrix();
	glutSwapBuffers();
}

void planet::reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0,(GLfloat)w/(GLfloat)h,1.0,20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
}

void planet::keyboard(unsigned char key,int x,int y)
{
	switch (key)
	{
	case 'd':
		day = (day+10)%360;
		glutPostRedisplay();
		break;
	case 'D':
		day = (day - 10)%360;
		glutPostRedisplay();
		break;
	case 'y':
		year = (year + 5)%360;
		glutPostRedisplay();
		break;
	case 'Y':
		year = (year - 5)%360;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

