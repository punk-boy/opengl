#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <GL/glut.h>
#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

#define WINSIZE 600
#define TRUE_WINSIZE 600
#define INF 4000
#define STEP 1000

extern void drawaxis();

vector<pair<GLfloat, GLfloat> > points;

inline int F(int n)
{
	if( n == 1 || n == 0 ) return 1;
	else return n * F(n-1);
}

inline int C(int i, int n)
{
	return F(n) / (F(i) * F(n - i));
}


void draw_line_segment()
{
	cout << "perpare to draw the line segments" << endl;
	glColor3f(0, 255, 0);
	glPointSize(1);

	



}

void draw_bezier_curve(int n)
{
	cout << "perpare to draw the bezier curve" << endl;
	glColor3f(255, 255, 255);
	glPointSize(1.0);
	glBegin(GL_POINTS);
	//double xt, yt;

	for (double t = 0; t <= 1; t += 1.0 / STEP)
	{	
		/*xt = 0;
		for (int i = 0; i <= n; i++)
			 xt += C(i, n) * pow(1 - t, n - i) * pow(t, i);*/
		GLfloat xt = points[0].first*pow(1.0f - t, 3) + 3 * points[1].first*t*pow(1.0f - t, 2) +
			3 * points[2].first*t*t*(1.0f - t) + points[3].first*pow(t, 3);
		/*yt = 0;
		for (int i = 0; i <= n; i++)
			yt += C(i, n) * pow(1 - t, n - i) * pow(t, i);*/

		GLfloat yt = points[0].second*pow(1.0f - t, 3) + 3 * points[1].second*t*pow(1.0f - t, 2) +
			3 * points[2].second*t*t*(1.0f - t) + points[3].second*pow(t, 3);

		glVertex2f(xt, yt);
		//cout << xt << ", " << yt << endl;
	}

	

	glEnd();
	glFlush();
}


void display_bezier()
{
	//drawaxis();
	//draw_bezier_curve(3);
	glFlush();
}


void reshape_bezier(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(-TRUE_WINSIZE / 2, TRUE_WINSIZE / 2, -TRUE_WINSIZE / 2, TRUE_WINSIZE / 2);
	gluOrtho2D(0, WINSIZE, 0, WINSIZE);
	glMatrixMode(GL_MODELVIEW);
}


void mouseListener(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		if (points.size() < 4)
		{
			x = x;
			y = WINSIZE - y;
			glColor3f(255, 255, 255);
			glPointSize(5);
			glBegin(GL_POINTS);
			glVertex2f(x, y);
			points.push_back(make_pair(x, y));
			printf("points.size:%d,\tx=%d,\ty=%d\n", points.size(), x, y);
			
			glEnd();
			glFlush();
		}
		else if (points.size() == 4)
		{
			draw_bezier_curve(3);
		}
	}

}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	// glutCreateWindow("Bezier Curve");

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WINSIZE, WINSIZE);

	glutCreateWindow(argv[0]);
	glutReshapeFunc(reshape_bezier);

	glutDisplayFunc(display_bezier);
	glutMouseFunc(mouseListener);



	glutMainLoop();



	return 0;
}




