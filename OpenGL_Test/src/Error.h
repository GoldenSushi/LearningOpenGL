#ifndef ERROR_H
#define ERROR_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#if defined(OPENGL_DEBUG)
#ifndef GLERR
#define GLERR(x) clearError(); x; if(getError(#x, __FILE__, __LINE__)) __debugbreak()
#else
#define GLERR(x) x
#endif
#endif


static void clearError()
{
	while (glGetError()) {}
}

static bool getError(const char* function, const char* file, int line)
{
	while (unsigned int error = glGetError())
	{
		std::cout << "[ERROR] :" << error << std::endl
			<< "IN FUNCTION :  " << function << std::endl
			<< "IN FILE : " << file << std::endl
			<< "IN LINE : " << line << std::endl;
		return true;
	}
	return false;
}

enum VarType
{
	VarUINT = 0, VarFLOAT
};

static unsigned int getSize(VarType type)
{
	switch (type)
	{
	case VarUINT: return sizeof(unsigned int);
	case VarFLOAT: return sizeof(float);
	default: return 0;
	}
}

#endif //ERROR_H