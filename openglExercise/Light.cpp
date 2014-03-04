#include "stdafx.h"
#include "Light.h"


Light::Light(void)
{
}


Light::~Light(void)
{
}

void Light::init()
{
	GLfloat mat_specular[] = {1.0,1.0,1.0,1.0};
	GLfloat mat_shininess[] = {50.0};
	GLfloat light_position[] = {1.0,1.0,1.0,0.0};
	GLfloat white_light[] = {1.0,1.0,1.0,1.0};
	GLfloat lmodel_ambient[] = {0.1,0.1,0.1,1.0};
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_shininess);
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,white_light);
	glLightfv(GL_LIGHT0,GL_SPECULAR,white_light);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lmodel_ambient);

	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//glEnable(GL_DEPTH_TEST);
}

void Light::display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSolidSphere(1.0,20,16);
	glFlush();
}

void Light::reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
	{
		glOrtho(-1.5,1.5,-1.5*(GLfloat)h/(GLfloat)w,1.5*(GLfloat)h/(GLfloat)w,-10.0,10.0);
	}
	else
	{
		glOrtho(-1.5*(GLfloat)h/(GLfloat)w,1.5*(GLfloat)h/(GLfloat)w,-1.5,1.5,-10.0,10.0);
	}
	glMatrixMode(GL_MODELVIEW);
}

display_func Light::warper_display()
{
	return Light::display;
}

reshape_func Light::warper_reshape()
{
	return Light::reshape;
}