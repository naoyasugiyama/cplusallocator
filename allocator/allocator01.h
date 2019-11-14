#pragma once
#include <iostream>

template<typename T>
class allocator01
{
public:
	using value_type = T;

	//!> default ,copy , move 
	allocator01() {}
	//!> 
	template <typename U>
	allocator01(const allocator01<U>&) {}

	//!> memory
	T* allocate(std::size_t num)
	{
		std::size_t size = num * sizeof(T);
		TotalSize += size;
		std::cout << "allocate: " << typeid(T).name() << std::endl;
		return reinterpret_cast<T*>(std::malloc(size));
	}

	void deallocate(T* p, std::size_t num)
	{
		const std::size_t size = num * sizeof(T);
		static_cast<void>(num);
		std::free(p);
		TotalSize -= size;
		std::cout << "deallocate: " << typeid(T).name() << std::endl;
//		::operator delete(p);
	}

	std::size_t GetTotalMemorySize()
	{
		return TotalSize;
	}
private:
	static std::size_t TotalSize;
};

template <typename T>
std::size_t allocator01<T>::TotalSize = 0;

//!> î‰är
template<typename T1,typename T2>
bool operator==(const allocator01<T1>&, const allocator01<T2>&)
{
	return true;
}

template<typename T1, typename T2>
bool operator!=(const allocator01<T1>&, const allocator01<T2>&)
{
	return false;
}

