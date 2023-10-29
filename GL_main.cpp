#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <gl/glm/glm.hpp> 
#include <gl/glm/ext.hpp> 
#include <gl/glm/gtc/matrix_transform.hpp>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#define WIDTH 800  
#define HEIGHT 800
#define X_POS 450
#define Y_POS 50
#define MODEL_COUNTS 0 
using namespace std;

GLchar* vertexSource, * fragmentSource;
GLuint vertexShader, fragmentShader;
GLuint ID; 

enum bufferMode { 
	modeInit, modeUpdate
};
GLuint VAO[MODEL_COUNTS], EBO, VBO[2];

enum projectionMode {
	modeOrtho, modePers
}; int projectionMode = modePers;

glm::mat4 view = glm::mat4(1.0f);
glm::mat4 projection = glm::mat4(1.0f);;  
glm::mat4 transformMatrix = glm::mat4(1.0f);

glm::vec3 cameraPos, cameraDirection, cameraUp;  
unsigned int viewLocation, projectionLocation, transformLocation;

char* loadBuffer(const char* file) {
	FILE* fptr; long length; char* buf;

	fptr = fopen(file, "rb");
	if (!fptr) return NULL;

	fseek(fptr, 0, SEEK_END);
	length = ftell(fptr);
	buf = (char*)malloc(length + 1);
	fseek(fptr, 0, SEEK_SET);
	fread(buf, length, 1, fptr);
	fclose(fptr);
	buf[length] = 0;
	return buf;
}

void makeVertexShader() {
	vertexSource = loadBuffer("vertex.glsl");
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, (const GLchar**)&vertexSource, 0);
	glCompileShader(vertexShader);
	GLint result;
	GLchar errorLog[512];

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
	if (!result) {
		glGetShaderInfoLog(vertexShader, 512, NULL, errorLog);
		cerr << "ERROR: vertex shader err\n" << errorLog << endl;
		return;
	}
}

void makeFragProgram() {
	fragmentSource = loadBuffer("fragment.glsl");
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, (const GLchar**)&fragmentSource, 0);
	glCompileShader(fragmentShader);
	GLint result;
	GLchar errorLog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);

	if (!result) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, errorLog);
		cerr << "ERROR: fragment shader err\n" << errorLog << endl;
		return;
	}
}

void makeShaderProgram() {
	makeVertexShader();
	makeFragProgram();
	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glUseProgram(ID);
}

void setBuffer(int idx, int bufferMode) { 
	if (bufferMode == modeInit) {
		glGenVertexArrays(1, &VAO[idx]);
		glBindVertexArray(VAO[idx]);
		glGenBuffers(2, VBO);
	}

	if (bufferMode == modeInit || bufferMode == modeUpdate) {
		glBindBuffer(GL_ARRAY_BUFFER, VBO[0]); // vertex
		switch(idx) 
		{
			case 0:
				//glBufferData(GL_ARRAY_BUFFER, sizeof(), , GL_STATIC_DRAW);  
				break;
		}
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); //ebo
		switch(idx) 
		{
			case 0:
				//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(), , GL_STATIC_DRAW);  
				break;
		}
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, VBO[1]); //color
		switch(idx) 
		{
			case 0:
				//glBufferData(GL_ARRAY_BUFFER, sizeof(), , GL_STATIC_DRAW);  
				break;
		} 
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(1);
	}
}

void setCamera() {
	using namespace glm;
	cameraPos = 	  vec3(0.0f, 0.0f, 0.4f);
	cameraDirection = vec3(0.0f, 0.0f, 0.0f);
	cameraUp = 		  vec3(0.0f, 1.0f, 0.0f);
	view = lookAt(cameraPos, cameraDirection, cameraUp);
}

void setProjection(int projectionMode) {
	using namespace glm;
	switch (projectionMode) {
	case modePers:
		projection = perspective(radians(45.0f), 1.0f, 0.1f, 0.5f);  
		break;
	case modeOrtho: 
		projection = ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);  
		break;
	}
}

void setTransform(int idx) {
	using namespace glm;
	switch (idx) {
	case 0:
		break;
	}
}

void finishTransform(int idx) {
	viewLocation = glGetUniformLocation(ID, "viewTransform");  
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &view[0][0]);
	projectionLocation = glGetUniformLocation(ID, "projectionTransform");
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, &projection[0][0]);
	transformLocation = glGetUniformLocation(ID, "transform");
	glUniformMatrix4fv(transformLocation, 1, GL_FALSE, value_ptr(transformMatrix));
	glBindVertexArray(VAO[idx]);
}

void modelOutput(int idx) {
	switch (idx) {
	case 0:
		//glDrawElements(GL_TRIANGLES, sizeof(), GL_UNSIGNED_INT, 0);  
		break;
	}
}

void keyDown(unsigned char KEY, int x, int y) {
	switch (KEY) {
	case 27:  // ESC
		glutDestroyWindow(1);
		break;
	}
	glutPostRedisplay();
}

void keyUp(unsigned char KEY, int x, int y) {
	switch (KEY) {
		case 0:
			break;
	}
	glutPostRedisplay();
}

void timerOperation(int value) {
	
	glutTimerFunc(10, timerOperation, 1);
	glutPostRedisplay();
}

GLvoid displayOutput() {
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  glUseProgram(ID);
	
	setCamera();
	setProjection(projectionMode);
	
	for (int i = 0; i < MODEL_COUNTS; i++) {
		setTransform(i);
		finishTransform(i);	
		modelOutput(i);  
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
