#include <GL/glut.h>
#include <cmath>
#include <stdio.h>

void bresenhamLine3DPlus(int x0, int y0, int x1, int y1)
{
}

void bresenhamLine3D(int x0, int y0, int z0, int x1, int y1, int z1)
{
	glPointSize(5.0);
	glColor3f(255, 0, 0);
	glBegin(GL_POINTS);
	
	int x = x0, y = y0, z = z0, dx = x1 - x0, dy = y1 - y0, dz = z1 - z0;
	float ey = -0.5, ez = -0.5;
	while (x < x1)
	{
		glVertex3i(x, y, z);
		printf("%d, %d, %d\n", x, y, z);
		x++, ey = ey + 1.0 * dy / dx, ez = ez + 1.0 * dz / dx;
		if (ey >= 0) y++, ey = ey - 1;
		if (ez >= 0) z++, ez = ez - 1;
	}
	
	
	glEnd();
	glFlush();

	
	
}



void bresenhamArch3D(int r, float angle)
{
	//glRotatef(60, 0, 1, 0.0);
	glBegin(GL_POINTS);
	float radius = angle * 3.1415926 / 180;
	int x0 = 0, y0 = r, z0 = 0, x1 = r * sin(radius), y1 = r - r * cos(radius), x = x0, y = y0, z = z0;
	float e = 0.5;
	// printf("(%d, %d) -> (%d, %d)", x0, y0, x1, y1);
	while (x < x1)
	{
		glVertex3i(x, y, z);
		x++, e = e + (-1.0 * x / y);
		while (e <= 0)
		{
			y--, e = e + 1;
			glVertex3i(x, y, z);
		}
	}
	glEnd();
	glFlush();
}


void display_line3D()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//bresenhamLine3D(-1, -1, -1, 100, 100, 100);
	glColor3f(1,0,0);
	bresenhamArch3D(40, 90);
	glRotatef(60, 0, 1, 0.0);
	glColor3f(0, 1, 0);
	bresenhamArch3D(40, 90);

}

void reshape_line3D(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-150, 150, -150, 150, -150, 150);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void main_3d(int argc, char ** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(300, 300);

	glutCreateWindow(argv[0]);
	glutReshapeFunc(reshape_line3D);

	glutDisplayFunc(display_line3D);
	glutMainLoop();

	return;
}




