// 모델 버퍼 
#include "buffer.h"
//모델 좌표 cpp파일은 여기에 임포트 -> ex) #include "cube_ebo.cpp"

extern GLuint VAO[MODEL_COUNT];  // MODEL_COUNT는 config.h에 정의되어있음
GLuint EBO, VBO[2];

void vertexInput(int idx) {  // vertex
	switch (idx) {
	case 0:
		//glBufferData(GL_ARRAY_BUFFER, sizeof(), , GL_STATIC_DRAW);
		break;
	}
}

void eboInput(int idx) {  // ebo
	switch (idx) {
	case 0:
		//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(), , GL_STATIC_DRAW);
		break;
	}
}

void colorInput(int idx) {  // color
	switch (idx){
	case 0:
		//glBufferData(GL_ARRAY_BUFFER, sizeof(), , GL_STATIC_DRAW);
		break;
	}
}

void setBuffer(int idx, int bufferMode) {  // 반드시 케이스 문 안쪽에만 코드를 작성해야 함. 외부에 추가 작성 시 제대로 동작하지 않을 수 있음.
	if (bufferMode == modeInit) {
		glGenVertexArrays(1, &VAO[idx]);
		glBindVertexArray(VAO[idx]);
		glGenBuffers(2, VBO);
	}

	if (bufferMode == modeInit || bufferMode == modeUpdate) {
		glBindBuffer(GL_ARRAY_BUFFER, VBO[0]); // vertex
		vertexInput(idx);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); //ebo
		eboInput(idx);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
		glEnableVertexAttribArray(0);
		
		glBindBuffer(GL_ARRAY_BUFFER, VBO[1]); //color
		colorInput(idx);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(1);
	}
}
