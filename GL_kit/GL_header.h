#pragma once
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
#define MODEL_COUNTS 1 
using namespace std;

static GLchar* vertexSource, * fragmentSource;
static GLuint vertexShader, fragmentShader;
static GLuint ID;

enum bufferMode {
	modeInit, modeUpdate
};
static GLuint VAO[MODEL_COUNTS], EBO, VBO[2];

enum projectionMode {
	modeOrtho, modePers
}; static int projectionMode = modePers;

static glm::mat4 view = glm::mat4(1.0f);
static glm::mat4 projection = glm::mat4(1.0f);;
static glm::mat4 transformMatrix = glm::mat4(1.0f);
static glm::vec3 cameraPos, cameraDirection, cameraUp;
static unsigned int viewLocation, projectionLocation, transformLocation;

char* loadBuffer(const char* file);
void makeVertexShader();
void makeFragProgram();
void makeShaderProgram();

void setBuffer(int idx, int bufferMode);
void setCamera();
void setProjection(int projectionMode);
void setTransform(int idx);
void finishTransform(int idx);
void modelOutput(int idx);

void keyDown(unsigned char KEY, int x, int y);
void keyUp(unsigned char KEY, int x, int y);
void timerOperation(int value);

GLvoid displayOutput();
GLvoid displayReshape(int w, int h);
