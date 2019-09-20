#include <iostream>
#include <GL/glut.h>
#include <stdio.h>

#define WINSIZE 600
#define TRUE_WINSIZE 600
#define INF 4000
#define STEP 1000

extern void drawaxis();



void draw_parametric_curve(double x1, double y1, double z1, double x2, double y2, double z2)
{
	glColor3f(255, 255, 255);
	glPointSize(20);
	glBegin(GL_POINTS);

	double xt, yt, zt;

	for (double t = 0; t <= 1; t += 1.0 / STEP)
	{
		xt = (1 - t)*x1 + t*x2;
		yt = (1 - t)*y1 + t*y2;
		zt = (1 - t)*z1 + t*z2;
		glVertex3f(xt, yt, zt);
	}
	

	glEnd();
	glFlush();
}

void draw_parametric_surface(double (*pixels)[3])
{
	glColor3f(255, 0, 0);
	glPointSize(2);
	glBegin(GL_POINTS);

	double xt, yt, zt;

	for (double u = 0; u <= 1; u += 1.0 / STEP)
	{
		for (double v = 0; v <= 1; v += 1.0 / STEP)
		{
			xt = (1 - v)*((1 - u)*pixels[0][0] + u*pixels[1][0]) + v *((1 - u)*pixels[3][0] + u*pixels[2][0]);
			yt = (1 - v)*((1 - u)*pixels[0][1] + u*pixels[1][1]) + v *((1 - u)*pixels[3][1] + u*pixels[2][1]);
			zt = (1 - v)*((1 - u)*pixels[0][2] + u*pixels[1][2]) + v *((1 - u)*pixels[3][2] + u*pixels[2][2]);
			glVertex3f(xt, yt, zt);
		}
	}
	glEnd();
	glFlush();
}

void display_parametric()
{
	drawaxis();
	draw_parametric_curve(3, -3, 6, 120, 120, 120);
	double pixels[4][3] = {
		-150, -150, -150,
		200, 300, -60,
		90, 180, 180,
		-200, 60, 20,
	};
	draw_parametric_surface(pixels);
}


void reshape_parametric(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-WINSIZE / 2, WINSIZE / 2, -WINSIZE / 2, WINSIZE / 2, -WINSIZE / 2, WINSIZE / 2);
	glMatrixMode(GL_MODELVIEW);
}




int main_parametric(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WINSIZE, WINSIZE);

	glutCreateWindow(argv[0]);
	glutReshapeFunc(reshape_parametric);

	glutDisplayFunc(display_parametric);
	glutMainLoop();

	return 0;
}




