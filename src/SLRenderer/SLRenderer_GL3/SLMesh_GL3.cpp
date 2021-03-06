#include "SLMesh_GL3.hpp"
#include "SLCamera_GL3.hpp"
#include "SLModel_GL3.hpp"

// SLR_GL3
namespace SLR_GL3
{
	// SLMesh_GL3
	SLMesh_GL3::SLMesh_GL3(ISLRenderer* renderer) : mRenderer(renderer)
	{
		// create vertex array handle
		GL_CHECK(glGenVertexArrays(1, &mGLVertexArrayHandle));
	}

	// ~SLMesh_GL3
	SLMesh_GL3::~SLMesh_GL3()
	{
		GL_CHECK(glDeleteVertexArrays(1, &mGLVertexArrayHandle));
	}

	// UpdateElementsCount
	void SLMesh_GL3::UpdateElementsCount()
	{
		switch (mPrimitiveType)
		{
		case SL_PRIMITIVE_TYPE_POINT:
			mGLElementsCount = mPrimitiveCount;
			break;
		case SL_PRIMITIVE_TYPE_LINE:
			mGLElementsCount = mPrimitiveCount * 2;
			break;
		case SL_PRIMITIVE_TYPE_LINE_STRIP:
			mGLElementsCount = mPrimitiveCount + 1;
			break;
		case SL_PRIMITIVE_TYPE_TRIANGLE:
			mGLElementsCount = mPrimitiveCount * 3;
			break;
		case SL_PRIMITIVE_TYPE_TRIANGLE_STRIP:
			mGLElementsCount = mPrimitiveCount + 2;
			break;
		default:
			break;
		}
	}

	// GetRenderer
	ISLRenderer* SLMesh_GL3::GetRenderer() const
	{
		return mRenderer;
	}

	// SetBaseColor
	void SLMesh_GL3::SetBaseColor(float r, float g, float b, float a)
	{
		mBaseColor[0] = r;
		mBaseColor[1] = g;
		mBaseColor[2] = b;
		mBaseColor[3] = a;
	}

	// SetBaseTexture
	void SLMesh_GL3::SetBaseTexture(ISLTexture2D* texture)
	{
		mBaseTexture = (SLTexture2D_GL3 *)texture;
	}

	// SetDetailTexture
	void SLMesh_GL3::SetDetailTexture(ISLTexture2D* texture)
	{
		mDetailTexture = (SLTexture2D_GL3 *)texture;
	}

	// SetNormalTexture
	void SLMesh_GL3::SetNormalTexture(ISLTexture2D* texture)
	{
		mNormalTexture = (SLTexture2D_GL3 *)texture;
	}

	// SetPositionBuffer
	void SLMesh_GL3::SetPositionBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mPositionBuffer != buffer)
		{
			// store and update
			mPositionBuffer = (SLBuffer_GL3 *)buffer;
			UpdateVAO();
		}
	}

	// SetColorBuffer
	void SLMesh_GL3::SetColorBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mColorBuffer != buffer)
		{
			// store and update
			mColorBuffer = (SLBuffer_GL3 *)buffer;
			UpdateVAO();
		}
	}

	// SetNormalBuffer
	void SLMesh_GL3::SetNormalBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mNormalBuffer != buffer)
		{
			// store and update
			mNormalBuffer = (SLBuffer_GL3 *)buffer;
			UpdateVAO();
		}
	}

	// SetTangentBuffer
	void SLMesh_GL3::SetTangentBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mTangentBuffer != buffer)
		{
			// store and update
			mTangentBuffer = (SLBuffer_GL3 *)buffer;
			UpdateVAO();
		}
	}

	// SetTexCoordBuffer
	void SLMesh_GL3::SetTexCoordBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mTexCoordBuffer != buffer)
		{
			// store and update
			mTexCoordBuffer = (SLBuffer_GL3 *)buffer;
			UpdateVAO();
		}
	}

	// SetWeightsBuffer
	void SLMesh_GL3::SetWeightsBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mWeightsBuffer != buffer)
		{
			// store and update
			mWeightsBuffer = (SLBuffer_GL3 *)buffer;
			UpdateVAO();
		}
	}

	// SetIndexBuffer
	void SLMesh_GL3::SetIndexBuffer(ISLIndexBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsIndexBufferExists(buffer)))
			return;

		// check if changed
		if (mIndexBuffer != buffer)
		{
			// store and update
			mIndexBuffer = (SLIndexBuffer_GL3 *)buffer;
			UpdateVAO();
		}
	}

	// SetPrimitiveCount
	void SLMesh_GL3::SetPrimitiveCount(uint32_t count)
	{
		mPrimitiveCount = count;
		UpdateElementsCount();
	}

	// SetPrimitiveType
	void SLMesh_GL3::SetPrimitiveType(SLPrimitiveType primitiveType)
	{
		mPrimitiveType = primitiveType;
		mGLPrimitiveMode = cSLPrimitiveTypeToGLPrimitiveMode[mPrimitiveType];
		UpdateElementsCount();
	}

	// GetBaseColor
	void SLMesh_GL3::GetBaseColor(float& r, float& g, float& b, float& a) const
	{
		r = mBaseColor[0];
		g = mBaseColor[1];
		b = mBaseColor[2];
		a = mBaseColor[3];
	}

	// GetBaseTexture
	ISLTexture2D* SLMesh_GL3::GetBaseTexture() const
	{
		return mBaseTexture;
	}

	// GetDetailTexture
	ISLTexture2D* SLMesh_GL3::GetDetailTexture() const
	{
		return mDetailTexture;
	}

	// GetNormalTexture
	ISLTexture2D* SLMesh_GL3::GetNormalTexture() const
	{
		return mNormalTexture;
	}

	// GetPositionBuffer
	ISLBuffer* SLMesh_GL3::GetPositionBuffer() const
	{
		return mPositionBuffer;
	}

	// GetColorBuffer
	ISLBuffer* SLMesh_GL3::GetColorBuffer() const
	{
		return mColorBuffer;
	}

	// GetNormalBuffer
	ISLBuffer* SLMesh_GL3::GetNormalBuffer() const
	{
		return mNormalBuffer;
	}

	// GetTangentBuffer
	ISLBuffer* SLMesh_GL3::GetTangentBuffer() const
	{
		return mTangentBuffer;
	}

	// GetTexCoordBuffer
	ISLBuffer* SLMesh_GL3::GetTexCoordBuffer() const
	{
		return mTexCoordBuffer;
	}

	// GetWeightsBuffer
	ISLBuffer* SLMesh_GL3::GetWeightsBuffer() const
	{
		return mWeightsBuffer;
	}

	// GetIndexBuffer
	ISLIndexBuffer* SLMesh_GL3::GetIndexBuffer() const
	{
		return mIndexBuffer;
	}

	// GetPrimitiveCount
	uint32_t SLMesh_GL3::GetPrimitiveCount() const
	{
		return mPrimitiveCount;
	}

	// GetPrimitiveType
	SLPrimitiveType SLMesh_GL3::GetPrimitiveType() const
	{
		return mPrimitiveType;
	}

	// update mesh VAO
	void SLMesh_GL3::UpdateVAO()
	{
		// bind VAO
		GL_CHECK(glBindVertexArray(mGLVertexArrayHandle));

		// set position buffer
		if (mPositionBuffer != nullptr)
		{ 
			GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mPositionBuffer->mGLBufferHandle));
			GL_CHECK(glVertexAttribPointer(mGLAttribLocation_Position, 3, GL_FLOAT, GL_FALSE, 0, 0));
			GL_CHECK(glEnableVertexAttribArray(mGLAttribLocation_Position));
		}

		// set color buffer
		if (mColorBuffer != nullptr)
		{
			GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mColorBuffer->mGLBufferHandle));
			GL_CHECK(glVertexAttribPointer(mGLAttribLocation_Color, 4, GL_FLOAT, GL_FALSE, 0, 0));
			GL_CHECK(glEnableVertexAttribArray(mGLAttribLocation_Color));
		}

		// set normal buffer
		if (mNormalBuffer != nullptr)
		{
			GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mNormalBuffer->mGLBufferHandle));
			GL_CHECK(glVertexAttribPointer(mGLAttribLocation_Normal, 3, GL_FLOAT, GL_FALSE, 0, 0));
			GL_CHECK(glEnableVertexAttribArray(mGLAttribLocation_Normal));
		}

		// set tangent buffer
		if (mTangentBuffer != nullptr)
		{
			GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mTangentBuffer->mGLBufferHandle));
			GL_CHECK(glVertexAttribPointer(mGLAttribLocation_Tangent, 3, GL_FLOAT, GL_FALSE, 0, 0));
			GL_CHECK(glEnableVertexAttribArray(mGLAttribLocation_Tangent));
		}

		// set tex coord buffer
		if (mTexCoordBuffer != nullptr)
		{
			GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mTexCoordBuffer->mGLBufferHandle));
			GL_CHECK(glVertexAttribPointer(mGLAttribLocation_TexCoord, 2, GL_FLOAT, GL_FALSE, 0, 0));
			GL_CHECK(glEnableVertexAttribArray(mGLAttribLocation_TexCoord));
		}

		// set weights buffer
		if (mWeightsBuffer != nullptr)
		{
			GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mWeightsBuffer->mGLBufferHandle));
			GL_CHECK(glVertexAttribPointer(mGLAttribLocation_Weights, 4, GL_FLOAT, GL_FALSE, 0, 0));
			GL_CHECK(glEnableVertexAttribArray(mGLAttribLocation_Weights));
		}

		// set index buffer
		if (mIndexBuffer != nullptr)
			GL_CHECK(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer->mGLBufferHandle));

		// unbind VAO
		GL_CHECK(glBindVertexArray(0));
	}
}
