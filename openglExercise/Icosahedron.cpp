#include "stdafx.h"
#include <math.h>
#include "Icosahedron.h"

Icosahedron::Icosahedron()
{

}

Icosahedron::~Icosahedron()
{

}



display_func Icosahedron::warper_display()
{
	return Icosahedron::icosahedron_display;
}


void Icosahedron::icosahedron_display()
{
	int i;
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_TRIANGLES);
	for(i=0;i<20;i++)
	{
		GLfloat d1[3],d2[3],norm[3];
		for(int j=0;j<3;j++)
		{
			d1[j] = vdata[tindices[i][0]][j]-
				vdata[tindices[i][1]][j];
			d2[j] = vdata[tindices[i][1]][j] - 
				vdata[tindices[i][2]][j];
		}
		normcrossprod(d1,d2,norm);
		glNormal3fv(norm);

		glVertex3fv(&vdata[tindices[i][0]][0]);
		glVertex3fv(&vdata[tindices[i][1]][0]);
		glVertex3fv(&vdata[tindices[i][2]][0]);
	}
	glEnd();
	glFlush();
}

void Icosahedron::init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}

void Icosahedron::normalize(float v[3])
{
	GLfloat d = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
	if(d == 0.0)
	{
		return;	
	}
	v[0] /= d;
	v[1] /= d;
	v[2] /= d;
}

void Icosahedron::normcrossprod(float v1[3],float v2[3],float out[3])
{
	out[0] = v1[1]*v2[2] - v1[2]*v2[1];
	out[1] = v1[2]*v2[0] - v1[0]*v2[2];
	out[2] = v1[0]*v2[1] - v1[1]*v2[0];
	normalize(out);
}