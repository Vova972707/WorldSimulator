#include "Shaders.h"


GLuint shaderProgram; // extern
GLuint vertexShader;
GLuint fragmentShader;

void initVertexShader(const char* filename) {

	FILE* f;
	fopen_s(&f, filename, "r");
	fseek(f, 0, SEEK_END);
	size_t shaderSize = ftell(f);
	GLchar* vertexShaderSource = (GLchar*)malloc(shaderSize);
	fseek(f, 0, SEEK_SET);
	fread(vertexShaderSource, shaderSize, 1, f);
	fclose(f);

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	// Check for compile time errors
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	free(vertexShaderSource);
}

void initFragmentShader(const char* filename) {

	FILE* f;
	fopen_s(&f, filename, "r");
	fseek(f, 0, SEEK_END);
	size_t shaderSize = ftell(f);
	GLchar* fragmentShaderSource = (GLchar*)malloc(shaderSize);
	fseek(f, 0, SEEK_SET);
	fread(fragmentShaderSource, shaderSize, 1, f);
	fclose(f);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	// Check for compile time errors
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	free(fragmentShaderSource);
}

void linkShaders() {

	GLint success;
	GLchar infoLog[512];
	// Link shaders
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// Check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
}

void releaseShaders() {
	
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void useShaders() {
	glUseProgram(shaderProgram);
}