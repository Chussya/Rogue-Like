#pragma once

// This block necessary for export to another projects
#ifdef ENGINE_EXPORTS
	#define ENGINE_API __declspec(dllexport)
#else
	#define ENGINE_API __declspec(dllimport)
#endif // ENGINE_EXPORTS

#include <memory>
#include <vector>
#include <algorithm>

namespace CustomEngine
{
	class IObserver;

	class ENGINE_API IObservable : public std::enable_shared_from_this<IObservable>
	{
	public:
		void AddObserver(std::weak_ptr<IObserver> observer)
		{
			observers.push_back(observer);
		}

	protected:
		virtual void Emit()
		{
			auto self = shared_from_this();
			std::for_each(observers.begin(), observers.end(), [self](auto observer) {
				auto lockedObserver = observer.lock();
				if (lockedObserver)
				{
					lockedObserver->Notify(self);
				}
				});
		}
	private:
		std::vector<std::weak_ptr<IObserver>> observers;
	};

	class ENGINE_API IObserver
	{
	public:
		virtual void Notify(std::shared_ptr<IObservable> observable) = 0;
	};
}