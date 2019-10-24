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
	void selection_sort(T&& array)
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






	template<typename T>
	static  int partition(T* array, int low, int high)
	{
		int i = low - 1, k{};
		int pivot = array[high];

		for (int j = low; j != high; ++j)
			if (array[j] < pivot)
				++i, std::swap(array[i], array[j]);

		std::swap(array[i + 1], array[high]);

		return i + 1;
	}


	template<typename T>
	static void quick_sort(T* array, int low, int high)
	{
		int pi{};
		if (low < high)
			pi = partition(array, low, high),
			quick_sort(array, low, pi - 1),
			quick_sort(array, pi + 1, high);
	}



	template<typename T>
	static void merge(T* array,const int& left,const int& mid,const int& right)
	{

		T *tempArray = new T[right - left + 1]{};
		int pos{}, lpos = left, rpos = mid + 1;
		while (lpos <= mid && rpos <= right)
			if (array[lpos] < array[rpos])
				tempArray[pos++] = array[lpos++];
			else tempArray[pos++] = array[rpos++];


		while (lpos <= mid)
			tempArray[pos++] = array[lpos++];
		while (rpos <= right)
			tempArray[pos++] = array[rpos++];

		for (int iter{}; iter != pos; iter++)
			array[iter + left] = tempArray[iter];

		delete[]tempArray;
		return;
	}

	template<typename T>
	static void merge_sort(T* array, int left, int right)
	{
		int mid = (left + right) / 2;

		if (left < right)
			merge_sort(array, left, mid),
			merge_sort(array, mid + 1, right),
			merge(array, left, mid, right);
	}




}
