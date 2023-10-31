// 모델 변환 
#include "translate.h"
//모델 좌표 cpp파일은 여기에 임포트 -> ex) #include "cube_ebo.cpp"

extern GLuint ID;
GLuint VAO[MODEL_COUNT];  // MODEL_COUNT는 config.h에 정의되어있음

glm::mat4 view;  // 건들 필요 없음
glm::mat4 projection;
glm::mat4 transformMatrix;
glm::vec3 cameraPos, cameraDirection, cameraUp;
unsigned int viewLocation, projectionLocation, transformLocation;

void finishTransform(int idx) {  // 변환 전달 
	viewLocation = glGetUniformLocation(ID, "viewTransform");
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &view[0][0]);
	projectionLocation = glGetUniformLocation(ID, "projectionTransform");
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, &projection[0][0]);
	transformLocation = glGetUniformLocation(ID, "transform");
	glUniformMatrix4fv(transformLocation, 1, GL_FALSE, value_ptr(transformMatrix));
	glBindVertexArray(VAO[idx]);
}

void setCamera() {  // 카메라 
	using namespace glm;
	view = mat4(1.0f);
	cameraPos = vec3(0.0f, 0.0f, 0.5f);
	cameraDirection = vec3(0.0f, 0.0f, 0.0f);
	cameraUp = vec3(0.0f, 1.0f, 0.0f);
	view = lookAt(cameraPos, cameraDirection, cameraUp);
}

void setProjection(int projectionMode) {  // 투영 
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

void setTransform(int idx) {  // 변환 
	using namespace glm;
	transformMatrix = mat4(1.0f);
	switch (idx) {  // 변환 추가 
	case 0:
		break;
	}
}

void modelOutput(int idx) {  // 모델 출력 
	switch (idx) {
	case 0:
		//glDrawElements(GL_TRIANGLES, sizeof(), GL_UNSIGNED_INT, 0);
		break;
	}
}
