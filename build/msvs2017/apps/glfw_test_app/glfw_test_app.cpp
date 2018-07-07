#include <glfw/glfw3.h>
#include <iostream>

int main(int argc, char** argv)
{
	// set error callback
	glfwSetErrorCallback([](int error, const char* description)	{
		std::cout << "Error: " << description << std::endl;
	});

	// init glfw
	if (!glfwInit())
		exit(EXIT_FAILURE);

	// select OpenGL version
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
	glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	// create window
	GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW OpenGL3", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	// set current context
	glfwMakeContextCurrent(window);

	// setup thescene ready for rendering
	int width = 0, height = 0;
	glfwGetFramebufferSize(window, &width, &height);

	// main loop
	double dt = 0, last_update_time = 0;
	while (!glfwWindowShouldClose(window))
	{
		// display and process events through callbacks
		glfwSwapBuffers(window);
		glfwPollEvents();

		// get frame time
		dt = glfwGetTime();
		if ((dt - last_update_time) > 0.2)
			last_update_time = dt;
	}

	// exit
	glfwTerminate();
	exit(EXIT_SUCCESS);
}