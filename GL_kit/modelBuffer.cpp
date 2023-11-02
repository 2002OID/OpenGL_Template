// �� ���� 
#include "buffer.h"
//�� ��ǥ cpp������ ���⿡ ����Ʈ -> ex) #include "cube_ebo.cpp"

extern GLuint VAO[MODEL_COUNT];  // MODEL_COUNT�� config.h�� ���ǵǾ�����
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

void setBuffer(int idx, int bufferMode) {  // �ݵ�� ���̽� �� ���ʿ��� �ڵ带 �ۼ��ؾ� ��. �ܺο� �߰� �ۼ� �� ����� �������� ���� �� ����.
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
