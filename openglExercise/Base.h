#ifndef BASE
#define BASE

#include <GL/glut.h>

typedef void (*display_func)();
typedef void (*reshape_func)(int,int);
typedef void (*mouse_func)(int,int,int,int);
typedef void (*keyboard_func)(unsigned char ,int,int);

class Base
{
public:
	Base();
	virtual ~Base();

	virtual display_func warper_display();
	virtual reshape_func warper_reshape();
	virtual mouse_func warper_mouse();
	virtual keyboard_func warper_keyboard();
	virtual void init();

protected:
	
	static void display();
	static void reshape(int w,int h);
	static void mouse(int button,int state, int x,int y);
	static void keyboard(unsigned char key,int x,int y);

	int width;
	int height;
	int x;
	int y;

private:

};

#endif