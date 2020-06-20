#include "MaterialsDataProvider.h"
#include "d3dUtil.h"
#include <DirectXMath.h>

using namespace DirectX;

MaterialsDataProvider::MaterialsDataProvider()
{
	buildMaterials();
}

MaterialsDataProvider::~MaterialsDataProvider() = default;

void MaterialsDataProvider::buildMaterials()
{
	materials["grass"] = grassMaterial();
	materials["water"] = waterMaterial();
}

std::unique_ptr<Material> MaterialsDataProvider::grassMaterial()
{
	auto grass = std::make_unique<Material>();
	grass->Name = "grass";
	grass->MatCBIndex = 0;
	grass->DiffuseAlbedo = XMFLOAT4(0.2f, 0.6f, 0.2f, 1.0f);
	grass->FresnelR0 = XMFLOAT3(0.01f, 0.01f, 0.01f);
	grass->Roughness = 0.125f;
	return grass;
}

std::unique_ptr<Material> MaterialsDataProvider::waterMaterial()
{
	auto water = std::make_unique<Material>();
	water->Name = "water";
	water->MatCBIndex = 1;
	water->DiffuseAlbedo = XMFLOAT4(0.0f, 0.2f, 0.6f, 1.0f);
	water->FresnelR0 = XMFLOAT3(0.1f, 0.1f, 0.1f);
	water->Roughness = 0.0f;
	return water;
}

Material* MaterialsDataProvider::getMaterialForName(std::string name)
{
	return materials[name].get();
}

std::vector<Material*> MaterialsDataProvider::getMaterials()
{
	std::vector<Material*> result;
	for (auto& material : materials)
	{
		result.push_back(material.second.get());
	}
	return result;
}
