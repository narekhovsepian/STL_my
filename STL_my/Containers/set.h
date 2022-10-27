#pragma once


//#include "frbAbstract.h"
#include "../DataStructure/rbAbstract.h"




namespace std_my
{


	template<typename _Key_t >
	class set : protected alg::rbBase< _Key_t, char>
	{
	private:
		typedef alg::node< _Key_t, char> snode;
		typedef alg::rbBase< _Key_t, char> base_class;
		snode* _sroot{ nullptr }; //{ base_class::get_root() };

		

		void inorder_traversal(snode* tree) const
		{
			if (tree)
				inorder_traversal(tree->left_child),
				std::cout << tree->_key << "  ",
				inorder_traversal(tree->right_child);
		}

		snode* find_node(const _Key_t& item)
		{
			if (base_class::get_root())
			{
				snode* tree = base_class::get_root();
				while (tree)
					if (tree->_key == item)
						return tree;
					else if (tree->_key > item)
						if (tree->left_child)
							tree = tree->left_child;
						else return nullptr;
					else if (tree->_key < item)
						if (tree->right_child)
							tree = tree->right_child;
						else return nullptr;
			}		
			else return nullptr;

		}
		void clear(snode* tree)
		{
			if (tree)
				clear(tree->left_child),
				clear(tree->right_child),
				delete tree, tree = nullptr;
		}
	public:



		~set()
		{
			if (_sroot)
				clear(_sroot),
				_sroot = nullptr;
		}

		void clear()
		{
			if (_sroot)
				clear(_sroot),
				_sroot = nullptr;
		}

		_Key_t find(const _Key_t& item)
		{

			if (_sroot)
				if (find_node(item))
					std::cout << find_node(item)->_key << "\n";


		}

		void inordert_print() const
		{
			if (_sroot)
				inorder_traversal(_sroot);
		}

		void erase(const _Key_t& item)
		{
			snode* child{ nullptr };
			snode* find_item = find_node(item);

			if (!find_item)
				return;

			if (find_item->left_child && find_item->right_child)
			{
				snode* left_chidl_maxnode = base_class::max_node(find_item->left_child);
				find_item->_key = left_chidl_maxnode->_key;
				find_item = left_chidl_maxnode;
			}

			child = find_item->right_child ? find_item->left_child : find_item->right_child;

			if (base_class::node_color(find_item) == alg::Black)
				find_item->color = base_class::node_color(child),
				base_class::delete_case1(find_item);

			base_class::replace_node(find_item, child);

			if (!find_item->parent && child)
				child->color = alg::Black;

			delete find_item;
			find_item = nullptr;
		}





		void insert(const _Key_t& item)
		{

			snode* newnode = new snode{ item };
			if (!_sroot)
				base_class::set_root(newnode), _sroot = base_class::get_root();
			else
			{
				snode* root = _sroot;
				while (true)
				{
					if (item == root->_key)
					{
						delete newnode;
						newnode = nullptr;
						return;
					}
					else if (item < root->_key)
						if (root->left_child)
							root = root->left_child;
						else
						{
							root->left_child = newnode; break;
						}
					else if (item > root->_key)
						if (root->right_child)
							root = root->right_child;
						else
						{
							root->right_child = newnode; break;
						}

				}
				newnode->parent = root;

			}
			base_class::insert_case1(newnode);

			while (_sroot->parent)
				_sroot = _sroot->parent;
		}


	};

}
