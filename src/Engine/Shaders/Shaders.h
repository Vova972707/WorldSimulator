#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


void initVertexShader(const char* filename);
void initFragmentShader(const char* filename);
void linkShaders();
void releaseShaders();
void useShaders();