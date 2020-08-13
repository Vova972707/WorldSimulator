#include "Engine\Window.h"


int main()
{
	initWindow(800, 600, "WorldSimulator");
	initVertexShader("src\\Engine\\Shaders\\VertexShader.txt");
	initFragmentShader("src\\Engine\\Shaders\\FragmentShader.txt");
	linkShaders();
	releaseShaders();

	registerVertices();
	loop();
	terminate();
	return 0;
}
