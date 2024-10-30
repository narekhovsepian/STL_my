#pragma once
#include<iostream>

namespace std_my
{

	template<typename T>
	class avl
	{
		static const int ALLOWED_IMBALANCE = 1;
		template<typename T>
		struct avlNode
		{
			T _info;
			avlNode<T> *lef_child;
			avlNode<T> *right_child;
			int height;
			avlNode(const T &info = T()) :_info(info), lef_child(nullptr), right_child(nullptr), height(0) { }

		};

		avlNode<T> *_root = nullptr;
		avlNode<T> *findLargestNode(avlNode<T> *) const;
		avlNode<T> *findSmallestNode(avlNode<T>*) const;
		void LL_rightRotate(avlNode<T> *&); //rotateWithLeftChild
		void RR_leftRotate(avlNode<T> *&);  // rotateWithRightChild
		void LR_rightleftRotate(avlNode<T> *&); 
		void RL_leftrightRotate(avlNode<T> *&);
		void balance(avlNode<T> *&);
		inline int height(const avlNode<T> *tree) const { return (tree) ? tree->height : -1; }
		inline int max(const int &a, const int& b) { return (a > b) ? a : b; }
		void inorderTraversal(const avlNode<T> *) const;
		void insert(avlNode<T> *&, const T &);
		void remove(avlNode<T> *&, const T &);
		void clear(avlNode<T> *&);
	public:
		avl() { }
		~avl();
		void inorder_print();
		void insert(const T&);
		void remove(const T&);
		void clear();

	};


	template<typename T>
	void avl<T>::balance(avlNode<T> *&tree)
	{
		if (tree == nullptr)
			return;


		if (height(tree->lef_child) - height(tree->right_child) > ALLOWED_IMBALANCE)
			if (height(tree->lef_child->lef_child) >= height(tree->lef_child->right_child))
				LL_rightRotate(tree);
			else RL_leftrightRotate(tree);
		else if (height(tree->right_child) - height(tree->lef_child) > ALLOWED_IMBALANCE)
			if (height(tree->right_child->right_child) >= height(tree->right_child->lef_child))
				RR_leftRotate(tree);
			else LR_rightleftRotate(tree);

		tree->height = max(height(tree->lef_child), height(tree->right_child)) + 1;

	}



	template<typename T>
	void avl<T>::LL_rightRotate(avlNode<T> *&tree)
	{
		avlNode<T> *x = tree->lef_child;
		tree->lef_child = x->right_child;
		x->right_child = tree;


		tree->height = max(height(tree->lef_child), height(tree->right_child)) + 1;
		x->height = max(height(x->lef_child), tree->height) + 1;
		tree = x;
		x = nullptr;

	}

	template<typename T>
	void avl<T>::RR_leftRotate(avlNode<T> *&tree)
	{
		avlNode<T> *x = tree->right_child;
		tree->right_child = x->lef_child;
		x->lef_child = tree;

		tree->height = max(height(tree->lef_child), height(tree->right_child)) + 1;
		x->height = max(height(x->right_child), tree->height) + 1;
		tree = x;
		x = nullptr;

	}

	template<typename T>
	void avl<T>::LR_rightleftRotate(avlNode<T> *&tree)
	{

		LL_rightRotate(tree->right_child);
		RR_leftRotate(tree);


	}

	template<typename T>
	void avl<T>::RL_leftrightRotate(avlNode<T> *&tree)
	{

		RR_leftRotate(tree->lef_child);
		LL_rightRotate(tree);


	}



	template<typename T>
	void avl<T>::clear(avlNode<T> *&tree)
	{
		if (tree)
			clear(tree->lef_child),
			clear(tree->right_child),
			delete tree, tree = nullptr;
	}


	template<typename T>
	avl<T>::~avl()
	{
		if (_root)
			clear(_root);
		_root = nullptr;
	}

	template<typename T>
	avl<T>::avlNode<T> *avl<T>::findSmallestNode(avlNode<T> *tree) const
	{
		if (!tree || !tree->lef_child)
			return tree;
		else return findSmallestNode(tree->lef_child);
	}

	template<typename T>
	avl<T>::avlNode<T> *avl<T>::findLargestNode(avlNode<T> *tree) const
	{
		if (!tree || !tree->right_child)
			return tree;
		else return findLargestNode(tree->right_child);
	}

	template<typename T>
	void avl<T>::inorderTraversal(const avlNode<T> *tree) const
	{
		if (tree)
			inorderTraversal(tree->lef_child),
			std::cout << tree->_info << "  ",
			inorderTraversal(tree->right_child);
		else return;

	}

	template<typename T>
	void avl<T>::inorder_print()
	{
		if (_root)
			inorderTraversal(_root);
		else return;
	}

	template<typename T>
	void avl<T>::insert(const T &item)
	{
		insert(_root, item);
	}

	template<typename T>
	void avl<T>::clear()
	{
		if (_root)
			clear(_root);
		else return;
	}

	template<typename T>
	void avl<T>::insert(avlNode<T> *&tree, const T &item)
	{
		if (!tree)
			tree = new avlNode<T>(item);
		else if (tree->_info > item)
			insert(tree->lef_child, item);
		else if (tree->_info < item)
			insert(tree->right_child, item);

		balance(tree); 
	}


	template<typename T>
	void avl<T>::remove(avlNode<T> *&tree, const T &item)
	{
		avlNode<T> *tmp = nullptr;
		if (tree)
			if (tree->_info > item)
				remove(tree->lef_child, item);
			else if (tree->_info < item)
				remove(tree->right_child, item);
			else if (tree->_info == item)
				if (tree->lef_child && tree->right_child)
					tree->_info = findSmallestNode(tree->right_child)->_info,
					remove(tree->right_child, tree->_info);
				else if (!tree->lef_child || !tree->right_child)
					tmp = tree, tree = (tree->lef_child) ? tree->lef_child : tree->right_child,
					delete tmp, tmp = nullptr;

		balance(tree);

	}

	template<typename T>
	void avl<T>::remove(const T&item)
	{
		if (_root)
			remove(_root, item);
		else return;
	}
}