#ifndef ELEMENTBUFFER_H
#define ELEMENTBUFFER_H

#include "Error.h"

class ElementBuffer
{
private:
	unsigned int m_ElementBufferID;
	unsigned int m_count;
public:
	ElementBuffer(const void *data, unsigned int count, VarType type);
	~ElementBuffer();
	void bind() const;
	void unbind() const;
	inline unsigned int getCount() { return m_count; }
};

#endif //ELEMENTBUFFER_H