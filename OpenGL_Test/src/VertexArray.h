#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include "Error.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"
#include <vector>

struct Attributes
{
	int count;
	bool normalize;
	int offset;
};

class VertexArray
{
private:
	unsigned int m_VertexArrayID;
	int m_TotalCount;
	GLenum m_Type;
	int m_ByteSize;
	std::vector<Attributes> m_Attributes;
public:
	VertexArray(const VertexBuffer &vb, const ElementBuffer &eb);
	~VertexArray();
	void bind() const;
	void unbind() const;
	void addAttribf(int count, bool normalize = false);
};

#endif //VERTEXARRAY_H