#pragma once

#include "Window.h"


GLFWwindow* _window;
GLuint		_VBO, _VAO;
GLfloat		_vertices[] = {
	-0.5f, -0.5f, 0.0f, // Left  
	0.5f, -0.5f, 0.0f, // Right 
	0.0f,  0.5f, 0.0f  // Top   
};

void initWindow(uint32_t width, uint32_t height, const char* title, bool fullscreen) {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	_window = glfwCreateWindow(width, height, title, fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
	glfwMakeContextCurrent(_window);

	glfwSetKeyCallback(_window, key_callback);
	
	glewExperimental = GL_TRUE;
	glewInit();

	glViewport(0, 0, width, height);
}

void registerVertices() {

	glGenVertexArrays(1, &_VAO);
	glGenBuffers(1, &_VBO);
	glBindVertexArray(_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), _vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)
}

void loop() {

	while (!glfwWindowShouldClose(_window))
	{
		glfwPollEvents();

		// Render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		useShaders();
		glBindVertexArray(_VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		glfwSwapBuffers(_window);
	}
}

void terminate() {

	glDeleteVertexArrays(1, &_VAO);
	glDeleteBuffers(1, &_VBO);
	glfwTerminate();
}

void key_callback( GLFWwindow* window, int key, int scancode, int action, int mode )
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}