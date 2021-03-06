#include <memory>

class GPUService;
class Renderer;
class MainPassDataProvider;
class ObjectsDataProvider;
class MaterialsDataProvider;
class DynamicVerticesProvider;
class FrameResourceUpdater;
class ViewController;
class GeometryStorageConfigurator;
class MaterialsDataProviderConfigurator;
class RenderItemTemplatesProvider;
class OBJFileLoader;

#pragma once
class AppContext
{
public:
	AppContext(
		std::unique_ptr<GPUService> gpuService,
		std::unique_ptr<Renderer> renderer,
		std::unique_ptr<MainPassDataProvider> mainPassDataProvider,
		std::unique_ptr<ObjectsDataProvider> objectsDataProvider,
		std::unique_ptr<MaterialsDataProvider> materialsDataProvider,		
		std::unique_ptr<DynamicVerticesProvider> dynamicVerticesProvider,
		std::unique_ptr<FrameResourceUpdater> frameResourceUpdater,
		std::unique_ptr<ViewController> viewController,
		std::unique_ptr<GeometryStorageConfigurator> geometryStorageConfigurator,
		std::unique_ptr<MaterialsDataProviderConfigurator> materialsDataProviderConfigurator,
		std::unique_ptr<RenderItemTemplatesProvider> renderItemTemplatesProvider,
		std::unique_ptr<OBJFileLoader> objFileLoader);
	~AppContext();

	GPUService* getGPUService() { return gpuService.get(); }
	Renderer* getRenderer() { return renderer.get(); }
	MainPassDataProvider* getMainPassDataProvider() { return mainPassDataProvider.get(); }
	ObjectsDataProvider* getObjectsDataProvider() { return objectsDataProvider.get(); }
	MaterialsDataProvider* getMaterialsDataProvider() { return materialsDataProvider.get(); }
	DynamicVerticesProvider* getDynamicVerticesProvider() { return dynamicVerticesProvider.get(); }
	FrameResourceUpdater* getFrameResourceUpdater() { return frameResourceUpdater.get(); }
	ViewController* getViewController() { return viewController.get(); }
	GeometryStorageConfigurator* getGeometryStorageConfigurator() { return geometryStorageConfigurator.get(); }
	MaterialsDataProviderConfigurator* getMaterialsDataProviderConfigurator() { return materialsDataProviderConfigurator.get(); }
	RenderItemTemplatesProvider* getRenderItemTemplatesProvider() { return renderItemTemplatesProvider.get(); }
	OBJFileLoader* getOBJFileLoader() { return objFileLoader.get(); }

private:
	std::unique_ptr<GPUService> gpuService;
	std::unique_ptr<Renderer> renderer;
	std::unique_ptr<MainPassDataProvider> mainPassDataProvider;
	std::unique_ptr<ObjectsDataProvider> objectsDataProvider;
	std::unique_ptr<MaterialsDataProvider> materialsDataProvider;
	std::unique_ptr<DynamicVerticesProvider> dynamicVerticesProvider;
	std::unique_ptr<FrameResourceUpdater> frameResourceUpdater;
	std::unique_ptr<ViewController> viewController;
	std::unique_ptr<GeometryStorageConfigurator> geometryStorageConfigurator;
	std::unique_ptr<MaterialsDataProviderConfigurator> materialsDataProviderConfigurator;
	std::unique_ptr<RenderItemTemplatesProvider> renderItemTemplatesProvider;
	std::unique_ptr<OBJFileLoader> objFileLoader;
};