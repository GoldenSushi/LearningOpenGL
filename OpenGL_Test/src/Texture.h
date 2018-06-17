#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>

enum ExternalFormat
{
	RGBA = 1, RGB
};

class Texture
{
private:
	unsigned int m_TextureID;
	unsigned char *m_DataBuffer;
	int m_Width;
	int m_Height;
	int m_Channels;
public:
	Texture(const std::string file, ExternalFormat externalFormat = RGB);
	~Texture();
	void bind(unsigned int textureSlot);
	void unbind();
};

#endif //TEXTURE_H