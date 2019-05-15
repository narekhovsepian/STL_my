#pragma once
#include<iostream>
#include<iterator>
namespace std_my
{
	template<typename T>
	class list
	{

		template<typename T>
		struct Node
		{

			T _info;
			Node<T> *_head;
			Node<T> *_rear;
			Node(const T &info = T()) :_info(info), _head(nullptr), _rear(nullptr) { }

		};
		const unsigned int _Max_size = 100;
		unsigned int _size = 0;
		Node<T> *root_head = nullptr;
		Node<T> *root_rear = nullptr;
	public:
		list() :root_head(nullptr), root_rear(nullptr) { }
		virtual	~list();
		T &front() { return  root_head->_info; }
		const T& front() const { return root_head->_info; }
		T& back() { return root_rear->_info; }
		const T& back() const { return root_rear->_info; }
		void insert(const T&);
		void push_front(const T&);
		void push_back(const T&);
		void pop_back();
		void pop_front();
		void remove(const T&);
		void clear() noexcept;
		bool empty() const noexcept { return  root_head == nullptr && root_rear == nullptr; }
		inline	unsigned int size() const { return _size + 1; }
		inline	unsigned int Max_size() const { return _Max_size; }
		void print();
		list<T> &operator=(const list<T> &);
		list<T> &operator=(list<T> &&) noexcept;
		class b_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
		{
			friend class list<T>;
			Node<T> *pointer;
			b_iterator(Node<T> *tmp) :pointer(tmp) { }
		public:
			T& operator*() { return pointer->_info; }
			b_iterator &operator++() { pointer = pointer->_head; return *this; }
			b_iterator &operator--() { pointer = pointer->_rear; return *this; }
			b_iterator operator++(T) { b_iterator tmp = *this; pointer = pointer->_head; return tmp; }
			b_iterator operator--(T) { b_iterator tmp = *this; pointer = pointer->_rear; return tmp; }
			bool operator==(const b_iterator &other) const { return this->pointer == other->pointer; }
			bool operator!=(const b_iterator &other) const { return this->pointer != other.pointer; }
			b_iterator() :pointer(nullptr) { }

		};
		class cb_iterator :public std::iterator<std::bidirectional_iterator_tag, int, ptrdiff_t, const T*, const T&>
		{
			friend class list<T>;
			const Node<T> *pointer;
			cb_iterator(Node<T> *tmp) :pointer(tmp) { }
		public:
			cb_iterator() :pointer(nullptr) { }
			cb_iterator(const cb_iterator &i) :pointer(i.pointer) { }
			const T &operator*() { return pointer->_info; }
			cb_iterator &operator++() { pointer = pointer->_head; return *this; }
			cb_iterator operator++(T) { cb_iterator tmp = *this; pointer = pointer->_head; return tmp; }
			cb_iterator operator--() { pointer = pointer->_head; return *this; }
			cb_iterator operator--(T) { cb_iterator tmp = *this; pointer = pointer->_rear; return tmp; }
			bool operator==(const cb_iterator &other) const { return this->pointer == other.pointer; }
			bool operator!=(const cb_iterator &other) const { return this->pointer != other.pointer; }

		};
		b_iterator begin() { return b_iterator(this->root_head); }
		b_iterator end() { return b_iterator(); }
		cb_iterator cbegin()const { return cb_iterator(this->root_head); }
		cb_iterator cend() const { return cb_iterator(); }


		friend bool operator == (cb_iterator a, b_iterator b) { return *a == *b; }
		friend bool operator != (cb_iterator a, b_iterator b) { return *a != *b; }
		friend bool operator == (b_iterator a, cb_iterator b) { return *a == *b; }
		friend bool operator != (b_iterator a, cb_iterator b) { return *a != *b; }

	};

	template<typename T>
	list<T> &list<T>::operator=(const list<T> &other)
	{
		if (this != &other)
		{
			if (this->root_head == nullptr)
			{
				this->root_head = new Node<T>(other.root_head->_info);
				this->root_rear = this->root_head;
			}
			Node<T> *t_head = other.root_head;
			while ((t_head = t_head->_head) != nullptr)
			{
				Node<T> *tmp = new Node<T>(t_head->_info);
				tmp->_head = root_head;
				root_head->_rear = tmp;
				root_head = tmp;

			}
		}
		return *this;
	}

	template<typename T>
	list<T> &list<T>::operator=(list<T> &&other) noexcept
	{
		if (&other != nullptr)
		{
			this->root_head = std::move(other.root_head);
			this->root_rear = std::move(other.root_rear);
			this->_size = std::move(other._size);
			other._size = 0;
			other.root_head = nullptr;
			other.root_rear = nullptr;
		}
		return *this;
	}










	template<typename T>
	void list<T>::push_front(const T& el)
	{
		if (_size <= _Max_size) {
			Node<T> *tmp = new Node<T>(el);
			if (!root_head)
			{
				root_head = tmp;
				root_rear = tmp;
			}
			else
			{
				tmp->_head = root_head;
				root_head->_rear = tmp;
				root_head = tmp;
			}
			++_size;
		}

	}

	template<typename T>
	void list<T>::push_back(const T& el)
	{
		if (_size <= Max_size)
		{
			Node<T> *tmp = new Node<T>(el);
			if (!root_rear)
			{
				root_rear = tmp;
				root_head = tmp;
			}
			else
			{
				tmp->_rear = root_rear;
				root_rear->_head = tmp;
				root_rear = tmp;

			}
			++_size;
		}
	}
	template<typename T>
	void list<T>::pop_front()
	{
		if (_size != 0)
		{
			Node<T> &tmp = *root_head;
			root_head = root_head->_head;
			root_head->_rear = nullptr;
			delete &tmp;
			--_size;
		}
	}
	template<typename T>
	void list<T>::pop_back()
	{
		if (_size != 0)
		{
			Node<T> &tmp = *root_rear;
			root_rear = root_rear->_rear;
			root_rear->_head = nullptr;
			delete &tmp;
			--_size;
		}
	}
	template<typename T>
	void list<T>::clear() noexcept
	{

		while (root_head != nullptr)
		{
			Node<T>	&tmp = *root_head;
			root_head = root_head->_head;
			if (root_head != nullptr)
			{
				root_head->_rear = nullptr;
			}
			delete &tmp;
			--_size;
		}

	}

	template<typename T>
 	list<T>::~list() 
	{
		if (root_head != nullptr && root_rear != nullptr)
		{
			clear();
		}
	}





	template<typename T>
	void list<T>::print()
	{
		Node<T> *r = root_rear;
		while (root_rear != nullptr)
		{
			std::cout << root_rear->_info << "  ";
			root_rear = root_rear->_rear;
			//_root = _root->_rear;
		}
		root_rear = r;
		Node<T> *h = root_head;
		std::cout << "\n\n\n";
		while (root_head != nullptr)
		{
			std::cout << root_head->_info << "  ";
			root_head = root_head->_head;
		}
		root_head = h;
	}



}