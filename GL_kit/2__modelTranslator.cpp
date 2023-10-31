// ¸ðµ¨ º¯È¯
#include "2__modelTranslator.h"
//#include "cube_ebo.cpp"

extern GLuint ID;
GLuint VAO[MODEL_COUNTS];

glm::mat4 view;
glm::mat4 projection;
glm::mat4 transformMatrix;
glm::vec3 cameraPos, cameraDirection, cameraUp;
unsigned int viewLocation, projectionLocation, transformLocation;

void finishTransform(int idx) {  // °Çµé ÇÊ¿ä ¾øÀ½
	viewLocation = glGetUniformLocation(ID, "viewTransform");
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &view[0][0]);
	projectionLocation = glGetUniformLocation(ID, "projectionTransform");
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, &projection[0][0]);
	transformLocation = glGetUniformLocation(ID, "transform");
	glUniformMatrix4fv(transformLocation, 1, GL_FALSE, value_ptr(transformMatrix));
	glBindVertexArray(VAO[idx]);
}

void setCamera() {  // Ä«¸Þ¶ó
	using namespace glm;
	view = mat4(1.0f);
	cameraPos = vec3(0.0f, 0.0f, 0.5f);
	cameraDirection = vec3(0.0f, 0.0f, 0.0f);
	cameraUp = vec3(0.0f, 1.0f, 0.0f);
	view = lookAt(cameraPos, cameraDirection, cameraUp);
}

void setProjection(int projectionMode) {  // Åõ¿µ
	using namespace glm;
	projection = mat4(1.0f);
	switch (projectionMode) {
	case modePers:
		projection = perspective(radians(45.0f), 1.0f, 0.1f, 1.0f);
		break;
	case modeOrtho:
		projection = ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
		break;
	}
}

void setTransform(int idx) {  // º¯È¯
	using namespace glm;
	transformMatrix = mat4(1.0f);
	switch (idx) {  // ¿©±â¿¡ º¯È¯ Ãß°¡
	case 0:
		break;
	}
}

void modelOutput(int idx) {  // ¿©±â¿¡¼­ ¸ðµ¨ ÃÖÁ¾ Ãâ·Â
	switch (idx) {
	case 0:
		//glDrawElements(GL_TRIANGLES, sizeof(), GL_UNSIGNED_INT, 0);
		break;
	}
}