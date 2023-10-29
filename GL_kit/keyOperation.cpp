#include "GL_header.h"

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
