#pragma once

namespace std_my
{
	template<typename T>
	void bubble_sort(T&& array)
	{
		unsigned int size = sizeof(array) / sizeof(array[0]);
		for (unsigned int i = 0; i < size - 1; ++i)
		{
			for (unsigned int j = 0; j < size - i - 1; ++j)
			{
				if (array[j] > array[j + 1])
				{
					std::swap(array[j], array[j + 1]);
				}
				std::cout << array[i] << "    ";
			}
			std::cout << std::endl;
		}
	}
	template<typename T>
	void selection_sort(T &&array)
	{
		unsigned int size = sizeof(array) / sizeof(array[0]);
		size_t k = 0;
		for (size_t i = 0; i < size; i++)
		{
			 T tmp = array[i];
			for (size_t j = i; j < size - 1; j++)
			{
				if (tmp < array[j])
				{
					tmp = array[j];
					k = j;
				}
			}
			std::swap(array[i], array[k]);
		}
	}
}
