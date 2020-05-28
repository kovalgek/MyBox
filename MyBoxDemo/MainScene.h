#include <wrl/client.h>
#include <vector>
#include <memory>
#include <string>

class Application;
class GameTimer;
class FrameResourceController;
class ObjectsDataProvider;
class PipleneStateData;
struct FrameResource;
struct ID3D12Device;
struct ID3D12CommandQueue;
struct ID3D12CommandAllocator;
struct ID3D12GraphicsCommandList;

const int gNumFrameResources = 3;

#pragma once
class MainScene
{
public:
	MainScene(
		Application *appContext,
		std::unique_ptr<PipleneStateData> pipleneStateData,
		FrameResourceController *frameResourceController,
		ObjectsDataProvider *objectsDataProvider);

	~MainScene();
	void draw(const GameTimer& gameTimer);

private:
	Application *appContext;

	ID3D12Device              *device;
	ID3D12CommandQueue        *commandQueue;
	ID3D12CommandAllocator    *commandAllocator;
	ID3D12GraphicsCommandList *commandList;

	FrameResourceController *frameResourceController;
	std::unique_ptr<PipleneStateData> pipleneStateData;
	ObjectsDataProvider *objectsDataProvider;

	void onKeyboardInput(const GameTimer& gameTimer);
	void drawRenderItems(ID3D12GraphicsCommandList* cmdList);

	bool isWireframe = false;
};

