#include "stdafx.h"
#include "Robot.h"
 
int Robot::shoulder = 0;
int Robot::elbow = 0;

Robot::Robot(void)
{
}


Robot::~Robot(void)
{
}

void Robot::init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}

void Robot::display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(-1.0,0.0,0.0);
	glRotatef((GLfloat)shoulder,0.0,0.0,1.0);
	glTranslatef(1.0,0.0,0.0);
	glPushMatrix();
	glScalef(2.0,0.4,1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.0,0.0,0.0);
	glRotatef((GLfloat)elbow,0.0,0.0,1.0);
	glTranslatef(1.0,0.0,0.0);
	glPushMatrix();
	glScalef(2.0,0.4,1.0);
	glutWireCube(1.0);
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();
}

void Robot::reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0,(GLfloat)w/(GLfloat)h,1.0,20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-5.0);
}

void Robot::keyboard(unsigned char key,int x,int y)
{
	switch (key)
	{
	case 's':
		shoulder = (shoulder + 5)%360;
		glutPostRedisplay();
		break;
	case 'S':
		shoulder = (shoulder - 5)%360;
		glutPostRedisplay();
		break;
	case 'e':
		elbow = (elbow + 5)%360;
		glutPostRedisplay();
		break;
	case 'E':
		elbow = (elbow - 5)%360;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

display_func Robot::warper_display()
{
	return Robot::display;
}

reshape_func Robot::warper_reshape()
{
	return Robot::reshape;
}

keyboard_func Robot::warper_keyboard()
{
	return Robot::keyboard;
}






