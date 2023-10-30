// ≈∏¿Ã∏”
#include "GL_func.h"

void timerOperation(int value) {

	glutTimerFunc(10, timerOperation, 1);
	glutPostRedisplay();
}