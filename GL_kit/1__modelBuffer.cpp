// ¸ðµ¨ ¹öÆÛ
#include "1__modelBuffer.h"
//#include "cube_ebo.cpp"

extern GLuint VAO[MODEL_COUNTS];
GLuint EBO, VBO[2];

void setBuffer(int idx, int bufferMode) {
	if (bufferMode == modeInit) {
		glGenVertexArrays(1, &VAO[idx]);
		glBindVertexArray(VAO[idx]);
		glGenBuffers(2, VBO);
	}

	if (bufferMode == modeInit || bufferMode == modeUpdate) {
		glBindBuffer(GL_ARRAY_BUFFER, VBO[0]); // vertex
		switch (idx)
		{
		case 0:
			//glBufferData(GL_ARRAY_BUFFER, sizeof(), , GL_STATIC_DRAW);
			break;
		}
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);


		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); //ebo
		switch (idx)
		{
		case 0:
			//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(), , GL_STATIC_DRAW);
			break;
		}
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
		glEnableVertexAttribArray(0);


		glBindBuffer(GL_ARRAY_BUFFER, VBO[1]); //color
		switch (idx)
		{
		case 0:
			//glBufferData(GL_ARRAY_BUFFER, sizeof(), , GL_STATIC_DRAW);
			break;
		}
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(1);
	}
}