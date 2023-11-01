#include "config.h"  // �߿� ��� ����
#include "shader.h"  // ���̴� ����
#include "buffer.h"  // ����
#include "translate.h"  // ��ȯ
#include "gl_func.h"  // GL ��� �Լ�

GLuint ID;
int projectionMode = modePers;  // ��������/��������, �⺻ �������� ���, modeOrtho�� ���� �� �˾Ƽ� �ٲ�

GLvoid displayOutput() {
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
	glUseProgram(ID);
	
	setCamera(); // �� �κ��� ���⼭ �ǵ� �ʿ� ����
	setProjection(projectionMode); // �� �κ��� ���⼭ �ǵ� �ʿ� ����

	// MODEL_COUNT�� config.h�� ���ǵǾ�����
	for (int i = 0; i < MODEL_COUNT; i++) {  // MODEL_COUNT ��ŭ �ݺ����� ���� ��ȯ�� ��� �ݺ�
		setTransform(i);  // ��ȯ ����
		finishTransform(i); // ��ȯ�� glsl�� ����
		modelOutput(i);  // ���� ���, 3�� �Լ� ��� modelOutput.cpp�� ����
	}
	
	glutSwapBuffers();
}

GLvoid displayReshape(int w, int h) {
	glViewport(0, 0, w, h);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GL_MULTISAMPLE);
	glutInitWindowPosition(X_POS, Y_POS);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("OpenGL");
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		cerr << "Unable to initialize GLEW" << endl;  exit(EXIT_FAILURE);
	}
	else cout << "GLEW Initialized" << endl;
		
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_MULTISAMPLE);
	makeShaderProgram();

	// MODEL_COUNT�� config.h�� ���ǵǾ�����
	for(int i = 0; i < MODEL_COUNT; i ++)  // MODEL_COUNT ��ŭ ���� �ʱ�ȭ
		setBuffer(i, modeInit);  // modelBuffer.cpp�� ����
	
	glutDisplayFunc(displayOutput);
	glutReshapeFunc(displayReshape);
	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);
	glutTimerFunc(10, timerOperation, 1);
	glutMainLoop();
}
