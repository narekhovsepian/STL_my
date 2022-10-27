#pragma once
#include<queue>

namespace std_my
{

	template<typename _Ty>
	void buble_sort_iter(_Ty first, _Ty last) {
		for (_Ty i = first; i != last; i = std::next(i))
			for (_Ty j = first; j < i; j = std::next(j))
				if (*i < *j)
					std::iter_swap(i, j);
	}

	template<typename _Ty>
	void selection_sort_iter(_Ty first, _Ty last) {
		for (_Ty i = first; i != last; i = std::next(i)) {
			_Ty min = i;
			for (_Ty j = i; j != last; j = std::next(j)) {
				if (*min > *j)
					min = j;
			}
			std::iter_swap(i, min);
		}
	}

	template<typename _Ty>
	void insertion_sort_iter(_Ty first, _Ty last) {
		for (_Ty i = std::next(first); i != last; i = std::next(i)) {
			_Ty tmp = i;
			while (tmp != first) {
				if (*tmp < *std::prev(tmp))
					std::iter_swap(tmp, std::prev(tmp));
				tmp = std::prev(tmp);
			}
		}
	}

	template<typename _Ty>
	void counting_sort_iter(_Ty first, _Ty last) {
		std::vector<int> in(first, last);
		std::vector<int> tmp(*std::max_element(in.begin(), in.end()) + 1, 0);
		for (const auto& i : in)
			tmp[i] += 1;
		in.clear();
		for (int i{}; i != tmp.size(); ++i) {
			for (int j{}; j != tmp[i]; ++j) {
				in.push_back(i);
			}
		}
		std::copy(in.begin(), in.end(), first);
	}

	template<typename _Ty>
	void merge(_Ty first_begin, _Ty first_end,
		_Ty second_begin, _Ty second_end,
		_Ty out_begin) {


		while (first_begin < first_end && second_begin < second_end)
		{
			*out_begin++ = *first_begin < *second_begin ? *first_begin++
				: *second_begin++;
		}
		while (first_begin < first_end)
		{
			*out_begin++ = *first_begin++;
		}
		while (second_begin < second_end)
		{
			*out_begin++ = *second_begin++;
		}
	}

	template<typename _Ty>
	void merge_sort_iter(_Ty first, _Ty last) {
		int size = std::distance(first, last);
		if (size == 1)
			return;
		int half = size / 2;
		using type = typename std::iterator_traits<_Ty>::value_type;
		_Ty mid = first;
		std::advance(mid, half);
		std::vector<type> f_v(first, mid);
		std::vector<type> s_v(mid, last);
		merge_sort_iter(f_v.begin(), f_v.end());
		merge_sort_iter(s_v.begin(), s_v.end());
		merge(f_v.begin(), f_v.end(), s_v.begin(), s_v.end(), first);
	}




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

	template<typename _Ty>
	_Ty partition(_Ty first, _Ty last) {
		typename std::iterator_traits<_Ty>::value_type pivot = *first;
		_Ty out = first;

		for (_Ty tmp = std::next(first); tmp != last; tmp = std::next(tmp))
			if (*tmp < pivot)
				out = std::next(out),
				std::iter_swap(out, tmp);

		std::iter_swap(out, first);
		return out;
	}

	template<typename _Ty>
	void quick_sort(_Ty first, _Ty last) {
		if (std::distance(first, last) > 1) {
			_Ty pi = partition(first, last);
			quick_sort(first, pi);
			quick_sort(std::next(pi), last);
		}
	}

	template<typename _Ty>
	void radix_sort(_Ty first, _Ty last) {
		using type = typename std::iterator_traits<_Ty>::value_type;
		std::vector<type>vec(first, last);
		std::vector<std::vector<type>> bucket(10);
		int one_of_then{ 1 };
		for (int pow{}; pow != 10; ++pow) {
			for (const auto& i : vec)
				bucket[i / one_of_then % 10].push_back(i);
			vec.clear();
			for (int i{}; i != bucket.size(); ++i)
				vec.insert(vec.end(), bucket[i].begin(), bucket[i].end()),
				bucket[i].clear();
			one_of_then *= 10;
		}
		std::copy(vec.begin(), vec.end(), first);
	}

	template<typename _Ty>
	void heap_sort(_Ty first, _Ty last) {
		using type = typename std::iterator_traits<_Ty>::value_type;
		std::priority_queue<type> pq(first, last);
		while (!pq.empty()) {
			*first = pq.top();
			first = std::next(first);
			pq.pop();
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
	static void merge(T* array, const int& left, const int& mid, const int& right)
	{

		T* tempArray = new T[right - left + 1]{};
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
