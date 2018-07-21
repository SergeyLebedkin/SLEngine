#pragma once

#include "../SLRenderer.hpp"
#include <GLES2/gl2.h>

// SLR_GLES3
namespace SLR_GLES3 {
	// SLRendererGL2
	class SLRenderer_GLES3 : public ISLRenderer
	{
	public:
		// constructor and destructor
		SLRenderer_GLES3();
		~SLRenderer_GLES3();

		// texture functions
		virtual ISLTexture2D* CreateTexture2D(uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel = 0);
		virtual void UpdateTexture2D(ISLTexture2D* texture2d, uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel = 0);
		virtual void DeleteTexture2D(ISLTexture2D* texture2d);

		// buffer functions
		virtual ISLBuffer* CreateBuffer(float* data, uint32_t size);
		virtual void UpdateBuffer(ISLBuffer* buffer, float* data, uint32_t size);
		virtual void DeleteBuffer(ISLBuffer* buffer);

		// index buffer functions
		virtual ISLIndexBuffer* CreateIndexBuffer(uint16_t* data, uint32_t size);
		virtual void UpdateIndexBuffer(ISLIndexBuffer* buffer, uint16_t* data, uint32_t size);
		virtual void DeleteIndexBuffer(ISLIndexBuffer* buffer);

		// mesh functions
		virtual ISLMesh* CreateMesh();
		virtual void DeleteMesh(ISLMesh* mesh);

		// model functions
		virtual ISLModel* CreateModel();
		virtual void DeleteModel(ISLModel* model);

		// camera functions
		virtual ISLCamera* CreateCamera();
		virtual void DeleteCamera(ISLCamera* camera);

		// scene functions
		virtual ISLScene* CreateScene();
		virtual void DeleteScene(ISLScene* scene);

		// render
		virtual void Render();

		// delete resource
		virtual void DeleteResources();

		// get description
		virtual const char * GetDescription() const;
	};
}