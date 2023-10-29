#include "GL_header.h"

void setCamera() {
	using namespace glm;
	cameraPos = vec3(0.0f, 0.0f, 0.4f);
	cameraDirection = vec3(0.0f, 0.0f, 0.0f);
	cameraUp = vec3(0.0f, 1.0f, 0.0f);
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
