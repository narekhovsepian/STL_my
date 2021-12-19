#pragma once
#include<new>


class Singleton
{
private:
	Singleton() = default;
	~Singleton() = default;

	Singleton(const Singleton&) = delete;
	Singleton& operator= (const Singleton&) = delete;

	void* operator new(std::size_t) = delete;
	void* operator new[](std::size_t) = delete;

	void operator delete(void*) = delete;
	void operator delete[](void*) = delete;

public:
	static Singleton& getInst()
	{
		static Singleton object;
		return object;
	}

};
/*
 int main()
 {
 	auto& s = Singleton::getInst();
 	return 0;
 }*/