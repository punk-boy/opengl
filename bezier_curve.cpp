#include <iostream>
#include <GL/glut.h>
#include <stdio.h>

void display_bezier_curve()
{

}


void reshape_bezier_curve(int w, int h)
{

}




int main_bezier(int argc, char ** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(300, 300);

	glutCreateWindow(argv[0]);
	glutReshapeFunc(reshape_bezier_curve);

	glutDisplayFunc(display_bezier_curve);
	glutMainLoop();



	return 0;
}




