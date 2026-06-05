#pragma once

#include <SFML/Graphics.hpp>

#include "Vector2D.h"

namespace CustomEngine
{
	enum class EGameWindowEvent
	{
		OnFocused = 1 << 0,
		OnClick = 1 << 1,
	};

	class Util
	{
	public:
		class UString
		{
		public:
			__declspec(dllexport) static std::string stringFormat(std::string s1, std::string s2, const char sym, const size_t length);
			__declspec(dllexport) static std::string stringCenter(std::string s, const char sym, const size_t length);

			__declspec(dllexport) static bool isNumeric(const std::string& str);
		};

		class UGraphic
		{
		public:
			enum class EItemOrigin
			{
				LeftTop = 0,
				MidTop,
				RightTop,
				Center,
				LeftBottom,
				MidBottom,
				RightBottom,
			};

			// Text methods

			__declspec(dllexport) static void initText(sf::Text& text, std::string s, const sf::Font& font, const sf::Color colorText, const unsigned int charSize);
			__declspec(dllexport) static void initText(sf::Text& text, std::string s, const sf::Font& font, const sf::Color colorText, const unsigned int charSize, const Vector2Df pos);

			// Sprite methods

			__declspec(dllexport) static void initSprite(sf::Sprite& sprite, float desiredWidth, float desiredHeight, const sf::Texture& texture);
			__declspec(dllexport) static void drawSprite(const sf::Sprite& sprite, sf::RenderWindow& window);
			__declspec(dllexport) static void setSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight);

			// General items methods

			template<class SFMLItem>
			__declspec(dllexport) static void setItemOrigin(SFMLItem& item, float originX, float originY)
			{
				sf::FloatRect localRect = item.getLocalBounds();
				item.setOrigin(originX * localRect.width, originY * localRect.height);
			}
		};
	};
}