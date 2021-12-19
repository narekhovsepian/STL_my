#pragma once
#include<stack>

namespace bst
{
	template<typename T>
	class bst
	{
		template<typename T>
		struct node
		{
			T _info;
			node<T>* left_child;
			node<T>* right_child;
			node(const T& info = T()) :_info{ info }, left_child{ nullptr }, right_child{ nullptr } { }
		};
		node<T>* _root{ nullptr };
		void insert(node<T>*, const T&);
	public:
		~bst();
		void insert(const T&);
		void inorder(node<T>*);
		void inorder_traversla_print() { inorder(_root); }
		void clear();

	};


	template<typename T>
	void bst<T>::insert(node<T>* tmp, const T& item)
	{
		node<T>* tree = tmp;
		while (tree != nullptr)
		{
			if (tree->_info > item)
				if (tree->left_child)
					tree = tree->left_child;
				else
				{
					tree->left_child = new node<T>{ item }; break;
				}
			else if (tree->_info < item)
				if (tree->right_child)
					tree = tree->right_child;
				else
				{
					tree->right_child = new node<T>{ item }; break;
				}
		}
	}

	template<typename T>
	void bst<T>::insert(const T& item)
	{
		if (!_root)
			_root = new node<T>(item);
		else insert(_root, item);
	}


	template<typename T>
	void bst<T>::inorder(node<T>* tree)
	{
		std::stack<node<T>*> st;
		node<T>* cur = tree;

		while (cur || st.empty() == false)
		{
			while (cur)
				st.push(cur),
				cur = cur->left_child;

			cur = st.top();
			std::cout << cur->_info << "  ";
			st.pop();

			cur = cur->right_child;
		}
	}


	template<typename T>
	void bst<T>::clear()
	{

		std::stack<node<T>*> st;
		node<T>* cut = _root;
		node<T>* tmp{ nullptr };
		st.push(cut);
		while (st.empty() == false)
		{
			tmp = st.top();
			st.pop();

			if (tmp->left_child)
				st.push(tmp->left_child);
			if (tmp->right_child)
				st.push(tmp->right_child);

			delete tmp;
		}

		_root = nullptr;
	}


	template<typename T>
	bst<T>::~bst()
	{

	}




}