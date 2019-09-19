
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

#define WINSIZE 600
#define INF 3000
using namespace std;




void read_off_data2(string filename)
{
	ifstream in("duck.off", ios::in);
	string filetype;
	


}
void read_off_data1(char* filename)
{
	char filetype[20];
	int vnum, fnum, third;
	int n; double x, y, z;
	int m, p1, p2, p3;
	FILE * fp = fopen(filename, "r");
	if (fp == NULL) { cout << "file open failed!" << endl; return; }
	
	fscanf(fp, "%s", filetype);
	fscanf(fp, "%d%d%d", &vnum, &fnum, &third);
	// cout << filetype << " " << vnum << " " << fnum << " " << third << endl;

	for (int i = 0; i < vnum; i++)
	{
		fscanf(fp, "%lf%lf%lf", &x, &y, &z);
		cout << x << "\t" << y << "\t" << z << endl;
	}

	for (int i = 0; i < fnum; i++)
	{
		fscanf(fp, "%d%d%d%d", &m, &p1, &p2, &p3);
		cout << p1 << "\t" << p2 << "\t" << p3 << endl;
	}


	return;


}
void drawaxis()
{
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(30, 1.0, 1.0, 1.0);
	glPointSize(5);
	// z
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, -WINSIZE / 2 - INF);
	glVertex3f(0, 0, WINSIZE / 2 + INF);
	glEnd();
	// y
	glColor3f(0, 255, 0);
	glBegin(GL_LINES);
	glVertex3f(0, -WINSIZE / 2 - INF, 0);
	glVertex3f(0, WINSIZE / 2 + INF, 0);
	glEnd();
	// x
	glColor3f(0, 0, 255);
	glBegin(GL_LINES);
	glVertex3f(-WINSIZE / 2 - INF, 0, 0);
	glVertex3f(WINSIZE / 2 + INF, 0, 0);
	glEnd();

	/*glBegin(GL_LINES);
	glVertex3f(0, 0, -1);
	glVertex3f(0, 0, 1);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0, -1, 0);
	glVertex3f(0, 1, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-1, 0, 0);
	glVertex3f(1, 0, 0);
	glEnd();*/

	cout << "draw coordinate axis finished!" << endl;
	glFlush();
}
void drawduck()
{


	return;
}


void prepareData()
{
	drawaxis();
	char * filename = "duck.off";
	// read_off_data1(filename);

}




void display_duck()
{
	
	drawaxis();
	drawduck();

}


void reshape_duck(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-WINSIZE / 2, WINSIZE / 2, -WINSIZE / 2, WINSIZE / 2, -WINSIZE / 2, WINSIZE / 2);
	glMatrixMode(GL_MODELVIEW);
}
void init_duck()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}


int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WINSIZE, WINSIZE);

	glutCreateWindow(argv[0]);
	
	prepareData();
	init_duck();
	
	glutDisplayFunc(display_duck);
	glutReshapeFunc(reshape_duck);
	glutMainLoop();
	return 0;
}




