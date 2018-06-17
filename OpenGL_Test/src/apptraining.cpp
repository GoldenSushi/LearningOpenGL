//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <fstream>
//#include <sstream>
//#include <string>
//#include <iostream>
//#include <cassert>
//
//#if defined(OPENGL_DEBUG)
//#define ERR(x) clearError(); x; getError(#x, __FILE__, __LINE__); __debugbreak();
//#endif
//
//
//window util
//void framebufferSizeCallback(GLFWwindow *, int, int);
//void escapeWindow(GLFWwindow *window);
//int compileShader(GLenum type, std::string &code);
//int createProgram(std::string &vertexCode, std::string &fragmentCode);
//
//error handling
//void clearError();
//bool getError(const char* function, const char* file, int line);
//
//shader util
//enum ShaderType
//{
//	NONE = -1, VERTEX, FRAGMENT
//};
//struct ShaderFile
//{
//	std::string vertexShader;
//	std::string fragmentShader;
//};
//ShaderFile shaderParser(std::string &filename);
//
//unsigned int SCREEN_WIDTH = 800;
//unsigned int SCREEN_HEIGHT = 600;
//
//int main()
//{
//	if (!glfwInit())
//	{
//		std::cout << "Could not initialize GLFW." << std::endl;
//		return -1;
//	}
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow *window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window", nullptr, nullptr);
//	glfwMakeContextCurrent(window);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Could not initialize GLAD." << std::endl;
//		return -1;
//	}
//
//	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
//
//	float points[]
//	{	//positions		//colors
//		0.0f, 0.0f,		 1.0f, 0.0f, 0.0f, 1.0f,
//		0.5f, -0.5f,	 0.0f, 1.0f, 0.0f, 1.0f,
//		-0.5f, -0.5f,	 0.0f, 0.0f, 1.0f, 1.0f,
//		0.0f, 0.5f,		 1.0f, 0.0f, 0.0f, 1.0f
//	};
//
//	unsigned short triangleIndex[3] =
//	{
//		1, 2, 3
//	};
//
//	unsigned int VAO;
//	unsigned int VBO;
//	unsigned int EBO;
//
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(2 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangleIndex), triangleIndex, GL_STATIC_DRAW);
//
//
//	std::string filename = "res/Shaders/testShader.Shader";
//	ShaderFile file = shaderParser(filename);
//
//	std::cout << "Vertex Shader:\n" << file.vertexShader << std::endl
//	<< "Fragment Shader:\n" << file.fragmentShader << std::endl;
//
//	int program = createProgram(file.vertexShader, file.fragmentShader);
//
//	glUseProgram(program);
//
//
//
//	while (!glfwWindowShouldClose(window))
//	{
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//
//		ASSERT(glDrawElements(GL_TRIANGLES, 3, GL_INT, 0));
//
//		glfwSwapBuffers(window);
//		escapeWindow(window);
//		glfwPollEvents();
//	}
//
//	glDeleteProgram(program);
//
//	glfwTerminate();
//
//	return 0;
//}
//
//
//void framebufferSizeCallback(GLFWwindow *window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//void escapeWindow(GLFWwindow *window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE))
//	{
//		glfwSetWindowShouldClose(window, true);
//	}
//}
//
//ShaderFile shaderParser(std::string &filename)
//{
//	std::ifstream shaderFile(filename);
//	if (!shaderFile)
//	{
//		std::cout << "[Could not open file] : " << filename << "." << std::endl;
//		return { nullptr, nullptr };
//	}
//
//	ShaderType type = ShaderType::VERTEX;
//	std::stringstream ss[2];
//	std::string line;
//
//	while (std::getline(shaderFile, line))
//	{
//		if (line.find("#shader") != std::string::npos)
//		{
//			if (line.find("vertex") != std::string::npos) { type = ShaderType::VERTEX; }
//			else if (line.find("fragment") != std::string::npos) { type = ShaderType::FRAGMENT; }
//		}
//		else
//		{
//			if ((int)type >= 0) { ss[(int)type] << line << '\n'; }
//			else std::cout << "Problem in reading file" << std::endl
//				<< "File name : " << filename << std::endl
//				<< "Code line : " << __LINE__ << std::endl;
//		}
//	}
//	return { ss[0].str(), ss[1].str() };
//}
//
//int compileShader(GLenum type, std::string &code)
//{
//	unsigned int shader = glCreateShader(type);
//	const char *source = code.c_str();
//	glShaderSource(shader, 1, &source, nullptr);
//	glCompileShader(shader);
//
//	int result;
//	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
//	if (!result)
//	{
//		int length;
//		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
//		char *log = (char*)alloca(length * sizeof(char));
//		glGetShaderInfoLog(shader, length, nullptr, log);
//		std::cout << "[SHADER COMPILE ERROR] :" << std::endl
//			<< log << std::endl;
//		return 0;
//	}
//	return shader;
//}
//
//int createProgram(std::string &vertexCode, std::string &fragmentCode)
//{
//	unsigned int program = glCreateProgram();
//	unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexCode);
//	unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentCode);
//	glAttachShader(program, vertexShader);
//	glAttachShader(program, fragmentShader);
//	glLinkProgram(program);
//	glValidateProgram(program);
//
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	int resultVal;
//	int resultLink;
//	glGetProgramiv(program, GL_LINK_STATUS, &resultLink);
//	glGetProgramiv(program, GL_VALIDATE_STATUS, &resultVal);
//
//	if (!resultVal || !resultLink)
//	{
//		int length;
//		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
//		char *log = (char*)alloca(length * sizeof(char));
//		glGetProgramInfoLog(program, length, nullptr, log);
//		std::cout << "[PROGRAM ERROR] :" << std::endl
//			<< log << std::endl;
//		return 0;
//	}
//	return program;
//}
//
//void clearError()
//{
//	while (glGetError()) {}
//}
//
//bool getError(const char* function, const char* file, int line)
//{
//	while (unsigned int error = glGetError())
//	{
//		std::cout << "[ERROR] : " << error << std::endl
//			<< "[AT FUNCTION] : " << function << std::endl
//			<< "[LINE] : " << line << std::endl
//			<< "[FILE] : " << file << std::endl;
//		return true;
//	}
//	return false;
//}
