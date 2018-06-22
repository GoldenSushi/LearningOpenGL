//#include <glad\glad.h>
//#include <GLFW\glfw3.h>
//#include "imGui\imgui.h"
//#include "imGui\imgui_impl_glfw_gl3.h"
//
//#include "glm\glm.hpp"
//#include "glm\gtc\matrix_transform.hpp"
//#include "glm\gtc\type_ptr.hpp"
//
//#include "Shader.h"
//#include "Camera.h"
//#include "VertexArray.h"
//#include "Texture.h"
//#include "Error.h"
//
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image\stb_image.h"
//
//#define COS(x) cos(glm::radians(x))
//#define SIN(x) sin(glm::radians(x))
//
//const int SCREEN_WIDTH = 1280;
//const int SCREEN_HEIGHT = 720;
//
//void framebufferSizeCallback(GLFWwindow *, int, int);
//
//int main()
//{
//
//	if (!glfwInit())
//	{
//		std::cout << "Could not initialize GLFW." << std::endl;
//		return -1;
//	}
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow *window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "WINDOW", nullptr, nullptr);
//	if (!window)
//	{
//		std::cout << "Could not initialize window." << std::endl;
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	ImGui::CreateContext();
//	ImGui_ImplGlfwGL3_Init(window, true);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Could not initialize GLAD." << std::endl;
//		return -1;
//	}
//
//	GLERR(glfwSetFramebufferSizeCallback(window, framebufferSizeCallback));
//
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glEnable(GL_DEPTH_TEST);
//
//	std::string filename = "res/Shaders/testShader.Shader";
//	Shader myShader(filename);
//
//
//	struct Point
//	{
//		float x;
//		float y;
//	};
//
//	Point point1{ 0.2f, 0.5f };
//	Point point2{ 0.4f, 0.5f };
//	Point point3{ 0.4f, 0.2f };
//	Point point4{ 0.6f, 0.2f };
//
//	float points[8]
//	{
//		point1.x, point1.y,
//		point2.x, point2.y,
//		point3.x, point3.y,
//		point4.x, point4.y
//	};
//
//	unsigned int index[4]
//	{
//		0, 1, 2, 3
//	};
//
//	unsigned int vao;
//	glGenVertexArrays(1, &vao);
//	glBindVertexArray(vao);
//
//	unsigned int vbo;
//	glGenBuffers(GL_ARRAY_BUFFER, &vbo);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	unsigned int ebo;
//	glGenBuffers(GL_ELEMENT_ARRAY_BUFFER, &ebo);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
//
//
//	myShader.bind();
//
//
//	//	myShader.bind();
//	//	myShader.setUniform1i("u_texture", 0);
//	//	myShader.setUniform1i("u_texture2", 1);
//	//
//	//	std::string texturePath = "src/container.jpg";
//	//	std::string texture2Path = "src/awesomeface.png";
//	//
//	//
//	//	Texture texture(texturePath);
//	//	Texture texture2(texture2Path, RGBA);
//	//	texture.bind(0);
//	//	texture2.bind(1);
//	//
//	//
//	//	float positions[20]
//	//	{
//	//		0.5f, -0.5f, 0.0f,		1.0f, 0.0f,	//0
//	//		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f,	//1
//	//		0.5f, 0.5f, 0.0f,		1.0f, 1.0f, //2
//	//		-0.5, 0.5f, 0.0f,		0.0f, 1.0f	//3
//	//	};
//	//
//	//	unsigned int index[6]
//	//	{
//	//		0, 1, 2,
//	//		2, 3, 1,
//	//	};
//	//
//	//	float vertices[] = {
//	//    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//	//     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//	//     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	//     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	//    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//	//    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//	//
//	//    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	//     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	//     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//	//     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//	//    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//	//    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	//
//	//    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	//    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	//    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	//    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	//    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	//    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	//
//	//     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	//     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	//     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	//     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	//     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	//     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	//
//	//    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	//     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//	//     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	//     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	//    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	//    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	//
//	//    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//	//     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	//     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	//     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	//    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//	//    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//	//};
//	//
//	struct Colors
//	{
//		float red;
//		float blue;
//		float green;
//		float alpha;
//	};
//
//	Colors colors;
//	//
//	//
//	//	VertexBuffer vb(vertices, 180, VarFLOAT);
//	//	vb.bind();
//	//	ElementBuffer eb(index, 6, VarUINT);
//	//	eb.bind();
//	//
//	//	VertexArray va(vb, eb);
//	//	va.addAttribf(3);
//	//	va.addAttribf(2);
//	//	va.bind();
//	//
//	//	float count = 0.0f;
//	//	float xCoord = 0.0f;
//	//	float yCoord = 0.0f;
//	//	float zCoord= -5.0f;
//	//	float camX= 0.0f;
//	//	float camY = 0.0f;
//	//	float camZ = 5.0f;
//	//	float camDirX = 0.0f;
//	//	float camDirY = 0.0f;
//	//	float camDirZ = -1.0f;
//	//	float rot = 270.0f;
//	//
//	//
//
//	//Camera camera(window, glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//
//	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
//
//	while (!glfwWindowShouldClose(window))
//	{
//		GLERR(glClearColor(clear_color.x, clear_color.y, clear_color.z, 1.0f));
//		GLERR(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
//
//		glDrawElements(GL_LINE, 4, GL_UNSIGNED_INT, 0);
//
//		//float seed = (float)glfwGetTime();
//
//		//colors.red = 0.5f + 0.25f * sin(glm::radians((float)glfwGetTime() * 500));
//		//colors.blue = 0.5f + 0.25f * cos(glm::radians((float)glfwGetTime() * 500));
//		//colors.green = 0.5f + 0.25f * sin(glm::radians((float)glfwGetTime() * 500));
//		//colors.alpha = 0.85f + (0.15f * cos(glm::radians((float)glfwGetTime() * 500)));
//
//
//		//glm::mat3 rotation = glm::mat3(glm::vec3(COS(rot), 0.0f, SIN(rot)), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(COS(rot), 0.0f, -SIN(rot)));
//
//		//count = (seed * 50.0f);
//		//for (int i = 0; i <= 360; i += 60)
//		//{
//		//	xCoord = 2.0f * (cos(glm::radians((float)i + count)));
//		//	yCoord = 2.0f * (sin(glm::radians((float)i + count)));
//		//	glm::mat4 model = glm::mat4(1.0f);
//		//	model = glm::translate(model, glm::vec3(xCoord, yCoord, zCoord));
//		//	model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(1.0f, 1.0f, 0.0f));
//		//	glm::mat4 view(1.0f);
//		//	view = camera.update();
//		//	//view = lookAt(camera.getCameraPos(), camera.getCameraPos() + glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//		//	glm::mat4 projection(1.0f);
//		//	projection = glm::perspective(glm::radians(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f, 100.0f);
//		//	glm::mat4 mvp = projection * view * model;
//
//		//	glUniformMatrix4fv(glGetUniformLocation(myShader.getShaderID(), "mvp"), 1, GL_FALSE, glm::value_ptr(mvp));
//		//	glDrawArrays(GL_TRIANGLES, 0, 36);
//		//	//glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr);
//		//}
//
//		//camera.walk();
//
//		//ImGui_ImplGlfwGL3_NewFrame();
//
//		//{
//		//	static float f = 0.0f;
//		//	static int counter = 0;
//		//	ImGui::Text("PARTY BOX");
//		//	ImGui::ColorEdit3("clear color", (float*)&colors); // Edit 3 floats representing a color
//
//		//	if (ImGui::Button("Button"))                            // Buttons return true when clicked (NB: most widgets return true when edited/activated)
//		//		counter++;
//		//	ImGui::SameLine();
//		//	ImGui::Text("counter = %d", counter);
//
//		//	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
//		//}
//
//		//glUniform4f(glGetUniformLocation(myShader.getShaderID(), "color"), colors.red, colors.blue, colors.green, colors.alpha);
//
//		//	ImGui::Render();
//		//	ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
//
//		//	glfwSwapBuffers(window);
//		//	glfwPollEvents();
//	}
//
//	//ImGui_ImplGlfwGL3_Shutdown();
//	//ImGui::DestroyContext();
//
//	glfwDestroyWindow(window);
//	glfwTerminate();
//
//	return 0;
//}
//
//void framebufferSizeCallback(GLFWwindow *window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}