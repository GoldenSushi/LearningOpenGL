#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "Error.h"

Shader::Shader(std::string &filename) :
	m_ShaderID(0)
{
	createShader(filename);
}

Shader::~Shader()
{
	GLERR(glDeleteShader(m_ShaderID));
}

void Shader::bind() const
{
	if (m_ShaderID == 0)
	{
		std::cout << "[WARNING] : Binding shader with ID 0." << std::endl;
	}
	GLERR(glUseProgram(m_ShaderID));
}

void Shader::setUniform1i(const std::string & name, unsigned int v0)
{
	GLERR(glUniform1i(glGetUniformLocation(m_ShaderID, name.c_str()), v0));
}

void Shader::setUniform4f(const std::string &name, float v0, float v1, float v2, float v3)
{
	glUniform4f(glGetUniformLocation(m_ShaderID, name.c_str()), v0, v1, v2, v3);
}


int Shader::compileShader(int type, std::string &sourceCode) const
{
	const char* source = sourceCode.c_str();
	unsigned int shader = glCreateShader(type);
	GLERR(glShaderSource(shader, 1, &source, nullptr));
	GLERR(glCompileShader(shader));

	int result;
	GLERR(glGetShaderiv(shader, GL_COMPILE_STATUS, &result));
	if (!result)
	{
		int length;
		GLERR(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length));
		char* log = (char*)alloca(length * sizeof(char));
		GLERR(glGetShaderInfoLog(shader, length, nullptr, log));
		std::cout << "[WARNING] : SHADER COMPILE ERROR : "
			<< log << std::endl;
		return 0;
	}
	return shader;
}

void Shader::createShader(std::string &filename)
{
	ShaderSourceCode sourceCode = shaderParser(filename);
	int program = glCreateProgram();
	int vertexShader = compileShader(GL_VERTEX_SHADER, sourceCode.vertexShader);
	int fragmentShader = compileShader(GL_FRAGMENT_SHADER, sourceCode.fragmentShader);
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	int linkResult;
	int validationResult;
	glGetProgramiv(program, GL_LINK_STATUS, &linkResult);
	glGetProgramiv(program, GL_VALIDATE_STATUS, &validationResult);
	if (!linkResult || !validationResult)
	{
		int length;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
		const char *log = (char*)alloca(length * sizeof(char));
		std::cout << "[WARNING] : ";
		if (!linkResult && !validationResult) { std::cout << "LINK AND VALIDATION "; }
		else if (!linkResult) { std::cout << "LINK "; }
		else { std::cout << "VALIDATION "; }
		std::cout << "ERROR : " << log << std::endl;
		return;
	}
	m_ShaderID = program;
}