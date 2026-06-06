#pragma once

namespace CustomEngine
{
	class GameObject;

	class Component
	{
	protected:
		GameObject* ptrGameObject;

	public:
		Component(GameObject* ptrGameObject);
		virtual ~Component();

		GameObject* getGameObject();

		virtual void update(float deltaTime) = 0;
		virtual void render() = 0;
	};
}