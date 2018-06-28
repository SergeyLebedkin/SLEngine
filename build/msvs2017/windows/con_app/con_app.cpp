#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <map>

class ISLRenderer;

// SLTextureWrapMode
enum SLTextureWrapMode
{
	SL_TEXTURE_WRAP_MODE_CLAMP  = 0,
	SL_TEXTURE_WRAP_MODE_REPEAT = 1,
};

// SLTextureFilterimgMode
enum SLTextureFilterimgMode 
{
	SL_TEXTURE_FILTERING_MODE_NEAREST        = 0,
	SL_TEXTURE_FILTERING_MODE_LINEAR         = 1,
	SL_TEXTURE_FILTERING_MODE_MIPMAP_NEAREST = 2,
	SL_TEXTURE_FILTERING_MODE_MIPMAP_LENEAR  = 3,
};

// SLPixelDataType
enum SLPixelDataType 
{
	SL_PIXEL_DATA_TYPE_R    = 0,
	SL_PIXEL_DATA_TYPE_RG   = 1,
	SL_PIXEL_DATA_TYPE_RGB  = 2,
	SL_PIXEL_DATA_TYPE_BGR  = 3,
	SL_PIXEL_DATA_TYPE_RGRA = 4,
	SL_PIXEL_DATA_TYPE_BGRA = 5,
};

// SLPrimitiveType
enum SLPrimitiveType
{
	SL_PRIMITIVE_TYPE_POINT          = 0,
	SL_PRIMITIVE_TYPE_LINE           = 1,
	SL_PRIMITIVE_TYPE_LINE_STRIP     = 2,
	SL_PRIMITIVE_TYPE_TRIANGLE       = 3,
	SL_PRIMITIVE_TYPE_TRIANGLE_STRIP = 4,
};

// SLRendererType
enum SLRendererType
{
	SL_RENDERER_TYPE_GL2 = 0,
	SL_RENDERER_TYPE_GLES2 = 1,
	SL_RENDERER_TYPE_VULKAN = 2,
	SL_RENDERER_TYPE_D3D9 = 3,
	SL_RENDERER_TYPE_DEFAULT = 0x7fffffff,
};

enum SLMeshGroupVisibilityMode
{
	SL_MESH_GROUP_VISIBILITY_MODE_VISIBLE     = 0,
	SL_MESH_GROUP_VISIBILITY_MODE_HIDE        = 1,
	SL_MESH_GROUP_VISIBILITY_MODE_TRANSPARENT = 2,
	
};

// ISLTexture2D
class ISLTexture2D
{
protected:
	// hide constructor and destructor
	ISLTexture2D() {};
	~ISLTexture2D() {};
public:
	// get render device
	virtual ISLRenderer* GetRenderer() const = 0;

	// get texture wrap mode S and T
	virtual SLTextureWrapMode GetWrapModeS() const = 0;
	virtual SLTextureWrapMode GetWrapModeT() const = 0;
	virtual SLTextureFilterimgMode GetFilterimgMode() const = 0;

	// set texture wrap mode S and T
	virtual void SetWrapModeS(SLTextureWrapMode wrapMode) = 0;
	virtual void SetWrapModeT(SLTextureWrapMode wrapMode) = 0;
	virtual void SetFilterimgMode(SLTextureFilterimgMode filterimgMode) = 0;
};

// ISLBuffer
class ISLBuffer
{
protected:
	// hide constructor and destructor
	ISLBuffer() {}
	~ISLBuffer() {}
public:
	// get device
	virtual ISLRenderer* GetRenderer() = 0;

	// get buffer size
	virtual size_t GetSize() = 0;
};

// ISLIndexBuffer
class ISLIndexBuffer
{
protected:
	// hide constructor and destructor
	ISLIndexBuffer() {};
	~ISLIndexBuffer() {};
public:
	// get device
	virtual ISLRenderer* GetRenderer() = 0;

	// get buffer size
	virtual size_t GetSize() = 0;
};

// ISLMesh
class ISLMesh
{
protected:
	// hide constructor and destructor
	ISLMesh() {};
	~ISLMesh() {};
public:
	// get device
	virtual ISLRenderer* GetRenderer() = 0;

	// get textures
	virtual void SetBaseTexture(ISLTexture2D* texture) = 0;
	virtual void SetDetailTexture(ISLTexture2D* texture) = 0;
	virtual void SetNormalTexture(ISLTexture2D* texture) = 0;

	// get buffers
	virtual void SetPositionBuffer(ISLBuffer* buffer) = 0;
	virtual void SetColorBuffer(ISLBuffer* buffer) = 0;
	virtual void SetNormalBuffer(ISLBuffer* buffer) = 0;
	virtual void SetTangentBuffer(ISLBuffer* buffer) = 0;
	virtual void SetBaseTexCoordBuffer(ISLBuffer* buffer) = 0;
	virtual void SetNormalTexCoordBuffer(ISLBuffer* buffer) = 0;
	virtual void SetWeightsBuffer(ISLBuffer* buffer) = 0;
	virtual void SetIndexBuffer(ISLIndexBuffer* buffer) = 0;

	// get primitive info
	virtual void SetPrimitiveCount(size_t count) = 0;
	virtual void SetPrimitiveType(SLPrimitiveType primitiveType) = 0;

	// get textures
	virtual ISLTexture2D* GetBaseTexture() const = 0;
	virtual ISLTexture2D* GetDetailTexture() const = 0;
	virtual ISLTexture2D* GetNormalTexture() const = 0;

	// get buffers
	virtual ISLBuffer* GetPositionBuffer() const = 0;
	virtual ISLBuffer* GetColorBuffer() const = 0;
	virtual ISLBuffer* GetNormalBuffer() const = 0;
	virtual ISLBuffer* GetTangentBuffer() const = 0;
	virtual ISLBuffer* GetBaseTexCoordBuffer() const = 0;
	virtual ISLBuffer* GetNormalTexCoordBuffer() const = 0;
	virtual ISLBuffer* GetWeightsBuffer() const = 0;
	virtual ISLIndexBuffer* GetIndexBuffer() const = 0;

	// get primitive info
	virtual size_t GetPrimitiveCount() const = 0;
	virtual SLPrimitiveType GetPrimitiveType() const = 0;
};

// ISLModel
class ISLModel
{
protected:
	ISLModel() {}
	~ISLModel() {}
public:
	// get device
	virtual ISLRenderer* GetRenderer() = 0;

	// visibility functions
	virtual void SetVisibilityMode(SLMeshGroupVisibilityMode visibilityMode) = 0;
	virtual SLMeshGroupVisibilityMode SetVisibilityMode() = 0;

	// transparency functions
	virtual void SetTransparency(float transparency) = 0;
	virtual float GetTransparency() = 0;

	// mesh functions
	virtual void AddMesh(ISLMesh* mesh) = 0;
	virtual void RemoveMesh(ISLMesh* mesh) = 0;

	// transform matrix functions
	virtual void SetTransform(glm::mat4 mat) = 0;
	virtual glm::mat4 SetTransform() = 0;
};

// ISLCamera
class ISLCamera : public ISLModel
{
protected:
	ISLCamera() {}
	~ISLCamera() {}
public:
	// set properties
	virtual void SetFOV(float fov) = 0;
	virtual void SetNearPlane(float nearPlane) = 0;
	virtual void SetFarPlane(float farPlane) = 0;

	// set properties
	virtual float GetFOV() = 0;
	virtual float GetNearPlane() = 0;
	virtual float GetFarPlane() = 0;
};

// ISLRenderer
class ISLRenderer
{
protected:
	// hide constructor
	ISLRenderer() {}
	~ISLRenderer() {}
public:
	// texture functions
	virtual ISLTexture2D* CreateTexture2D(void * data, size_t dataSize, size_t width, size_t height, SLPixelDataType pixelDataType, size_t mipLevel = 0) = 0;
	virtual void UpdateTexture2D(ISLTexture2D* texture2d, void * data, size_t dataSize, size_t width, size_t height, SLPixelDataType pixelDataType, size_t mipLevel = 0) = 0;
	virtual void DeleteTexture2D(ISLTexture2D* texture2d) = 0;

	// buffer functions
	virtual ISLBuffer* CreateBuffer(void* data, size_t size) = 0;
	virtual void UpdateBuffer(ISLBuffer* buffer, void* data, size_t size) = 0;
	virtual void DeleteBuffer(ISLBuffer* buffer) = 0;

	// index buffer functions
	virtual ISLIndexBuffer* CreateIndexBuffer(uint16_t* data, size_t size) = 0;
	virtual void UpdateIndexBuffer(ISLIndexBuffer* buffer, uint16_t* data, size_t size) = 0;
	virtual void DeleteIndexBuffer(ISLIndexBuffer* buffer) = 0;

	// mesh functions
	virtual ISLMesh* CreateMesh() = 0;
	virtual void DeleteMesh(ISLMesh* mesh) = 0;

	// model functions
	virtual ISLModel* CreateModel() = 0;
	virtual void DeleteModel(ISLModel* model) = 0;

	// camera functions
	virtual ISLCamera* CreateCamera() = 0;
	virtual void DeleteCamera(ISLCamera* camera) = 0;

	// render
	virtual void Render(ISLCamera* camera) = 0;

	// delete resource
	virtual void DeleteResources() = 0;
};

// SLRendererFabric
class SLRendererFabric
{
public:
	static ISLRenderer* CreateRenderer(SLRendererType rendererType = SL_RENDERER_TYPE_DEFAULT)
	{
		if (rendererType == SL_RENDERER_TYPE_GL2)
			return nullptr;
		else if (rendererType == SL_RENDERER_TYPE_GLES2)
			return nullptr;
		else if (rendererType == SL_RENDERER_TYPE_VULKAN)
			return nullptr;
		else if (rendererType == SL_RENDERER_TYPE_D3D9)
			return nullptr;
		return nullptr;
	}
};

// fake realizations
class SLRenderer_GL2 : public ISLRenderer {};
class SLRenderer_GLES2 : public ISLRenderer {};
class SLRenderer_Vulkan : public ISLRenderer {};
class SLRenderer_D3D9 : public ISLRenderer {};

// main
int main(int argc, char** argv)
{
	// create renderer
	ISLRenderer* renderer = SLRendererFabric::CreateRenderer();

	// create buffers
	ISLBuffer* positionBuffer = renderer->CreateBuffer(nullptr, 1024);
	ISLBuffer* noramlBuffer = renderer->CreateBuffer(nullptr, 1024);
	ISLIndexBuffer* indexBuffer = renderer->CreateIndexBuffer(nullptr, 1024);

	// create mesh and setup buffers
	ISLMesh* mesh = renderer->CreateMesh();
	mesh->SetPositionBuffer(positionBuffer);
	mesh->SetNormalBuffer(noramlBuffer);
	mesh->SetIndexBuffer(indexBuffer);

	// create model
	ISLModel* model = renderer->CreateModel();
	model->AddMesh(mesh);
	model->SetTransparency(1.0f);
	model->SetVisibilityMode(SL_MESH_GROUP_VISIBILITY_MODE_VISIBLE);

	// create camera
	ISLCamera* camera = renderer->CreateCamera();
	camera->SetFOV(45.0f);
	camera->SetNearPlane(0.1f);
	camera->SetFarPlane(100.0f);

	// render
	while(true) renderer->Render(camera);

	// delete camera
	renderer->DeleteCamera(camera);

	// delete model
	renderer->DeleteModel(model);

	// delete mesh
	renderer->DeleteMesh(mesh);

	// delete buffers
	renderer->DeleteIndexBuffer(indexBuffer);
	renderer->DeleteBuffer(noramlBuffer);
	renderer->DeleteBuffer(positionBuffer);

	return std::system("pause");
}