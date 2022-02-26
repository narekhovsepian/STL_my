#pragma once
#include<iostream>

namespace bst
{
	template<typename T>
	class bst
	{
	private:
		template<typename T>
		struct Node
		{
			friend class bst<T>;
			T _info;
			Node<T> *right_child;
			Node<T> *left_child;
			Node() { }
			Node(const T &info = T()) : _info(info), right_child(nullptr), left_child(nullptr) { }
		};
		Node<T> *_root = nullptr;
		void insert(Node<T> *, const T&);
		void inorder_traversal_LNR(const Node<T>*);
		void preorder_traversal_NLR(const Node<T>*);
		void postorder_traversal_LRN(const Node<T>*);
		int height(Node<T>*);
		bool is_balanced(Node<T>*);
		void NTH_preorder_print(Node<T> *, int, int&);
		void levelorder_traversal(Node<T>*);
		void search_recursive(const Node<T>*, const T&);
		void remove_recursive(Node<T>*&, const T&);
		Node<T> *findMaxNode(Node<T>*) const;
		Node<T> *findMinNode(Node<T>*) const;
		const int totalNode(Node<T>*) const;
		const int totalInternalNode(Node<T>*) const;
		const int totalExtrenalNode(Node<T>*) const;
		void clearTree(Node<T>*&);
	public:

		bst() { }
		void insert(const T&);
		int height();
		bool is_balanced();
		void level_order_traversal();
		void inorder_print();
		void preorder_print();
		void postorder_print();
		void NTH_preorder_print(int);
		void serach_recursive(const T&);
		void remove_recursive(const T&);
		const T& MaxValue() const;
		const T& MinValue() const;
		const int totalNode() const;
		const int totalInternalNode() const;
		const int totalExtrenalNode() const;
		void clear();
		~bst();

	};
	template<typename T>
	const int bst<T>::totalNode(Node<T>* r) const
	{
		if (r == nullptr)
			return 0;
		else return totalNode(r->left_child) + totalNode(r->right_child) + 1;

	}

	template<typename T>
	const int bst<T>::totalNode() const
	{
		if (_root != nullptr)
			return totalNode(_root);
		else return 0;
	}

	template<typename T>
	const int bst<T>::totalInternalNode(Node<T>* r) const
	{
		if (r == nullptr)
			return 0;
		if (!r->left_child && !r->right_child)
			return 0;
		else return totalInternalNode(r->left_child) + totalInternalNode(r->right_child) + 1;
	}

	template<typename T>
	const int bst<T>::totalInternalNode() const
	{
		if (_root)
			return 	totalInternalNode(_root);
	}

	template<typename T>
	const int bst<T>::totalExtrenalNode(Node<T> *r) const
	{
		if (r == nullptr)
			return 0;
		if (r->left_child == nullptr && r->right_child == nullptr)
			return 1;
		else return totalExtrenalNode(r->left_child) + totalExtrenalNode(r->right_child) + 1;
	}

	template<typename T>
	const int bst<T>::totalExtrenalNode() const
	{
		if (_root)
			return totalExtrenalNode(_root);
	}

	template<typename T>
	void bst<T>::clearTree(Node<T> *&r)
	{
		if (r)
		{
			clearTree(r->left_child);
			clearTree(r->right_child);
			delete r;
			r = nullptr;
		}

	}

	template<typename T>
	bst<T>::~bst()
	{
		if (_root)
			clearTree(_root);
	}

	template<typename T>
	void bst<T>::clear()
	{
		if (_root)
			clearTree(_root);
	}






	template<typename T>
	void bst<T>::NTH_preorder_print(int index)
	{
		int count = 0;
		NTH_preorder_print(_root, index, count);
	}

	template<typename T>
	void bst<T>::NTH_preorder_print(Node<T> *node, int index, int& count)
	{
		if (node != nullptr)
		{
			count++;
			if (count == index)
			{
				std::cout << "  " << node->_info;
			}
			NTH_preorder_print(node->left_child, index, count);
			NTH_preorder_print(node->right_child, index, count);
		}
	}

	template<typename T>
	void bst<T>::serach_recursive(const T& item)
	{
		if (item == _root->_info)
		{
			std::cout << "find-  " << _root->_info;
		}
		else
			search_recursive(_root, item);
	}

	template<typename T>
	inline void bst<T>::remove_recursive(const T &item)
	{
		if (_root)
			remove_recursive(_root, item);
		else return;
	}

	template<typename T>
	void bst<T>::search_recursive(const Node<T> *r, const T &item)
	{
		if (r->_info == item)
		{
			std::cout << "find-  " << r->_info;
			return;
		}
		if (r->_info > item)
		{
			if (r->left_child)
			{
				search_recursive(r->left_child, item);
			}
			else if (r->right_child)
			{
				search_recursive(r->right_child, item);
			}
		}
		else if (r->_info < item)
		{
			if (r->right_child)
			{
				search_recursive(r->right_child, item);
			}
			else if (r->left_child)
			{
				search_recursive(r->left_child, item);
			}
		}

	}

	template<typename T>
	bst<T>::Node<T> *bst<T>::findMaxNode(Node<T> *r) const
	{
		if (!r || !r->right_child)
			return r;
		else return findMaxNode(r->right_child);
	}

	template<typename T>
	bst<T>::Node<T> *bst<T>::findMinNode(Node<T>*r) const
	{
		if (!r || !r->left_child)
			return r;
		else return findMinNode(r->left_child);
	}
	template<typename T>
	const T& bst<T>::MaxValue() const
	{
		return  findMaxNode(_root)->_info;
	}
	template<typename T>
	const T& bst<T>::MinValue() const
	{
		return  findMinNode(_root)->_info;
	}


	template<typename T>
	void bst<T>::remove_recursive(Node<T> *&r, const T& item)
	{
		Node<T> *tmp = nullptr;

		if (r)
			if (r->_info > item)
				if (r->left_child)
					remove_recursive(r->left_child, item);
				else return;
			else if (r->_info < item)
				if (r->right_child)
					remove_recursive(r->right_child, item);
				else return;
			else if (r->_info == item)
				if (!r->left_child && !r->right_child)
					delete *&r, r = nullptr;
				else if (!r->left_child || !r->right_child)
					tmp = r, r = (!r->left_child) ? r->right_child : r->right_child, delete *&tmp, tmp = nullptr;
				else if (r->left_child && r->right_child)
					tmp = findMinNode(r->right_child),
					r->_info = tmp->_info,
					remove_recursive(r->right_child, tmp->_info);

	}


	template<typename T>
	void bst<T>::insert(Node<T> *r, const T& value)
	{
		if (value == r->_info)
			return;
		else if (r->_info > value)
		{
			if (r->left_child != nullptr)
				insert(r->left_child, value);
			else r->left_child = new Node<T>(value);
		}
		else if (r->_info < value)
		{
			if (r->right_child != nullptr)
				insert(r->right_child, value);
			else r->right_child = new Node<T>(value);
		}

	}
	template<typename T>
	void bst<T>::insert(const T& value)
	{
		if (_root == nullptr)
			_root = new Node<T>(value);
		else insert(_root, value);
	}

	template<typename T>
	bool bst<T>::is_balanced(){
		if (_root)
			is_balanced(_root);
		else return 1;
	}


	template<typename T>
	int bst<T>::height(Node<T> *r)
	{
		if (r == nullptr)
			return 0;
		else
		{
			int l_h = height(r->left_child);
			int r_h = height(r->right_child);

			/*if (l_h > r_h)
				return l_h + 1;
			else return r_h + 1;
			*/
			return (l_h > r_h) ? l_h + 1 : r_h + 1;
		}
	}


	template<typename T>
	bool bst<T>::is_balanced(Node<T>* r) {
		if (!r)
			return true;

		int _l = height(r->left_child);
		int _r = height(r->right_child);

		if (std::abc(_l - _r) <= 1 && is_balanced(r->left_child) && is_balanced(r->right_child))
			return true;

		return false;
	}


	template<typename T>
	int bst<T>::height()
	{
		return height(_root);
	}


	template<typename T>
	void bst<T>::level_order_traversal()
	{
		level_order_traversal(_root);
	}



	template<typename T>
	void bst<T>::inorder_print()
	{
		inorder_traversal_LNR(_root);
	}

	template<typename T>
	void bst<T>::preorder_print()
	{
		preorder_traversal_NLR(_root);
	}

	template<typename T>
	void bst<T>::postorder_print()
	{
		postorder_traversal_LRN(_root);
	}


	template<typename T>
	void  bst<T>::inorder_traversal_LNR(const Node<T> *r)
	{
		if (r != nullptr)
		{
			inorder_traversal_LNR(r->left_child);
			std::cout << r->_info << "  ";
			inorder_traversal_LNR(r->right_child);
		}

	}
	template<typename T>
	void bst<T>::preorder_traversal_NLR(const Node<T> *r)
	{
		if (r != nullptr)
		{
			std::cout << r->_info << "  ";
			preorder_traversal_NLR(r->left_child);
			preorder_traversal_NLR(r->right_child);
		}
	}

	template<typename T>
	void bst<T>::postorder_traversal_LRN(const Node<T> *r)
	{
		if (r != nullptr)
		{
			postorder_traversal_LRN(r->left_child);
			postorder_traversal_LRN(r->right_child);
			std::cout << r->_info << "  ";
		}
	}









}