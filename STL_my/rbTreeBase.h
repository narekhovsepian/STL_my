#pragma once


namespace rbTreeBase
{
	template<typename T>
	class rbTreeBase
	{
		enum color { Red = true, Black = false };
		template<typename T>
		struct rbNode
		{
			rbNode<T> *parent;
			rbNode<T> *left_child;
			rbNode<T> *right_child;
			color     rbcolor;
			rbNode() : parent(nullptr), left_child(nullptr), right_child(nullptr), rbcolor(Black) { }

		};
		rbNode<T> *_root = nullptr;


	protected:
		inline  rbNode<T> *get_root() const { return _root; }
		rbNode<T> *grandparent(rbNode<T> *);
		rbNode<T> *sinling(rbNode<T>*);
		rbNode<T> *uncle(rbNode<T>*);






	};
















}
