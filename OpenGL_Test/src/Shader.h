#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


enum ShaderType
{
	NONE = -1, VERTEX = 0, FRAGMENT = 1
};

struct ShaderSourceCode
{
	std::string vertexShader;
	std::string fragmentShader;
};

class Shader
{
private:
	int m_ShaderID;
	void createShader(std::string &filename);
	int compileShader(int type, std::string &sourceCode) const;
public:
	Shader(std::string &filename);
	~Shader();
	void bind() const;
	void setUniform1i(const std::string &name, unsigned int v0);
	void setUniform4f(const std::string &name, float v0, float v1, float v2, float v3);
	inline int getShaderID() const
	{
		return m_ShaderID;
	}
};

static ShaderSourceCode shaderParser(std::string &filename)
{
	std::ifstream shaderSource(filename);
	if (!shaderSource)
	{
		std::cout << "[WARNING] : Could not open file: " << filename << std::endl;
		return { nullptr, nullptr };
	}
	std::string line;
	std::stringstream ss[2];
	ShaderType type = VERTEX;

	while (std::getline(shaderSource, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos) { type = VERTEX; }
			else if (line.find("fragment") != std::string::npos) { type = FRAGMENT; }
		}
		else
		{
			if ((int)type >= 0) { ss[(int)type] << line << '\n'; }
		}
	}
	return { ss[0].str(), ss[1].str() };
}

#endif //SHADER_H