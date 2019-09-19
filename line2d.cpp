#include <GL/glut.h>
#include <cmath>
#include <stdio.h>

void bresenhamLine2DPlus(int x0, int y0, int x1, int y1)
{
	int x = x0, y = y0, dx = x1 - x0, dy = y1 - y0;
	float k = 1.0 * dy / dx, e = -0.5;
	glBegin(GL_POINTS);
	glPointSize(1.0);
	glColor3f(255, 0, 255);
	glVertex2i(x, y);
	while (x < x1)
	{
		x++, e = e + k;
		glVertex2i(x, y);
		while (e >= 0)
		{
			y++, e = e - 1;
			glVertex2i(x, y);
		}	
	}
	glEnd();
	glFlush();
}

void bresenhamLine2D(int x0, int y0, int x1, int y1)
{

	int x = x0, y = y0, dx = x1 - x0, dy = y1 - y0;
	float k = 1.0 * dy / dx, e = -0.5;
	glBegin(GL_POINTS);
	glPointSize(1.0);
	glColor3f(255, 0, 255);

	while (x < x1)
	{
		glVertex2i(x, y);
		x++, e = e + k;
		if (e >= 0)
		{
			y++, e = e - 1;
		}
	}
	glEnd();
	glFlush();
}


void bresenhamArch2DOrigin(int r)
{
	glBegin(GL_POINTS);
	int x, y, p;
	x = 0;
	y = r;
	p = 3 - 2 * r;
	while (x < y)
	{
		glVertex2i(x, y);
		if (p < 0)
		{
			p = p + 4 * x + 6;
		}
		else
		{
			p = p + 4 * (x - y) + 10;
			y = y - 1;
		}
		x = x + 1;
	}
	if (x == y)
	{
		glVertex2i(x, y);
	}
	glEnd();
	glFlush();
}


void bresenhamArch2D(int r, float angle)
{
	glBegin(GL_POINTS);
	float radius = angle * 3.1415926 / 180;
	int x0 = 0, y0 = r, x1 = r * sin(radius), y1 = r - r * cos(radius), x = x0, y = y0;
	float e = 0.5;
	printf("(%d, %d) -> (%d, %d)", x0, y0, x1, y1);
	while (x < x1)
	{
		glVertex2i(x, y);
		x++, e = e + (-1.0 * x / y);
		while(e <= 0)
		{
			y--, e = e + 1;
			glVertex2i(x, y);
		}
	}
	glEnd();
	glFlush();
}

void display_line2D()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//bresenhamLine2DPlus(-10, -100, 20, 200);
	//bresenhamLine2D(-150, 17, 89, 67);
	glColor3f(1, 0, 0);
	bresenhamArch2DOrigin(41);
	//glColor3i(0, 0, 255);
	bresenhamArch2D(40, 90);
	
}

void reshape_line2D(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-150, 150, -150, 150);
	glMatrixMode(GL_MODELVIEW);
	// ? glLoadIdentity();
}


void main_2d(int argc, char ** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(300,300);

	glutCreateWindow(argv[0]);
	glutReshapeFunc(reshape_line2D);

	glutDisplayFunc(display_line2D);
	glutMainLoop();


	return;
}




