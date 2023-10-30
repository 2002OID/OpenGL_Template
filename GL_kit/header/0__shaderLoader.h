//  셰이더 프로그램 생성
#ifndef SHADER_LOADER_H
#define SHADER_LOADER_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <gl/glm/glm.hpp> 
#include <gl/glm/ext.hpp> 
#include <gl/glm/gtc/matrix_transform.hpp>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
using namespace std;

char* loadBuffer(const char* file);
void makeShaderProgram();

#endif
