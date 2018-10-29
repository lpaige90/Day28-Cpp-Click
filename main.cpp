#include "click.h"
#include <memory>
#include <iostream>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glfw3.lib")

static void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_LEFT && GLFW_PRESS) {
		glfwGetCursorPos(window, &mouseX, &mouseY);
		mouseX = ((mouseX - 800.0 / 2.0) / 400.0);
		mouseY = (-(mouseY - 600.0 / 2.0) / 300.0);
	}
}

int main() {
	GLFWwindow* window;

	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(800, 600, "Move Me", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	int width;
	int height;
	float ratio;

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	std::unique_ptr<Circle> circle(new Circle(0.3f, 0.6f, 1.0f, 0.8f));

	while (!glfwWindowShouldClose(window))
	{
		glfwGetFramebufferSize(window, &width, &height);

		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);//Buffer enabled for color writing

		ratio = (float)width / (float)height;

		glMatrixMode(GL_PROJECTION);//Projection matrix stack
		glLoadIdentity();
		glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);//Projection

		glMatrixMode(GL_MODELVIEW);//Modelview matrix stack
		glLoadIdentity();

		circle->moveCircle(mouseX, mouseY);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}