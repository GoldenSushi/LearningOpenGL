#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <vector>
#include <cmath>
#include "imGui\imgui.h"
#include "imGui\imgui_impl_glfw_gl3.h"

#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

#include "Shader.h"
#include "Camera.h"
#include "Curve.h"
#include "VertexArray.h"
#include "Texture.h"
#include "Error.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image\stb_image.h"

#define COS(x) cos(glm::radians(x))
#define SIN(x) sin(glm::radians(x))

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

void input(GLFWwindow *window, float &parameter1, float &parameter2);
void framebufferSizeCallback(GLFWwindow *, int, int);



int main()
{
	
	if (!glfwInit())
	{
		std::cout << "Could not initialize GLFW." << std::endl;
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "WINDOW", nullptr, nullptr);
	if (!window)
	{
		std::cout << "Could not initialize window." << std::endl;
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Could not initialize GLAD." << std::endl;
		return -1;
	}

	GLERR(glfwSetFramebufferSizeCallback(window, framebufferSizeCallback));
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);

	std::string filename = "res/Shaders/testShader.Shader";
	Shader myShader(filename);

	Point point0{ 0.0f, 0.0f };
	Point point1{ 0.2f, 0.5f };
	Point point2{ 0.3f, 0.1f };
	Point point3{ 0.5f, 0.3f };
	Point point4{ 0.4f, 0.5f };

	std::vector<Point> points1
	{
		point0,
		point1,
		point2,
		point3,
		point4
	};

	Curve chaikin(points1);
	unsigned int it = 10;
	chaikin.setIterations(it);
	points1 = chaikin.chaikinCurve();

	std::vector<unsigned int> indices;
	indices = chaikin.getIndices();

	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER ,vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * points1.size() * 2, points1.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	unsigned int ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);


	myShader.bind();

	while (!glfwWindowShouldClose(window))
	{
		GLERR(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
		GLERR(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

		int drawSize = ((points1.size()) - 1) * 2;

		glDrawElements(GL_LINE_STRIP, drawSize, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}


void input(GLFWwindow *window, float &parameter1, float &parameter2) {
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		parameter1 += 0.1f;
	}
	else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		parameter1 -= 0.1f;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		parameter2 += 0.1f;
	}
	else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		parameter2 -= 0.1f;
	}
}



void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}