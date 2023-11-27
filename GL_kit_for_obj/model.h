#pragma once
#include "config.h"

struct Vertex {
    vec3 position;
    vec3 normal;
    vec2 texCoords; // 추가된 부분
 };

GLuint loadObj(const char* filename, vector<Vertex>& vertices);

extern vector<Vertex> model_1;
extern GLuint vertexCount_1;
