#pragma once
#include<iostream>


namespace std_my
{
	template<typename T>
	class forward_list
	{
		template<typename T>
		class iterator;
		template<typename T>
		struct Node
		{
			T _info = 0;
			Node<T> *_link = nullptr;
			Node(const T &info = T()) :_info(info), _link(nullptr) { }
			Node() :_info(0), _link(nullptr) { }
		};
		Node<T> *_root = nullptr;
		size_t size = 0;
	public:
		forward_list() : _root(nullptr) { }
		~forward_list();
		T &front();
		const T &front() const;
		void push_front(const T&);
		void push_front(T&&);
		void pop_front();
		void clear() noexcept;
		bool empty() const { return _root == nullptr; }
		void remove(const T&);
		forward_list<T> &operator=(forward_list<T> &&) noexcept;
		forward_list<T> &operator=(const forward_list<T> &);
		class iterator
		{

		};


	};

	template<typename T>
	void forward_list<T>::push_front(const T& el)
	{
		if (!_root)
		{
			_root = new Node<T>(el);

		}
		else
		{
			Node<T> *tmp = new Node<T>(el);
			tmp->_link = _root;
			_root = tmp;
		}
		++size;
	}

	template<typename T>
	void forward_list<T>::push_front(T &&el)
	{
		if (_root != nullptr)
			_root = new Node<T>(el);
		else
		{

			Node<T> *tmp = new Node<T>(el);
			tmp->_link = _root;
			_root = tmp;
		}
		++size;
	}

	template<typename T>
	T &forward_list<T>::front()
	{
		return _root->_info;
	}

	template<typename T>
	forward_list<T> &forward_list<T>::operator=(forward_list<T> &&other) noexcept
	{
		if (other._root != nullptr)
		{
			this->_root = std::move(other._root);
			this->size = std::move(other.size);
			other._root = nullptr;
			other.size = 0;

		}
		return *this;
	}

	template<typename T>
	forward_list<T> &forward_list<T>::operator=(const forward_list<T> &other)
	{
		if (this != &other)
		{

			forward_list<T>::Node<T> *t = other._root;
			if (this->_root == nullptr)
			{
				this->_root = new Node<T>(t->_info);

			}
			Node<T> *tmp = nullptr;
			Node<T> &tm = *this->_root;
			while ((t = t->_link) != nullptr)
			{

				tmp = new Node<T>(t->_info);
				this->_root->_link = tmp;
				this->_root = this->_root->_link;


			}
			this->_root = &tm;

		}
		return *this;
	}

	template<typename T>
	const T &forward_list<T>::front() const
	{
		return _root->_info;
	}

	template<typename T>
	void forward_list<T>::pop_front()
	{
		Node<T> *tmp = _root->_link;
		delete _root;
		_root = tmp;
		--size;
	}

	template<typename T>
	void forward_list<T>::clear() noexcept
	{
		Node<T> *tmp = nullptr;
		while (_root != nullptr)
		{
			tmp = _root->_link;
			delete _root;
			_root = tmp;
			--size;
		}

	}

	template<typename T>
	void forward_list<T>::remove(const T &el)
	{
		Node<T> *tmp = nullptr;
		Node<T> &tmp0 = *_root;
		while (_root->_info != el)
		{
			tmp = _root;
			_root = _root->_link;
		}
		tmp->_link = _root->_link;
		delete _root;
		_root = &tmp0;
	}


	template<typename T>
	forward_list<T>::~forward_list()
	{			
		if (_root != nullptr)
		{
			clear();
			_root = nullptr;
		}
	}





}