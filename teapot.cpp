
#include <GL/glut.h>

void teapot_init()
{		
	glEnable(GL_DEPTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH);


	GLfloat position[] = {1.0, 1.0, 1.0, 0.0}; //设置 光源的位置
	glLightfv(GL_LIGHT0, GL_POSITION, position);


	GLfloat ambient[] = {0.0, 0.0, 0.0, 0.0}; // 环境光参数
	GLfloat diffuse[] = {1.0, 0.0, 0.0, 1.0};//{0.5, 0.5, 0.5, 1.0}; //散射光属性
	GLfloat specular[] = {1.0, 1.0, 1.0, 0}; //镜面反射指数
	GLfloat shininess = 20.0; // 高光指数

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
	
}

void teapot_display()
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// glClearColor(0, 0, 0, 0);
	glColor3f(1.0, 0, 0);   // ---------------------------------颜色    不好用
	// gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0); //-----------------------------------视角   不好用
	glRotatef(60, 1, 0, 0);//改变茶壶姿态
	glTranslatef(0.25, -0.8f, 0);//改变茶壶的位置

	//glNewList(1, GL_COMPILE);
	// ==============================================================
	
	
	//glutWireTeapot(0.5);
	glutSolidTeapot(0.5);

	// ==============================================================
	//glEndList();
	//glCallList(1);

	glFlush();
}

void teapot_reshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, -1.0, -1.0, -1.0, -1.0, -1.0); // 窗口显示参数
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
}

int main_teapot(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);  //窗口显示参数                    
	glutInitWindowSize(300, 300); // 窗口显示参数 
	glutCreateWindow(argv[0]);
	glClearColor(255, 255, 255, 0);  // 清空背景色

	//---------------------------------------
	teapot_init();
	glutReshapeFunc(teapot_reshape);
	glutDisplayFunc(teapot_display);
	glutMainLoop();



	return 0;
}


