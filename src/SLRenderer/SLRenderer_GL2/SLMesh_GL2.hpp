#pragma once

#include "SLTexture2D_GL2.hpp"
#include "SLBuffer_GL2.hpp"
#include "SLIndexBuffer_GL2.hpp"
#include "SLShader_GL2.hpp"

// SLR_GL2
namespace SLR_GL2 {
	// SLMesh_GL2
	class SLMesh_GL2 : public ISLMesh
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;
	public:
		// textures
		SLTexture2D_GL2* mBaseTexture   = nullptr;
		SLTexture2D_GL2* mDetailTexture = nullptr;
		SLTexture2D_GL2* mNormalTexture = nullptr;

		// buffers
		SLBuffer_GL2* mPositionBuffer = nullptr;
		SLBuffer_GL2* mColorBuffer    = nullptr;
		SLBuffer_GL2* mNormalBuffer   = nullptr;
		SLBuffer_GL2* mTangentBuffer  = nullptr;
		SLBuffer_GL2* mTexCoordBuffer = nullptr;
		SLBuffer_GL2* mWeightsBuffer  = nullptr;
		SLIndexBuffer_GL2* mIndexBuffer = nullptr;

		// shader
		SLShader_GL2* mShader = nullptr;

		// properties
		float mBaseColor[4]            = { 0,0,0,0 };
		uint32_t mPrimitiveCount       = 0;
		SLPrimitiveType mPrimitiveType = SL_PRIMITIVE_TYPE_TRIANGLE;
	public:
		// OpenGL handles and settings
		GLuint mGLPrimitiveMode = GL_TRIANGLES;
		GLuint mGLElementsCount = GL_TRIANGLES;

		// OpenGL attributes locations
		GLuint mGLAttribLocation_Position = cSLVertexAttribLication_Position;
		GLuint mGLAttribLocation_Color = cSLVertexAttribLication_Color;
		GLuint mGLAttribLocation_Normal = cSLVertexAttribLication_Normal;
		GLuint mGLAttribLocation_Tangent = cSLVertexAttribLication_Tangent;
		GLuint mGLAttribLocation_TexCoord = cSLVertexAttribLication_TexCoord;
		GLuint mGLAttribLocation_Weights = cSLVertexAttribLication_Weights;
	private:
		// utils
		void UpdateElementsCount();
	public:
		// constructor and destructor
		SLMesh_GL2(ISLRenderer* renderer);
		~SLMesh_GL2();

		// get device
		virtual ISLRenderer* GetRenderer() const;

		// set colors
		virtual void SetBaseColor(float r, float g, float b, float a);

		// set textures
		virtual void SetBaseTexture(ISLTexture2D* texture);
		virtual void SetDetailTexture(ISLTexture2D* texture);
		virtual void SetNormalTexture(ISLTexture2D* texture);

		// set buffers
		virtual void SetPositionBuffer(ISLBuffer* buffer);
		virtual void SetColorBuffer(ISLBuffer* buffer);
		virtual void SetNormalBuffer(ISLBuffer* buffer);
		virtual void SetTangentBuffer(ISLBuffer* buffer);
		virtual void SetTexCoordBuffer(ISLBuffer* buffer);
		virtual void SetWeightsBuffer(ISLBuffer* buffer);
		virtual void SetIndexBuffer(ISLIndexBuffer* buffer);

		// set primitive info
		virtual void SetPrimitiveCount(uint32_t count);
		virtual void SetPrimitiveType(SLPrimitiveType primitiveType);

		// get colors
		virtual void GetBaseColor(float& r, float& g, float& b, float& a) const;

		// get textures
		virtual ISLTexture2D* GetBaseTexture() const;
		virtual ISLTexture2D* GetDetailTexture() const;
		virtual ISLTexture2D* GetNormalTexture() const;

		// get buffers
		virtual ISLBuffer* GetPositionBuffer() const;
		virtual ISLBuffer* GetColorBuffer() const;
		virtual ISLBuffer* GetNormalBuffer() const;
		virtual ISLBuffer* GetTangentBuffer() const;
		virtual ISLBuffer* GetTexCoordBuffer() const;
		virtual ISLBuffer* GetWeightsBuffer() const;
		virtual ISLIndexBuffer* GetIndexBuffer() const;

		// get primitive info
		virtual uint32_t GetPrimitiveCount() const;
		virtual SLPrimitiveType GetPrimitiveType() const;
	};
}
