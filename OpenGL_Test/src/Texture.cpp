#include "Texture.h"
#include "Error.h"
#include <iostream>
#include "stb_image\stb_image.h"

Texture::Texture(const std::string file, ExternalFormat externalFormat)
{
	GLERR(glGenTextures(1, &m_TextureID));
	GLERR(glBindTexture(GL_TEXTURE_2D, m_TextureID));
	GLERR(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLERR(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLERR(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
	GLERR(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));


	stbi_set_flip_vertically_on_load(true); //flips image so it wont load upside down
	m_DataBuffer = stbi_load(file.c_str(), &m_Width, &m_Height, &m_Channels, 0);
	
	if (!m_DataBuffer)
	{
		std::cout << "[WARNING] : Could not load Texture " << file << " properly." << std::endl;
	}

	if (externalFormat == RGB)
	{
		GLERR(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_DataBuffer));
	}
	else if (externalFormat == RGBA)
	{
		GLERR(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_DataBuffer));
	}
	
	GLERR(glBindTexture(GL_TEXTURE_2D, 0));

	if (m_DataBuffer)
	{
		stbi_image_free(m_DataBuffer);
	}
}

Texture::~Texture()
{
	GLERR(glDeleteTextures(1, &m_TextureID));
}

void Texture::bind(unsigned int slot)
{
	GLERR(glActiveTexture(GL_TEXTURE0 + slot));
	GLERR(glBindTexture(GL_TEXTURE_2D, m_TextureID));
}

void Texture::unbind()
{
	GLERR(glBindTexture(GL_TEXTURE_2D, 0));
}