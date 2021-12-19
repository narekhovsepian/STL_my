#pragma once





namespace std_my
{

	template<typename T>
	class deque
	{
		static const int max_size_array{ 9 };

		template<typename T>
		struct	deque_node
		{
			T _item{ };
			int	_array_node_size{ -1 };
			T* deq_array{ nullptr };
			deque_node<T>* _front;
			deque_node<T>* _rear;
			deque_node() :_fornt{ nullptr }, _rear{ nullptr }, deq_array{ new T[max_size_array]{ } } { }

		};

		deque_node<T>* _root{ nullptr };
	public:
		void push_front(const T&);


	};

	template<typename T>
	void deque<T>::push_front(const T& item)
	{
		deque_node<T>* tmp{ nullptr };
		if (!_root)
			_root = new deque_node<T>(),
			_root->deq_array[++_root->_array_node_size] = item;
		else if (_root->_array_node_size > 9)
		{

		}


	}








}
