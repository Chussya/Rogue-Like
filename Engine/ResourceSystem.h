#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace CustomEngine
{
	class ResourceSystem
	{
	private:
		std::map<std::string, sf::Texture*> textures;
		std::map<std::string, std::vector<sf::Texture*>> textureMaps;

		ResourceSystem() {}
		~ResourceSystem() {}

		ResourceSystem(ResourceSystem const&) = delete;
		ResourceSystem& operator= (ResourceSystem const&) = delete;

		void deleteAllTextures();
		void deleteAllTextureMaps();

	public:
		static ResourceSystem* getInstance();

		void loadTexture(const std::string& name, std::string sourcePath, bool isSmooth = true);
		const sf::Texture* getTextureShared(const std::string& name) const;
		sf::Texture* getTextureCopy(const std::string& name) const;
		void deleteSharedTexture(const std::string& name);

		void loadTextureMap(const std::string& name, std::string sourcePath, sf::Vector2u elementPixelSize, int totalElements, bool isSmooth = true);
		const sf::Texture* getTextureMapElementShared(const std::string& name, int elementIndex) const;
		sf::Texture* getTextureMapElementCopy(const std::string& name, int elementIndex) const;
		int getTextureMapElementsCount(const std::string& name) const;
		void deleteSharedTextureMap(const std::string& name);

		void clear();
	};
}