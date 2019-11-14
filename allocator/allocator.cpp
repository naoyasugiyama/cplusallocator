// allocator.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
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

	// �u�T�C�Y�v10 �ŏ�����
	IntAllocatorVector v(10, 0, myAllocator);
	std::cout << myAllocator.GetTotalMemorySize() << std::endl;

	// 100�̗v�f��ǉ�
	for (int i = 0; i < 100; ++i) {
		v.push_back(0);
	}
	std::cout << myAllocator.GetTotalMemorySize() << std::endl;

	// �v�f���N���A
	// �u�T�C�Y�v�� 0 �ɂȂ邪�A�u�e�ʁv�͕ς��Ȃ��B
	v.clear();
	std::cout << myAllocator.GetTotalMemorySize() << std::endl;

	// �u�e�ʁv�� 0 �ɐ؂�߂�
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

