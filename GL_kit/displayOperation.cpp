#include "GL_header.h"

void modelOutput(int idx) {
	switch (idx) {
	case 0:
		//glDrawElements(GL_TRIANGLES, sizeof(), GL_UNSIGNED_INT, 0);  
		break;
	}
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
