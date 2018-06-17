#include "VertexArray.h"

VertexArray::VertexArray(const VertexBuffer &vb, const ElementBuffer &eb)
	: m_VertexArrayID(0)
{
	GLERR(glGenVertexArrays(1, &m_VertexArrayID));
	GLERR(glBindVertexArray(m_VertexArrayID));
	vb.bind();
	eb.bind();
	switch (vb.getType())
	{
	case VarUINT: m_Type = GL_UNSIGNED_INT;
	case VarFLOAT:  m_Type = GL_FLOAT;
	}
	m_ByteSize = getSize(vb.getType());
	GLERR(glBindVertexArray(0));
}

void VertexArray::bind() const
{
	GLERR(glBindVertexArray(m_VertexArrayID));
	
	for (int i = 0; i < m_Attributes.size(); ++i)
	{
		GLERR(glVertexAttribPointer(i, m_Attributes[i].count, m_Type,
			m_Attributes[i].normalize, m_TotalCount * m_ByteSize, (void*)m_Attributes[i].offset));
		glEnableVertexAttribArray(i);
	}
}

void VertexArray::unbind() const
{
	GLERR(glBindVertexArray(0));
}

VertexArray::~VertexArray()
{
	GLERR(glDeleteVertexArrays(1, &m_VertexArrayID));
}

void VertexArray::addAttribf(int count, bool normalize)
{
	m_Attributes.push_back({ count, normalize, m_TotalCount * m_ByteSize });
	m_TotalCount += count;
}

