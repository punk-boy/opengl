
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

#define TRUE_WINSIZE 600
#define WINSIZE 3000
#define INF 9000
using namespace std;


/* double (*point)[3] = NULL;
int (*face)[3] = NULL;*/
// data
double ** point;
int ** face;
int vnum, fnum, third;

void read_off_data2(string filename)
{
	ifstream in("duck.off", ios::in);
	string filetype;
	


}
void read_off_data1(char* filename)
{
	char filetype[20];
	//int vnum, fnum, third;
	int n; double x, y, z;
	int m, p1, p2, p3;
	FILE * fp = fopen(filename, "r");
	if (fp == NULL) { cout << "file open failed!" << endl; return; }
	
	fscanf(fp, "%s", filetype);
	fscanf(fp, "%d%d%d", &vnum, &fnum, &third);
	// cout << filetype << " " << vnum << " " << fnum << " " << third << endl;
    // alloc the memery
    point = (double **)malloc(sizeof(double*) * (vnum));
    for(int i=0;i<=vnum;i++) point[i] = (double *)malloc(sizeof(double) * 3);
    face = (int **)malloc(sizeof(int *) * (fnum));
    for(int i=0;i<=fnum;i++) face[i] = (int *)malloc(sizeof(int) * 3);
    // store the data
	for (int i = 0; i < vnum; i++)
	{
		fscanf(fp, "%lf%lf%lf", &x, &y, &z);
		// cout << x << "\t" << y << "\t" << z << endl;
        point[i][0] = x;
        point[i][1] = y;
        point[i][2] = z;
	}

	for (int i = 0; i < fnum; i++)
	{
		fscanf(fp, "%d%d%d%d", &m, &p1, &p2, &p3);
		// cout << p1 << "\t" << p2 << "\t" << p3 << endl;
        face[i][0] = p1;
        face[i][1] = p2;
        face[i][2] = p3;
	}
    // print the data
    for(int i=0;i<vnum;i++)
    {
        cout << point[i][0] << "\t" << point[i][1] << "\t" << point[i][2] << endl;
    }
    cout << "=========================================" << endl;
    for(int i=0;i<fnum;i++)
    {
        cout << face[i][0] << "\t" << face[i][1] << "\t" << face[i][2] << endl;
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

bool visiable(int i)
{
/*    double matrix[3][3] = {
        point[face[i][0]][0], point[face[i][0]][1], point[face[i][0]][2],
        point[face[i][1]][0], point[face[i][1]][1], point[face[i][1]][2],
        point[face[i][2]][0], point[face[i][2]][1], point[face[i][2]][2] 
    };*/
    double matrix[3][3] = {
        1, 0, 0,
        0, 1, 0,
        0, 0, 2,
        
    };
/*
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
*/
    double x = (matrix[1][1] - matrix[0][1]) * (matrix[2][2] - matrix[1][2]) - (matrix[1][2] - matrix[0][2]) * (matrix[2][1] - matrix[1][1]);
    double z = (matrix[1][0] - matrix[0][0]) * (matrix[2][1] - matrix[1][1]) - (matrix[1][1] - matrix[0][1]) * (matrix[2][0] - matrix[1][0]);
    double y = (matrix[1][2] - matrix[0][2]) * (matrix[2][0] - matrix[1][0]) - (matrix[1][0] - matrix[0][0]) * (matrix[2][2] - matrix[1][2]);

    cout << x << "\t" << y << "\t" << z << endl;

    return true;
}

void drawduck()
{
    glColor3f(255, 255, 255);
    for(int i=0;i<fnum;i++)
    {
        glBegin(GL_TRIANGLES);
        cout << "face " << i << endl;
        cout << point[face[i][0]][0] << "\t" << point[face[i][0]][1] << "\t" << point[face[i][0]][2] << endl;
        cout << point[face[i][1]][0] << "\t" << point[face[i][1]][1] << "\t" << point[face[i][1]][2] << endl;
        cout << point[face[i][2]][0] << "\t" << point[face[i][2]][1] << "\t" << point[face[i][2]][2] << endl;
        cout << "---------------------" << endl;
        if(visiable(i))
        {
            glVertex3i(point[face[i][0]][0], point[face[i][0]][1], point[face[i][0]][2]);
            glVertex3i(point[face[i][1]][0], point[face[i][1]][1], point[face[i][1]][2]);
            glVertex3i(point[face[i][2]][0], point[face[i][2]][1], point[face[i][2]][2]);
        }
//      glVertex3i(1000*rand()%1001, 1000*rand()%1001, 1000*rand()%1001);
//      glVertex3i(1000*rand()%1001, 1000*rand()%1001, 1000*rand()%1001);
//      glVertex3i(1000*rand()%1001, 1000*rand()%1001, 1000*rand()%1001);
        glEnd();
    }
    glFlush();

	return;
}


void prepareData()
{
	drawaxis();
	char * filename = "duck.off";
	read_off_data1(filename);

}




void display_duck()
{
    // glClearColor(0.0, 0.0, 0.0, 0.0);	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawaxis();
	drawduck();

}


void reshape_duck(int w, int h)
{
//    glClearColor(0.0, 0.0, 0.0, 0.0);
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
	glutInitWindowSize(TRUE_WINSIZE, TRUE_WINSIZE);

	glutCreateWindow(argv[0]);
	
	prepareData();
	init_duck();
	
	glutDisplayFunc(display_duck);
	glutReshapeFunc(reshape_duck);
	glutMainLoop();
	return 0;
}




