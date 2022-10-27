#pragma once


namespace alg
{


	template<typename _Key_t, typename _Value_t >
	class rbBase;

	enum rbcolor { Red = true, Black = false };

	template<typename _Key_t, typename _Value_t >
	struct node
	{
		//template<typename _Key_t, typename _Value_t >
		friend	class rbBase<_Key_t,_Value_t>;

		typedef node<_Key_t, _Value_t> _Mytype_t;
		_Key_t _key{ };
		_Value_t _value{ };

		_Mytype_t* parent;
		_Mytype_t* left_child;
		_Mytype_t* right_child;
		rbcolor color;
		node(const _Key_t& key, const _Value_t& value) : _key{ key }, _value{ value }, parent{ nullptr }, left_child{ nullptr }, right_child{ nullptr }, color{ Red }{ }
		node(const _Key_t& key) : _key{ key }, parent{ nullptr }, left_child{ nullptr }, right_child{ nullptr }, color{ Red }{ }

	};




	template<typename _Key_t, typename _Value_t >
	class rbBase
	{
		typedef node < _Key_t, _Value_t> _Mytype_t;
	protected:

		_Mytype_t* _root{ nullptr };
		inline _Mytype_t*& get_root() { return  _root; }
		inline	void set_root(_Mytype_t* tree) { _root = tree; }
		inline rbcolor node_color(_Mytype_t* tree) { return !tree ? Black : tree->color; }

	public:

		virtual ~rbBase() { if (_root) 	_root = nullptr; }
		rbBase() { }

		//node<T>* grandparent(node<T>*);
		//node<T>* uncle(node<T>*);
		//node<T>* sibling(node<T>*);
		//void rotate_left(node<T>*);
		//void rotate_right(node<T>*);
		//void replace_node(node<T>*, node<T>*);

		//node<T>* max_node(node<T>*);
		//node<T>* min_node(node<T>*);
		/*
		void insert_case1(node<T>*);
		void insert_case2(node<T>*);
		void insert_case3(node<T>*);
		void insert_case4(node<T>*);
		void insert_case5(node<T>*);

		void delete_case1(node<T>*);
		void delete_case2(node<T>*);
		void delete_case3(node<T>*);
		void delete_case4(node<T>*);
		void delete_case5(node<T>*);
		void delete_case6(node<T>*);
		*/


		_Mytype_t* grandparent(_Mytype_t* tree)
		{
			if (tree && tree->parent)
				return tree->parent->parent;
			else return nullptr;
		}



		_Mytype_t* sibling(_Mytype_t* tree)
		{
			return (tree == tree->parent->left_child) ? tree->parent->right_child : tree->parent->left_child;
		}


		_Mytype_t* uncle(_Mytype_t* tree)
		{
			return sibling(tree->parent);
		}




		void  rotate_left(_Mytype_t* tree)
		{
			_Mytype_t* r = tree->right_child;
			replace_node(tree, r);
			tree->right_child = r->left_child;

			if (r->left_child)
				r->left_child->parent = tree;

			r->left_child = tree;
			tree->parent = r;
		}

		void rotate_right(_Mytype_t* tree)
		{
			_Mytype_t* l = tree->left_child;
			replace_node(tree, l);
			tree->left_child = l->right_child;

			if (l->right_child)
				l->right_child->parent = tree;

			l->right_child = tree;
			tree->parent = l;
		}

		void replace_node(_Mytype_t* old, _Mytype_t* newn)
		{
			if (!old->parent)
				_root = newn;
			else
				if (old == old->parent->left_child)
					old->parent->left_child = newn;
				else old->parent->right_child = newn;

			if (newn)
				newn->parent = old->parent;
		}



		_Mytype_t* max_node(_Mytype_t* tree)
		{
			if (!tree || !tree->right_child)
				return tree;
			else return max_node(tree->right_child);
		}


		_Mytype_t* min_node(_Mytype_t* tree)
		{
			if (!tree || !tree->left_child)
				return tree;
			else return min_node(tree->left_child);
		}




		void delete_case6(_Mytype_t* tree)
		{
			_Mytype_t* s = sibling(tree);

			s->color = node_color(tree->parent);
			tree->parent->color = Black;

			if (tree == tree->parent->left_child)
				s->right_child->color = Black,
				rotate_left(tree->parent);
			else
				s->left_child->color = Black,
				rotate_right(tree->parent);

		}




		void delete_case5(_Mytype_t* tree)
		{
			_Mytype_t* s = sibling(tree);
			if (tree == tree->parent->left_child &&
				node_color(s) == Black &&
				node_color(s->left_child) == Red &&
				node_color(s->right_child) == Black)

				s->color = Red,
				s->left_child->color = Black,
				rotate_right(s);

			else if (tree == tree->parent->right_child &&
				node_color(s) == Black &&
				node_color(s->right_child) == Red &&
				node_color(s->left_child) == Black)

				s->color = Red,
				s->right_child->color = Black,
				rotate_left(s);

			delete_case6(tree);
		}




		void delete_case4(_Mytype_t* tree)
		{
			_Mytype_t* s = sibling(tree);
			if (node_color(tree->parent) == Red &&
				node_color(s) == Black &&
				node_color(s->left_child) == Black &&
				node_color(s->right_child) == Black)

				s->color = Red,
				tree->parent->color = Black;
			else
				delete_case5(tree);
		}



		void delete_case3(_Mytype_t* tree)
		{
			_Mytype_t* s = sibling(tree);
			if (node_color(tree->parent) == Black &&
				node_color(s) == Black &&
				node_color(s->left_child) == Black &&
				node_color(s->right_child) == Black)


				s->color = Red,
				delete_case1(tree->parent);
			else
				delete_case4(tree);

		}




		void delete_case2(_Mytype_t* tree)
		{
			if (node_color(sibling(tree)) == Red)
			{
				tree->parent->color = Red;
				sibling(tree)->color = Black;
				if (tree == tree->parent->left_child)
					rotate_left(tree->parent);
				else
					rotate_right(tree->parent);
			}

			delete_case3(tree);
		}



		void delete_case1(_Mytype_t* tree)
		{
			if (!tree->parent)
				return;
			else
				delete_case2(tree);
		}


		void insert_case5(_Mytype_t* tree)
		{
			tree->parent->color = Black;
			_Mytype_t* g = grandparent(tree);
			g->color = Red;

			if (tree == tree->parent->left_child && tree->parent == g->left_child)
				rotate_right(g);
			else
				rotate_left(g);
		}




		void insert_case4(_Mytype_t* tree)
		{
			if (tree == tree->parent->right_child && tree->parent == grandparent(tree)->left_child)
				rotate_left(tree->parent),
				tree = tree->left_child;
			else if (tree == tree->parent->left_child && tree->parent == grandparent(tree)->right_child)
				rotate_right(tree->parent),
				tree = tree->right_child;

			insert_case5(tree);
		}


		void insert_case3(_Mytype_t* tree)
		{
			if (node_color(uncle(tree)) == Red)
				tree->parent->color = Black,
				uncle(tree)->color = Black,
				grandparent(tree)->color = Red,
				insert_case1(grandparent(tree));
			else
				insert_case4(tree);
		}




		void insert_case2(_Mytype_t* tree)
		{
			if (node_color(tree->parent) == Black)
				return;
			else
				insert_case3(tree);
		}


		void insert_case1(_Mytype_t* tree)
		{
			if (!tree->parent)
				tree->color = Black;
			else insert_case2(tree);
		}




	};


}
