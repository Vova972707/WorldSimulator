#pragma once

#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shaders/Shaders.h"


void initWindow(uint32_t width, uint32_t height, const char* title );
void registerVertices();
void loop();
void terminate();
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

