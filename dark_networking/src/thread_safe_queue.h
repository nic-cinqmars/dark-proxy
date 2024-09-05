#pragma once
#include <mutex>
#include <deque>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue
{
private:
	std::mutex queueMutex;
	std::deque<T> deQueue;
	std::condition_variable blocking;
	std::mutex blockingMutex;
public:
	ThreadSafeQueue() = default;
	ThreadSafeQueue(const ThreadSafeQueue<T>&) = delete;
	~ThreadSafeQueue()
	{
		clear();
	}

	const T& front()
	{
		std::scoped_lock lock(queueMutex);
		return deQueue.front();
	}

	const T& back()
	{
		std::scoped_lock lock(queueMutex);
		return deQueue.back();
	}

	void push_back(const T& item)
	{
		std::scoped_lock lock(queueMutex);
		deQueue.emplace_back(std::move(item));

		std::unique_lock<std::mutex> uniqueLock(blockingMutex);
		blocking.notify_one();
	}

	void push_front(const T& item)
	{
		std::scoped_lock lock(queueMutex);
		deQueue.emplace_front(std::move(item));

		std::unique_lock<std::mutex> uniqueLock(blockingMutex);
		blocking.notify_one();
	}

	bool empty()
	{
		std::scoped_lock lock(queueMutex);
		return deQueue.empty();
	}

	size_t size()
	{
		std::scoped_lock lock(queueMutex);
		return deQueue.size();
	}

	void clear()
	{
		std::scoped_lock lock(queueMutex);
		deQueue.clear();
	}

	T pop_front()
	{
		std::scoped_lock lock(queueMutex);
		T item = std::move(deQueue.front());
		deQueue.pop_front();
		return item;
	}

	T pop_back()
	{
		std::scoped_lock lock(queueMutex);
		T item = std::move(deQueue.back());
		deQueue.pop_back();
		return item;
	}

	void wait()
	{
		while(empty())
		{
			std::unique_lock<std::mutex> lock(blockingMutex);
			blocking.wait(lock);
		}
	}
};