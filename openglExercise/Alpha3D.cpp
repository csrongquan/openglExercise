#include "stdafx.h"
#include "Alpha3D.h"

float Alpha3D::solidZ = MAXZ;
float Alpha3D::transparentZ = MINZ;

Alpha3D::Alpha3D(void)
{
}


Alpha3D::~Alpha3D(void)
{
}

display_func Alpha3D::warper_display()
{
	return Alpha3D::display;
}

reshape_func Alpha3D::warper_reshape()
{
	return Alpha3D::reshape;
}

keyboard_func Alpha3D::warper_keyboard()
{
	return Alpha3D::keyboard;
}

void Alpha3D::init()
{
	GLfloat mat_specular[] = {1.0,1.0,1.0,0.15};
	GLfloat mat_shininess[] = {100.0};
	GLfloat position[] = {0.5,0.5,1.0,0.0};

	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glLightfv(GL_LIGHT0,GL_POSITION,position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	spherreList = glGenLists(1);
	glNewList(spherreList,GL_COMPILE);
	glutSolidSphere(0.4,16,16);
	glEndList();

	cubeList = glGenLists();
	glNewList(cubeList,GL_COMPILE);
	glutSolidCube(0.6);
	glEndList();
}

void Alpha3D::display()
{
	GLfloat mat_solid[] = {0.75,0.75,0.0,1.0};
	GLfloat mat_zero[] = {0.0,0.0,0.0,1.0};
	GLfloat mat_transparent[] = {0.0,0.8,0.8,0.6};
	GLfloat mat_emission[] = {0.0,0.3,0.3,0.6};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(-0.15,-0.15,solidZ);
	glMaterialfv(GL_FRONT,GL_EMISSION,mat_zero);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_solid);
	glCallList(spherreList);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.15,0.15,transparentZ);
	glRotatef(15.0,1.0,1.0,0.0);
	glRotatef(30.0,0.0,1.0,0.0);
	glMaterialfv(GL_FRONT,GL_EMISSION,mat_emission);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_transparent);
	glEnable(GL_BLEND);
	glDepthMask(GL_FALSE);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	glCallList(cubeList);
	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);
	glPopMatrix();

	glutSwapBuffers();
}

void Alpha3D::reshape(int w,int h)
{
	glViewport(0,0,(GLint)w,(GLint)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
	{
		glOrtho(-1.5,1.5,-1.5*(GLfloat)h/(GLfloat)w,1.5*(GLfloat)h/(GLfloat)w,-10.0,10.0);
	}
	else
	{
		glOrtho(-1.5*(GLfloat)w/(GLfloat)h,1.5*(GLfloat)w/(GLfloat)h,-1.5,1.5,-10.0,10.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Alpha3D::animate()
{
	if(solidZ <= MINZ || transparentZ >= MAXZ)
	{
		glutIdleFunc(NULL);
	}
	else
	{
		solidZ -= ZINC;
		transparentZ += ZINC;
		glutPostRedisplay();
	}
}

void Alpha3D::keyboard(unsigned char key,int x,int y)
{
	switch (key)
	{
	case 'a':
	case 'A':
		solidZ = MAXZ;
		transparentZ = MINZ;
		glutIdleFunc(animate);
		break;
	case 'r':
	case 'R':
		solidZ = MAXZ;
		transparentZ = MINZ;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}