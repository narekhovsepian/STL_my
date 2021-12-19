#pragma once



namespace std_my
{


	template<typename T>
	class heap
	{
		static const int max_size{ 100 };
		int _size{ -1 };
		T _heap[max_size]{};
		static int parent(const int& i) { return (i - 1) / 2; }
		static int left_child(const int& i) { return 2 * i + 1; }
		static int right_child(const int& i) { return 2 * i + 2; }

	public:
		heap() = default;
		~heap() {  }
		heap(const heap&) = delete;
		heap& operator =(const heap&) = delete;
		inline int size() const { return _size + 1; }
		inline bool is_Empty() const { return _size == -1 ? true : false; }
		void swap(T* a, T* b) { T tmp = *a; *a = *b, * b = tmp; }
		constexpr	inline bool less(const int& a, const int& b) const { return  _heap[a] > _heap[b]; }


		void print()
		{
			for (int i = 0; i != _size + 1; ++i)
				std::cout << _heap[i] << "  ";
		}


		void Min_heapify(int i)
		{
			int l = left_child(i);
			int r = right_child(i);
			int smallest = i;


			if (l <= _size && !less(l, i))
				smallest = l;

			if (r <= _size && !less(r, smallest))
				smallest = r;

			if (i != smallest)
				Min_heapify(smallest);

		}

		void Max_heapify(int i)
		{
			int l = left_child(i);
			int r = right_child(i);
			int smallest = i;

			if (l <= _size && less(l, i))
				smallest = l;

			if (r <= _size && less(r, smallest))
				smallest = r;

			if (smallest != i)
				swap(&_heap[i], &_heap[smallest]),
				Max_heapify(smallest);
		}


		void Build_Max_Heap()
		{
			for (int i = parent(_size); i != -1; --i)
				Max_heapify(i);
		}

		void Build_Min_Heap()
		{
			for (int i = parent(_size); i != -1; --i)
				Min_heapify(i);
		}




		void push(const T& item)
		{

			_heap[++_size] = item;

		}


		void Heap_Sort()
		{
			int s = _size;
			Build_Max_Heap();
			for (int i = _size; i != -1; --i)
				swap(&_heap[0], &_heap[i]),
				--_size,
				Max_heapify(0);

			_size = s;
		}



	};
}