#include <stdio.h>
#include <gl/glut.h>

/*
����������ʹ��OpenGL�򵥻�һ����ת��������
��ת�任����glRotatef
*/

//���ģʽ��0-������ģʽ����0˫����ģʽ
#define OUTPUT_MODE 1

//�Ƕ�
int angle = 0;

int xyz[3] = { 0, 0, 0 };

void display_rotate(void)
{
	//printf("xyz={%d,  %d,  %d\n}", xyz[0], xyz[1], xyz[2]);

	glClear(GL_COLOR_BUFFER_BIT);


	glLoadIdentity();
	glRotatef(angle, xyz[0], xyz[1], xyz[2]);

	glBegin(GL_TRIANGLES);
	{
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.5f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.5f, 0.0f);
	}
	glEnd();

	angle += 1;
	angle %= 360;

	if (OUTPUT_MODE == 0) {
		glFlush();//������GLUT_SINGLEʱʹ��
	}
	else {
		glutSwapBuffers();//��Ϊʹ�õ���˫����GLUT_DOUBLE�������������Ҫ��������Ż���ʾ
	}
}

//����
void keyboard_rotate(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'x':
	case 'X':
		xyz[0] = 1;
		xyz[1] = xyz[2] = 0;
		break;
	case 'y':
	case 'Y':
		xyz[1] = 1;
		xyz[0] = xyz[2] = 0;
		break;
	case 'z':
	case 'Z':
		xyz[2] = 1;
		xyz[0] = xyz[1] = 0;
		break;
	case 'a':
	case 'A':
		xyz[0] = xyz[1] = xyz[2] = 0;
		break;
	case 'b':
	case 'B':
		xyz[0] = xyz[1] = xyz[2] = 1;
		break;
	default:
		break;
	}
	printf("��ǰ��%c����ת\n", key);
	glutPostRedisplay();
}

void reshape_rotate(int w, int h)
{
	int offset = 50;
	int dis = (w > h ? h : w) - offset * 2;

	//������ʾ������Ļ�Ĵ�С
	glViewport(offset, offset, (GLsizei)dis, (GLsizei)dis);
	printf("reshape: w=%d, h=%d, dis=%d\n", w, h, dis);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1.5, 1.5, -1.5, 1.5, 0, 10);
	//gluOrtho2D(-1.5, 1.5, -1.5, 1.5);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main_rotate(int argc, char *argv[])
{
	printf("��ͨ������xyzab����ͼ����תԭ��/��\n");
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | (OUTPUT_MODE == 0 ? GLUT_SINGLE : GLUT_DOUBLE));
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);

	glutCreateWindow("��һ�� OpenGL ����");

	glutDisplayFunc(&display_rotate);
	//glutIdleFunc(display_rotate);  //���ò��ϵ�����ʾ����
	glutReshapeFunc(reshape_rotate);
	glutKeyboardFunc(&keyboard_rotate);
	glutMainLoop();

	return 0;
}