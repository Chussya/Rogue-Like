#pragma once

#include <random>

#include "Vector2D.h"

namespace CustomEngine
{
	class Math
	{
	public:
		const float PI{ 3.14159f };

		template <class Enum>
		class BitMask
		{
		private:
			int mask;

		public:
			__declspec(dllexport) BitMask(Enum mask) : mask { static_cast<int>(mask) } {}

			// Turn on mask without other changes
			__declspec(dllexport) void AddMask(Enum flag)
			{
				mask |= static_cast<int>(flag);
			}

			// Turn off mask without other changes
			__declspec(dllexport) void DeleteMask(Enum flag)
			{
				mask &= ~static_cast<int>(flag);
			}

			__declspec(dllexport) void SetMask(Enum mask)
			{
				this->mask = static_cast<int>(mask);
			}

			__declspec(dllexport) bool IsBitMaskOn(Enum checkMask)
			{
				return mask & static_cast<int>(checkMask);
			}
		};

		__declspec(dllexport) static int getRandNumTo(int num)
		{
			return std::rand() % num;
		}
	};
}