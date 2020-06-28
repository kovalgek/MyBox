#include <windows.h>
#include <wrl.h>
#include <dxgi1_4.h>
#include <d3d12.h>

// Link necessary d3d12 libraries.
#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")
#pragma comment(lib, "dxgi.lib")

#define MAX_LOADSTRING 100

//struct AppConfig
//{
//	DXGI_FORMAT backBufferFormat;
//	DXGI_FORMAT depthStencilFormat;
//	bool msaa4xState;
//	UINT msaa4xQuality;
//};

class Application
{
public:
	Application(HWND mainWindowHandle);
	~Application();

	void onResize(int clientWidth, int clientHeight);
	//void draw();
	void flushCommandQueue();

	// Factory for directx objects
	ID3D12Device *getDevice() const { return d3dDevice.Get() ; }

	// Execute commands
	ID3D12GraphicsCommandList *getCommandList() const { return commandList.Get(); }
	ID3D12CommandAllocator *getCommandAllocator() const { return commandAllocator.Get(); }
	ID3D12CommandQueue *getCommandQueue() const { return commandQueue.Get(); }

	// Drawing
	ID3D12Resource* currentBackBuffer()const;
	D3D12_CPU_DESCRIPTOR_HANDLE currentBackBufferView()const;
	D3D12_CPU_DESCRIPTOR_HANDLE depthStencilView()const;
	D3D12_VIEWPORT getScreenViewport() const { return  screenViewport; }
	D3D12_RECT getScissorRect() const { return scissorRect; }
	ID3D12Fence* getFence() const { return fence.Get(); }
	void swapChainMethod();
	UINT64 currentFence = 0;



	// Properties for PSO
	DXGI_FORMAT getBackBufferFormat() const { return backBufferFormat; }
	DXGI_FORMAT getDepthStencilFormat() const { return depthStencilFormat; }
	bool getMsaa4xState() const {	return msaa4xState; }
	UINT getMsaa4xQuality() const { return msaa4xQuality; }
	int getClientWidth() const { return clientWidth; }
	int getClientHeight() const { return clientHeight; }

private:
	void enableDebugModeIfNeeded();
	void createDevice();
	void createFence();
	void createDXGIFactory();
	void setUpDescriptorSizes();
	void setUp4xMSAAQuality();
	void createCommandObjects();
	void createSwapChain();
	void createRtvAndDsvDescriptorHeaps();

	void logAdapters();
	void logAdapterOutputs(IDXGIAdapter* adapter);
	void logOutputDisplayModes(IDXGIOutput* output, DXGI_FORMAT format);

	HINSTANCE applicationInstanceHandle  = nullptr;
	HWND mainWindowHandle = nullptr;
	WCHAR windowClass[MAX_LOADSTRING];

	bool      msaa4xState = false;
	UINT      msaa4xQuality = 0;

	Microsoft::WRL::ComPtr<ID3D12Device> d3dDevice;
	Microsoft::WRL::ComPtr<IDXGIFactory4> dxgiFactory;

	Microsoft::WRL::ComPtr<ID3D12Fence> fence;

	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;

	int currBackBuffer = 0;
	static const int swapChainBufferCount = 2;
	Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain;

	Microsoft::WRL::ComPtr<ID3D12Resource> swapChainBuffer[swapChainBufferCount];
	Microsoft::WRL::ComPtr<ID3D12Resource> depthStencilBuffer;

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;

	D3D12_VIEWPORT screenViewport;
	D3D12_RECT scissorRect;

	UINT rtvDescriptorSize = 0;
	UINT dsvDescriptorSize = 0;
	UINT cbvSrvUavDescriptorSize = 0;

	D3D_DRIVER_TYPE d3dDriverType = D3D_DRIVER_TYPE_HARDWARE;
	DXGI_FORMAT backBufferFormat = DXGI_FORMAT_R8G8B8A8_UNORM;
	DXGI_FORMAT depthStencilFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;

	int clientWidth = 800;
	int clientHeight = 600;
};
