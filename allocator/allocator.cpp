// allocator.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "allocator01.h"

#include <vector>
#include <list>

void g_strcopy_s(char* dest, size_t size, const char* src);

void g_strcopy_s(char* dest, size_t size, const char* src)
{
	uint32_t i = 0;//const char size ... 
	for (;;)
	{
		if (src[i] == '\0') {
			break;
		}
		++i;
	}
	std::cout << "src_size:strlen" << strlen(src) << std::endl;

	std::cout << "src_size:" << i << std::endl;
	size_t copysize = size - 1;//'\0'

	memcpy(dest, src, copysize);
	dest[copysize] = '\0';

}


int main()
{
#if 0
	using IntAllocator = allocator01<int>;
	using IntAllocatorVector = std::vector<int, IntAllocator>;

	IntAllocator myAllocator;

	// 「サイズ」10 で初期化
	IntAllocatorVector v(10, 0, myAllocator);
	std::cout << myAllocator.GetTotalMemorySize() << std::endl;

	// 100個の要素を追加
	for (int i = 0; i < 100; ++i) {
		v.push_back(0);
	}
	std::cout << myAllocator.GetTotalMemorySize() << std::endl;

	// 要素をクリア
	// 「サイズ」は 0 になるが、「容量」は変わらない。
	v.clear();
	std::cout << myAllocator.GetTotalMemorySize() << std::endl;

	// 「容量」も 0 に切りつめる
	v.shrink_to_fit();
	std::cout << myAllocator.GetTotalMemorySize() << std::endl;
	
#endif

	allocator01<std::string> a;
	auto rawptr = a.allocate(1);
	std::cout << "stringsize:" << a.GetTotalMemorySize() << std::endl;

	char buf[5];
	g_strcopy_s(buf, 5, "abcdefghijk");
	std::cout << "buf:" << buf << std::endl;

	getchar();
    return 0;
}

