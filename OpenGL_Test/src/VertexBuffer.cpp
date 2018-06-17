#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void *data, unsigned int count, VarType type)
	: m_VertexBufferID(0), m_Type(type)
{
	unsigned int typeSize = getSize(type);
	GLERR(glGenBuffers(1, &m_VertexBufferID));
	GLERR(glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID));
	GLERR(glBufferData(GL_ARRAY_BUFFER, count * typeSize, data, GL_STATIC_DRAW));
	GLERR(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_VertexBufferID);
}

void VertexBuffer::bind() const
{
	GLERR(glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID));
}

void VertexBuffer::unbind() const
{
	GLERR(glBindBuffer(GL_ARRAY_BUFFER, 0));
}