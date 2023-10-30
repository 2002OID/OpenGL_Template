//  버퍼 초기화
#ifndef MODEL_BUFFER_H
#define MODEL_BUFFER_H
#include <gl/glm/glm.hpp> 
#include <gl/glm/ext.hpp> 
#include <gl/glm/gtc/matrix_transform.hpp>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include "4__modelCounts.h"
#include "3__modeEnum.h"

void setBuffer(int idx, int bufferMode);

#endif