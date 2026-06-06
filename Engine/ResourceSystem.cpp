#include "pch.h"

#include "ResourceSystem.h"

namespace CustomEngine
{
	// Private

	void ResourceSystem::deleteAllTextures()
	{
		std::vector<std::string> keysToDelete;

		for (const auto& texturePair : textures)
		{
			keysToDelete.push_back(texturePair.first);
		}

		for (const auto& key : keysToDelete)
		{
			deleteSharedTexture(key);
		}
	}

	void ResourceSystem::deleteAllTextureMaps()
	{
		std::vector<std::string> keysToDelete;

		for (const auto& textureMapPair : textureMaps)
		{
			keysToDelete.push_back(textureMapPair.first);
		}

		for (const auto& key : keysToDelete)
		{
			deleteSharedTextureMap(key);
		}
	}

	// Public

	ResourceSystem* ResourceSystem::getInstance()
	{
		static ResourceSystem resourceSystem;
		return &resourceSystem;
	}

	void ResourceSystem::loadTexture(const std::string& name, std::string sourcePath, bool isSmooth)
	{
		if (textures.find(name) != textures.end())
		{
			return;
		}

		sf::Texture* newTexture = new sf::Texture();
		if (newTexture->loadFromFile(sourcePath))
		{
			newTexture->setSmooth(isSmooth);
			textures.emplace(name, newTexture);
		}
	}

	const sf::Texture* ResourceSystem::getTextureShared(const std::string& name) const
	{
		return textures.find(name)->second;
	}

	sf::Texture* ResourceSystem::getTextureCopy(const std::string& name) const
	{
		return new sf::Texture(*textures.find(name)->second);
	}

	void ResourceSystem::deleteSharedTexture(const std::string& name)
	{
		auto texturePair = textures.find(name);

		sf::Texture* deletingTexure = texturePair->second;
		textures.erase(texturePair);
		delete deletingTexure;
	}

	void ResourceSystem::loadTextureMap(const std::string& name, std::string sourcePath, sf::Vector2u elementPixelSize, int totalElements, bool isSmooth)
	{
		if (textureMaps.find(name) != textureMaps.end())
		{
			return;
		}

		sf::Texture textureMap;
		if (textureMap.loadFromFile(sourcePath))
		{
			auto textureMapElements = new std::vector<sf::Texture*>();

			auto textureSize = textureMap.getSize();
			int loadedElements = 0;

			for (int y = 0; y <= static_cast<int>(textureSize.y - elementPixelSize.y); y += elementPixelSize.y)
			{
				if (loadedElements == totalElements)
				{
					break;
				}

				for (int x = 0; x <= static_cast<int>(textureSize.x - elementPixelSize.x); x += elementPixelSize.x)
				{
					if (loadedElements == totalElements)
					{
						break;
					}

					sf::Texture* newTextureMapElement = new sf::Texture();
					if (newTextureMapElement->loadFromFile(sourcePath, sf::IntRect(x, y, elementPixelSize.x, elementPixelSize.y)))
					{
						newTextureMapElement->setSmooth(isSmooth);
						textureMapElements->push_back(newTextureMapElement);
					}
					loadedElements++;
				}
			}

			textureMaps.emplace(name, *textureMapElements);
		}
	}

	const sf::Texture* ResourceSystem::getTextureMapElementShared(const std::string& name, int elementIndex) const
	{
		auto textureMap = textureMaps.find(name);
		auto textures = textureMap->second;
		return textures[elementIndex];
	}

	sf::Texture* ResourceSystem::getTextureMapElementCopy(const std::string& name, int elementIndex) const
	{
		auto textureMap = textureMaps.find(name);
		auto textures = textureMap->second;
		return new sf::Texture(*textures[elementIndex]);
	}

	int ResourceSystem::getTextureMapElementsCount(const std::string& name) const
	{
		auto textureMap = textureMaps.find(name);
		auto textures = textureMap->second;
		return static_cast<int>(textures.size());
	}

	void ResourceSystem::deleteSharedTextureMap(const std::string& name)
	{
		auto textureMap = textureMaps.find(name);
		auto deletingTextures = textureMap->second;

		for (int i = 0; i < deletingTextures.size(); i++)
		{
			delete deletingTextures[i];
		}

		textureMaps.erase(textureMap);
	}

	void ResourceSystem::clear()
	{
		deleteAllTextures();
		deleteAllTextureMaps();
	}
}