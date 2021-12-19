#pragma once

namespace rbBstA
{

	enum rbcolor { Red = true; Black = false; }


	template<typename T>
	class rbBstA
	{
		template<typename T>
		struct node
		{
			T _info{ };
			node<T>* parent;
			node<T>* left_child;
			node<T>* right_child;
			node(const T& info = T()) : _info{ info },

		};
	};
}
