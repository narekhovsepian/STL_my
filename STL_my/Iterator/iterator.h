#pragma once
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include<cstddef>

namespace std_my {



	struct input_iterator_tag {};

	struct output_iterator_tag {};

	struct forward_iterator_tag : public input_iterator_tag {};

	struct bidirectional_iterator_tag : public forward_iterator_tag {};

	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	struct contiguous_iterator_tag : public random_access_iterator_tag {};

	template<typename _Category, typename _Tp,
		typename _Distance = ptrdiff_t,
		typename _Pointer = _Tp*,
		typename _Reference = _Tp&>

	struct iterator {
		typedef _Category iterator_category;

		typedef _Tp value_type;

		typedef _Distance difference_type;

		typedef _Pointer pointer;

		typedef _Reference reference;
	};

	template<typename Iter>
	struct iterator_traits {

		using value_type = typename Iter::value_type;

		using defference_type = typename Iter::difference_type;

		using pointer = typename Iter::pointer;

		using reference = typename Iter::reference;

		using iterator_category = typename Iter::iterator_category;
	};

	template<typename T>
	struct iterator_traits<T*> {
		using difference_type = ptrdiff_t;

		using value_type = T;

		using pointer = T*;

		using reference = T&;

		using iterator_category = random_access_iterator_tag;

		using iterator_concept = contiguous_iterator_tag;
	};

}


#endif
