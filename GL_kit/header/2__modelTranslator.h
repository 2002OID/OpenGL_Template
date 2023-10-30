// ¸ðµ¨ º¯È¯
#ifndef MODEL_TRANSLATOR_H
#define MODEL_TRANSLATOR_H
#include <gl/glm/glm.hpp> 
#include <gl/glm/ext.hpp> 
#include <gl/glm/gtc/matrix_transform.hpp>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include "4__modelCOUNTS.h"
#include "3__modeEnum.h"

void setCamera();
void setProjection(int projectionMode);
void setTransform(int idx);
void finishTransform(int idx);
void modelOutput(int idx);

#endif
