#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "Error.h"



class VertexBuffer
{
private:
	unsigned int m_VertexBufferID;
	unsigned int m_Count;
	VarType m_Type;
public:
	VertexBuffer(const void *data, unsigned int size, VarType type);
	~VertexBuffer();
	void bind() const;
	void unbind() const;
	inline unsigned int getCount() const { return m_Count; }
	inline VarType getType() const { return m_Type; }
};

#endif //VERTEXBUFFER_H
