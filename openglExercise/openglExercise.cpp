// openglExercise.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "Icosahedron.h"
#include "Cube.h"
#include "Mode.h"
#include "Clip.h"
#include "planet.h"
#include "Robot.h"
#include "Unproject.h"
#include "Smooth.h"
#include "Light.h"
#include "Blendeqn.h"
#include "Alpha.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Base& test = Alpha();

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	test.init();
	glutDisplayFunc(test.warper_display());
	glutReshapeFunc(test.warper_reshape());
	glutMouseFunc(test.warper_mouse());
	glutKeyboardFunc(test.warper_keyboard());
	glutMainLoop();

	return 0;
}

