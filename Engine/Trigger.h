#pragma once

namespace CustomEngine
{
	class ColliderComponent;

	struct Trigger
	{
	private:
		ColliderComponent* first;
		ColliderComponent* second;

	public:
		Trigger(ColliderComponent* newFirst, ColliderComponent* newSecond) : first(newFirst), second(newSecond) {};
	};
}