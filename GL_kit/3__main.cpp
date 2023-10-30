#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <gl/glm/glm.hpp> 
#include <gl/glm/ext.hpp> 
#include <gl/glm/gtc/matrix_transform.hpp>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include "0__shaderLoader.h"
#include "1__modelBuffer.h"
#include "2__modelTranslator.h"
#include "3__modeEnum.h"
#include "4__modelCounts.h"
#include "GL_func.h"
#define WIDTH 800  
#define HEIGHT 800
#define X_POS 450
#define Y_POS 50
using namespace std;

GLuint ID;
int projectionMode = modePers;  // ��������/��������, �⺻ �������� ���, modeOrtho�� ���� �� �˾Ƽ� �ٲ�

GLvoid displayOutput() {
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  glUseProgram(ID);
	
	setCamera();
	setProjection(projectionMode); // �� �κ��� ���⼭ �ǵ� �ʿ� ����

	for (int i = 0; i < MODEL_COUNTS; i++) {
		setTransform(i);  // ��ȯ ����
		finishTransform(i); // ��ȯ�� ���ؽ�glsl�� ����
		modelOutput(i);  // ���� ���, 3�� �Լ� ��� 2__modelTranslator.cpp�� ����
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
	for(int i = 0; i < MODEL_COUNTS; i ++)
		setBuffer(i, modeInit);
	
	glutDisplayFunc(displayOutput);
	glutReshapeFunc(displayReshape);
	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);
	glutTimerFunc(10, timerOperation, 1);
	glutMainLoop();
}
