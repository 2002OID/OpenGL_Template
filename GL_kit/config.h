// ���� ����, ���� ������, �� ��� ������ �̰��� ���� 
// ������Ʈ�� �߿� ��� ���ϵ��� �� ������ ��� 
// ������ ��� ���ϵ��� �� ���Ͽ� ���� �������� ������ �ֱ� ������ �� ������ ���� �����ؼ��� �ȵ�.
#ifndef CONFIG_H
#define CONFIG_H
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4305)
#pragma warning(disable: 4326)
#pragma warning(disable: 4244)
#include <gl/glm/glm.hpp> //  �� include���� �ٸ����� �ű��� �� ��!
#include <gl/glm/ext.hpp> 
#include <gl/glm/gtc/matrix_transform.hpp>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <iostream>

#define WIDTH 800  
#define HEIGHT 800
#define X_POS 450
#define Y_POS 50

using namespace std;

#define MODEL_COUNT 1

enum bufferMode {  // ���� ���. ���� �ʱ�ȭ �� modeInit ���, EBO ������Ʈ �� modeUpdate ��� 
	modeInit, modeUpdate
};
enum projectionMode {  // ���� ���� / ���� ����. �⺻ ���� ���� 
	modeOrtho, modePers
};

#endif
