#include "SLIndexBuffer_GL2.hpp"

// SLR_GL2
namespace SLR_GL2
{
	// ISLIndexBuffer_GL2
	SLIndexBuffer_GL2::SLIndexBuffer_GL2(ISLRenderer* renderer) : mRenderer(renderer)
	{
		// create buffer handle
		GL_CHECK(glGenBuffers(1, &mGLBufferHandle));
	}

	// ~ISLIndexBuffer_GL2
	SLIndexBuffer_GL2::~SLIndexBuffer_GL2()
	{
		// delete handles
		GL_CHECK(glDeleteBuffers(1, &mGLBufferHandle));
	}

	// GetRenderer
	ISLRenderer* SLIndexBuffer_GL2::GetRenderer() const
	{
		return mRenderer;
	}

	// UpdateData
	void SLIndexBuffer_GL2::UpdateData(uint16_t* data, uint32_t size)
	{
		// store settings
		mSize = size;

		// update buffer data
		GL_CHECK(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mGLBufferHandle));
		GL_CHECK(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
		GL_CHECK(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}

	// GetSize
	uint32_t SLIndexBuffer_GL2::GetSize() const
	{
		return mSize;
	}
}
