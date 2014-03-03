#include "stdafx.h"
#include "Mode.h"

Mode::Mode()
{

}

Mode::~Mode()
{

}

void Mode::init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
}

display_func Mode::warper_display()
{
	return Mode::display;
}

void Mode::display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glColor3f(1.0,1.0,1.0);
	draw_triangle();

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1,0xF0F0);
	glLoadIdentity();
	glTranslated(-20.0,0.0,0.0);
	draw_triangle();

	glLineStipple(1,0xF00F);
	glLoadIdentity();
	glScalef(1.5,0.5,1.0);
	draw_triangle();

	glLineStipple(1,0x8888);
	glLoadIdentity();
	glRotatef(90.0,0.0,0.0,1.0);
	draw_triangle();
	glDisable(GL_LINE_STIPPLE);

	glFlush();
}

void Mode::draw_triangle()
{
	glBegin(GL_TRIANGLES);

	glVertex2f(-0.3,-0.3);
	glVertex2f(0.3,-0.3);
	glVertex2f(0.0,0.3);

	glEnd();
}