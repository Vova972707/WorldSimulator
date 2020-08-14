#include "Shaders.h"

GLuint _shaderProgram; // extern
GLuint _vertexShader;
GLuint _fragmentShader;

void initVertexShader(const char* filepath) {

	FILE* f;
	fopen_s(&f, filepath, "r");
	fseek(f, 0, SEEK_END);
	size_t shaderSize = ftell(f);
	GLchar* vertexShaderSource = (GLchar*)malloc(shaderSize);
	fseek(f, 0, SEEK_SET);
	fread(vertexShaderSource, shaderSize, 1, f);
	fclose(f);

	_vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(_vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(_vertexShader);
	// Check for compile time errors
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(_vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(_vertexShader, 512, NULL, infoLog);
		printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
	}

	free(vertexShaderSource);
}

void initFragmentShader(const char* filepath) {

	FILE* f;
	fopen_s(&f, filepath, "r");
	fseek(f, 0, SEEK_END);
	size_t shaderSize = ftell(f);
	GLchar* fragmentShaderSource = (GLchar*)malloc(shaderSize);
	fseek(f, 0, SEEK_SET);
	fread(fragmentShaderSource, shaderSize, 1, f);
	fclose(f);

	_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(_fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(_fragmentShader);
	// Check for compile time errors
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(_fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(_fragmentShader, 512, NULL, infoLog);
		printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
	}

	free(fragmentShaderSource);
}

void linkShaders() {

	GLint success;
	GLchar infoLog[512];
	// Link shaders
	_shaderProgram = glCreateProgram();
	glAttachShader(_shaderProgram, _vertexShader);
	glAttachShader(_shaderProgram, _fragmentShader);
	glLinkProgram(_shaderProgram);
	// Check for linking errors
	glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(_shaderProgram, 512, NULL, infoLog);
		printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s\n", infoLog);
	}
}

void releaseShaders() {
	
	glDeleteShader(_vertexShader);
	glDeleteShader(_fragmentShader);
}

void useShaders() {
	glUseProgram(_shaderProgram);
}