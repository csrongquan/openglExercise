// openglExercise.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include "Icosahedron.h"
#include "Cube.h"
#include "Mode.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Base& test = Mode();

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	test.init();
	glutDisplayFunc(test.warper_display());
	glutReshapeFunc(test.warper_reshape());
	glutMouseFunc(test.warper_mouse());
	glutMainLoop();

	return 0;
}
