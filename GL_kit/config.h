// ���� ������ �� �� ��� ������ �̰��� ���� 
// ������Ʈ�� �߿� ��� ���ϵ��� �� ������ ��� 
// ������ ��� ���ϵ��� �� ���Ͽ� ���� �������� ������ �ֱ� ������ �� ������ ���� �����ؼ��� �ȵ�.
#ifndef CONFIG_H
#define CONFIG_H
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4305)  // ��ǥ ���Ͽ��� �߻��ϴ� ��� ����
#include <gl/glm/glm.hpp> //  �� include���� �ٸ����� �ű��� �� ��!
#include <gl/glm/ext.hpp> 
#include <gl/glm/gtc/matrix_transform.hpp>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <iostream>
using namespace std;

#define MODEL_COUNT 1

enum bufferMode {  // ���� ���. ���� �ʱ�ȭ �� modeInit ���, EBO ������Ʈ �� modeUpdate ��� 
	modeInit, modeUpdate
};
enum projectionMode {  // ���� ���� / ���� ����. �⺻ ���� ���� 
	modeOrtho, modePers
};

#endif
