#include "ElementBuffer.h"

ElementBuffer::ElementBuffer(const void *data, unsigned int count, VarType type)
{
	unsigned int typeSize = getSize(type);
	GLERR(glGenBuffers(1, &m_ElementBufferID));
	GLERR(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ElementBufferID));
	GLERR(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * typeSize, data, GL_STATIC_DRAW));
	GLERR(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

ElementBuffer::~ElementBuffer()
{
	GLERR(glDeleteBuffers(1, &m_ElementBufferID));
}

void ElementBuffer::bind() const
{
	GLERR(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ElementBufferID));
}

void ElementBuffer::unbind() const
{
	GLERR(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}