#include "Engine\Window.h"


int main()
{
	initWindow(800, 600, "WorldSimulator");
	initVertexShader("src\\Engine\\Shaders\\VertexShader.vert");
	initFragmentShader("src\\Engine\\Shaders\\FragmentShader.fraq");
	linkShaders();
	releaseShaders();

	registerVertices();
	loop();
	terminate();
	return 0;
}
