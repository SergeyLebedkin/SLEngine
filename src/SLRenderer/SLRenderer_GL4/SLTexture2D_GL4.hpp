#pragma once
#include "SLOpenGL4.hpp"

// SLR_GL4
namespace SLR_GL4 {
	// SLTexture2D_GL4
	class SLTexture2D_GL4 : public ISLTexture2D
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;

		// properties
		SLTextureWrapMode mWrapModeS = SL_TEXTURE_WRAP_MODE_REPEAT;
		SLTextureWrapMode mWrapModeT = SL_TEXTURE_WRAP_MODE_REPEAT;
		SLTextureFilterimgMode mFilteringMode = SL_TEXTURE_FILTERING_MODE_LINEAR;
	public:
		// OpenGL handles and settings
		GLuint mGLTextureHadle = 0;
		GLuint mGLSamplerHadle = 0;
		GLint mGLWrapModeS = GL_REPEAT;
		GLint mGLWrapModeT = GL_REPEAT;
		GLint mGLMinFilteringMode = GL_LINEAR;
		GLint mGLMagFilteringMode = GL_LINEAR;
		GLint mGLInternalFormat = GL_RGBA;
		GLenum mGLFormat = GL_RGBA;
	private:
		// utils
		void UpdateFormats(SLTextureDataType textureDataType);
	public:
		// constructor and destructor
		SLTexture2D_GL4(ISLRenderer* renderer);
		~SLTexture2D_GL4();

		// get render device
		virtual ISLRenderer* GetRenderer() const;

		// update image
		virtual void UpdateImage(int32_t mipLevel, SLTextureDataType format, uint32_t width, uint32_t height, const void* data, size_t dataSize = 0);

		// set texture wrap mode S and T
		virtual void SetWrapModeS(SLTextureWrapMode wrapMode);
		virtual void SetWrapModeT(SLTextureWrapMode wrapMode);
		virtual void SetFilteringMode(SLTextureFilterimgMode filterimgMode);

		// get texture wrap mode S and T
		virtual SLTextureWrapMode GetWrapModeS() const;
		virtual SLTextureWrapMode GetWrapModeT() const;
		virtual SLTextureFilterimgMode GetFilterimgMode() const;
	};
}
