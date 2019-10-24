#pragma once
#include<stack>
#include<queue>
namespace rb_bst
{

	enum rbcolour { Red = true, Black = false };
	template<typename T>
	class rb_bst
	{
		template<typename T>
		struct rb_node
		{
			T _info;
			rb_node<T>* left_child;
			rb_node<T>* right_child;
			rb_node<T>* parent;
			rbcolour colour;
			rb_node(const T& info = T{}) : _info(info), left_child{ nullptr }, right_child{ nullptr }, parent{ nullptr }, colour{ Red } { }
			rb_node() : left_child{ nullptr }, right_child{ nullptr }, parent{ nullptr }, colour{ Red } { }

		};


		using stptr = std::queue<rb_node<T>*>;
		rb_node<T>* _root{ nullptr };
		rb_node<T>* min_node{ nullptr };
		rb_node<T>* max_node{ nullptr };
		void postorder_travsersal(rb_node<T>*&);
	public:
		~rb_bst();
		void insert(const T&);
		rb_node<T>* get_root() { return _root; }
		void clear();
		void inorder_traversal(rb_node<T>*);
		void inorder_traversal_print();

	};

	template<typename T>
	rb_bst<T>::~rb_bst()
	{
		if (_root)
			postorder_travsersal(_root),
			_root = nullptr, min_node = nullptr, max_node = nullptr;
	}



	template<typename T>
	void rb_bst<T>::insert(const T& item)
	{
		rb_node<T>* tree{ nullptr };
		if (!_root)
			_root = new rb_node<T>{ item }, _root->colour = Black, min_node = max_node = _root;
		else
		{
			tree = _root;
			rb_node<T>* tmp{ nullptr };
			while (tree)
			{
				tmp = tree;
				if (tree->_info > item)
					tree = tree->left_child;
				else tree = tree->right_child;

			}

			if (tmp->_info > item)
				tmp->left_child = new rb_node<T>{ item }, tmp->left_child->parent = tmp;
			else tmp->right_child = new  rb_node<T>{ item }, tmp->right_child->parent = tmp;

			if (item < min_node->_info)
				min_node = tmp->left_child;
			else if (item > max_node->_info)
				max_node = tmp->right_child;
		}
	}

	template<typename T>
	void rb_bst<T>::clear()
	{
		if (_root)
			postorder_travsersal(_root),
			_root = nullptr, min_node = nullptr, max_node = nullptr;
	}

	template<typename T>
	void rb_bst<T>::inorder_traversal_print()
	{
		if (_root)
			inorder_traversal(_root);
	}




	template<typename T>
	void rb_bst<T>::inorder_traversal(rb_node<T>* tree)
	{
		if (!tree) return;
		rb_node<T>* vertex = tree, * father{ nullptr };

		while (1) {
			if (vertex->left_child) { vertex = vertex->left_child; continue; }
			std::cout << vertex->_info << "  ";
			if (vertex->right_child) { vertex = vertex->right_child; continue; }

			for (father = vertex->parent; father != nullptr; vertex = father, father = vertex->parent)


				if (father->left_child == vertex) {

					std::cout << father->_info << "  ";
					if (father->right_child) break;
				}

			if (!father) return;

			vertex = father->right_child;

		}
	}

	template<typename T>
	void rb_bst<T>::postorder_travsersal(rb_node<T>*& tree)
	{
		if (tree)
			postorder_travsersal(tree->left_child),
			postorder_travsersal(tree->right_child),
			delete tree, tree = nullptr;
	}





}