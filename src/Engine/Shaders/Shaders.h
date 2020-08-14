#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


void initVertexShader(const char* filepath);
void initFragmentShader(const char* filepath);
void linkShaders();
void releaseShaders();
void useShaders();