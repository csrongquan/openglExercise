#include "stdafx.h"
#include "stdlib.h"
#include "Unproject.h"


Unproject::Unproject(void)
{
}


Unproject::~Unproject(void)
{
}

display_func Unproject::warper_display()
{
	return Unproject::display;
}

reshape_func Unproject::warper_reshape()
{
	return Unproject::reshape;
}

mouse_func Unproject::warper_mouse()
{
	return Unproject::mouse;
}

void Unproject::display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void Unproject::reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0,(GLfloat)w/(GLfloat)h,1.0,100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Unproject::mouse(int button,int state,int x,int y)
{
	GLint viewport[4];
	GLdouble mvmatrix[16],projmatrix[16];
	GLint realy;
	GLdouble wx,wy,wz;
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if(state == GLUT_DOWN)
		{
			glGetIntegerv(GL_VIEWPORT,viewport);
			glGetDoublev(GL_MODELVIEW_MATRIX,mvmatrix);
			glGetDoublev(GL_PROJECTION_MATRIX,projmatrix);
			realy = viewport[3] - (GLint)y - 1;
			printf("Coordinates at cursor are (%4d,%4d,%4d,%4d)\n ",
				x,realy,viewport[3],y);
			gluUnProject((GLdouble)x,(GLdouble)realy,0.0,
				mvmatrix,projmatrix,viewport,&wx,&wy,&wz);
			printf("World coords at z=0.0 are (%f,%f,%f)\n",
				wx,wy,wz);
			gluUnProject((GLdouble)x,(GLdouble)realy,1.0,
				mvmatrix,projmatrix,viewport,&wx,&wy,&wz);
			printf("World coords at z=1.0 are (%f,%f,%f)\n",
				wx,wy,wz);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if(state == GLUT_DOWN)
		{
			exit(0);
		}
		break;
	default:
		break;
	}
}
