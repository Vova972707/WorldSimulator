#include "Engine\Window.h"

int main()
{
	initWindow(1280, 720, "WorldSimulator", false);
	initVertexShader("src\\Engine\\Shaders\\VertexShader.vert");
	initFragmentShader("src\\Engine\\Shaders\\FragmentShader.fraq");
	linkShaders();
	releaseShaders();

	registerVertices();
	loop();
	terminate();
	return 0;
}
