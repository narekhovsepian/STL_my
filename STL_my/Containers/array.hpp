#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>
#include <compare>
#include <type_traits>
#include "../iterator/iterator.hpp"

namespace std_my {


template<class _Ty, size_t _Size>
	class _const_iterator {
			
		public:
		using iterator_concept = std_my::contiguous_iterator_tag;

		using iterator_category = std_my::random_access_iterator_tag;
		using value_type = _Ty;
		using difference_type = ptrdiff_t;
		using pointer = const _Ty*;
		using reference = const _Ty&;
		
		constexpr _const_iterator() noexcept  : _Ptr()  {}
		
		constexpr explicit _const_iterator(pointer _Parg, size_t _Off = 0) noexcept : _Ptr(_Parg + _Off) { }
			
		[[nodiscard]]
			constexpr reference operator*() const noexcept {
				return *_Ptr;
			}

		[[nodiscard]]
			constexpr pointer operator->() const noexcept {
				return _Ptr;
			}

	
			constexpr _const_iterator&  operator++() noexcept {
				++_Ptr;
				return *this;
			}

			constexpr _const_iterator operator++(int) noexcept {
			 	_const_iterator tmp = *this;
				++_Ptr;
				return tmp;
			}

	
			constexpr _const_iterator& operator--() const noexcept {
				--_Ptr;
				return *this;
			}
		  	constexpr _const_iterator operator--(int) const noexcept {
				_const_iterator tmp = *this;
				--_Ptr;
				return tmp;
			}


			constexpr _const_iterator& operator+=(const ptrdiff_t _Off) noexcept {
				_Ptr += _Off;
				return *this;
			}

			
			constexpr _const_iterator& operator-=(const ptrdiff_t _Off) noexcept {
				_Ptr -= _Off;
				return *this;
			}

		[[nodiscard]]
			constexpr ptrdiff_t operator-(const _const_iterator& _Right)
				const noexcept {
					return _Ptr - _Right._Ptr;
				}

		[[nodiscard]]
			constexpr ptrdiff_t operator+(const _const_iterator& _Right)
				const noexcept {
					return _Ptr - _Right._Ptr;
				}
	
	/*	[[nodiscard]]
			constexpr std::strong_ordering operator <=>(const _const_iterator & _Right) const noexcept {
				return _Ptr <=> _Right._Ptr;
			}*/

		[[nodiscard]]
			constexpr bool operator==(const _const_iterator& _Right) const noexcept {
				return _Ptr== _Right._Ptr;
			}


		[[nodiscard]]
			constexpr bool operator!=(const _const_iterator& _Right) const noexcept {
				return !(*this == _Right);
			}
	
		[[nodiscard]]
			constexpr reference operator[](const ptrdiff_t _Off) const noexcept {
				return _Ptr[_Off];
			}


		[[nodiscard]]
			constexpr _const_iterator operator+(const ptrdiff_t _Off) const noexcept {
				_const_iterator tmp = *this;
				tmp += _Off;
				return tmp;
			}

		[[nodiscard]]
			constexpr _const_iterator operator-(const ptrdiff_t _Off) const noexcept {
				_const_iterator tmp = *this;
				tmp -= _Off;
				return tmp;
			}

		size_t _Idx;
		pointer _Ptr;
	};


template<class _Ty, std::size_t _Size>
	class _iterator : public _const_iterator<_Ty, _Size> {
		public:
		using iterator_category = std_my::random_access_iterator_tag;

		using iterator_concept = std_my::contiguous_iterator_tag;
		
		using value_type = _Ty;
		using difference_type = ptrdiff_t;
		using pointer = _Ty*;
		using reference = _Ty&;

		using _Mybase = _const_iterator<_Ty,_Size>;

		constexpr _iterator() noexcept {}

		constexpr explicit _iterator(pointer _Parg, size_t _Off = 0)
			noexcept : _Mybase{_Parg,_Off} {}

		

		[[nodiscard]]
			constexpr reference operator*() const noexcept {
				return const_cast<reference>(_Mybase::operator*());
			}

		[[nodiscard]]
			constexpr pointer operator->() const noexcept {
				return const_cast<pointer>(_Mybase::operator->());
			}

	
			constexpr _iterator& operator++() noexcept {
				_Mybase::operator++();
				return *this;
			}

			constexpr _iterator operator++(int) noexcept {
				_iterator tmp = *this;
				_Mybase::operator++();
				return tmp;
			}

	
			constexpr _iterator& operator--() noexcept {
				_Mybase::operator--();
				return *this;
			}

	
			constexpr _iterator operator--(int) noexcept {
				_iterator tmp = *this;
				_Mybase::operator--();
				return tmp;
			}
		
	
			constexpr _iterator& operator+=(const ptrdiff_t _Off) noexcept {
					_Mybase::operator+=(_Off);
					return *this;
			}


			constexpr _iterator& operator-=(const ptrdiff_t _Off) noexcept {
				_Mybase::operator-=(_Off);
				return *this;
			}

		
		using _Mybase::operator-;

		
		[[nodiscard]]
			constexpr _iterator operator-(const ptrdiff_t _Off) const noexcept {
				_iterator _tmp = *this;
				_tmp -= _Off;
				return _tmp;
			}

		[[nodiscard]]
			constexpr _iterator operator+(const ptrdiff_t _Off) const noexcept {
				_iterator _tmp = *this;
				_tmp += _Off;
				return _tmp;
			}

		[[nodiscard]]
			constexpr reference operator[](const ptrdiff_t _Off) noexcept {
				return const_cast<reference>(_Mybase::operator[](_Off));
			}
	};



template<typename _Ty, size_t _Size>
	class array {
		public:
		using value_type = _Ty;
		using size_type = size_t;
		using difference_type = ptrdiff_t;
		using reference = _Ty&;
		using const_reference =  const _Ty&;
		using pointer = _Ty*;
		using const_pointer = const _Ty*;

		using __iterator = _iterator<_Ty,_Size>;
		using __const_iterator = _const_iterator<_Ty,_Size>;

		[[nodiscard]]
		constexpr __iterator begin() noexcept  {
				return __iterator(_Elems,0);
			}
		
		[[nodiscard]]
			constexpr __const_iterator begin() const noexcept {
				return _const_iterator(_Elems,0);
			}

		[[nodiscard]]
			constexpr __iterator end() noexcept {
				return __iterator(_Elems,_Size);
			}

		[[nodiscard]]
			constexpr __const_iterator end() const noexcept {
				return _const_iterator(_Elems,_Size);
			}
		
		[[nodiscard]]
			 constexpr reference at(size_type _Pos) {
				 if(_Pos > _Size)
					 _Xran();

				 return _Elems[_Pos];
			 }

		 [[nodiscard]]
			 constexpr const_reference at(size_type _Pos) const {
				 if(_Pos > _Size)
					 _Xran();

				 return _Elems[_Pos];
			 }


		 [[nodiscard]]
			 constexpr reference operator[](size_type _Pos) noexcept {
				 return _Elems[_Pos];
			 }


		 [[nodiscard]]
			 constexpr const_reference operator[](size_type _Pos) const noexcept {
				 return _Elems[_Pos];
			 }

		 [[nodiscard]]
			 constexpr reference front() noexcept {
				 return _Elems[0];
			 }

		 [[nodiscard]]
			 constexpr const_reference front() const noexcept {
				 return _Elems[0];
			 }

		 [[nodiscard]]
			constexpr reference back() noexcept {
				return _Elems[_Size - 1];
			}

		 [[nodiscard]]
			constexpr const_reference back() const noexcept {
				return _Elems[_Size -1];
			}


		 [[nodiscard]]
			 constexpr pointer data() noexcept {
				return _Elems;
			 }

		 [[nodiscard]]
			constexpr const_pointer data() const noexcept {
				return _Elems;
			}
			
		[[noreturn]]
			void _Xran() const {
				std::out_of_range("invalid array<T,N> subscript");			
			}


		[[nodiscard]]
			constexpr bool empty() const noexcept {
				return false;
			}

		[[nodiscard]]
			constexpr size_type size() const noexcept {
				return _Size;
			}

		[[nodiscard]]
			constexpr size_type max_size() const noexcept {
				return _Size;
			}



		_Ty _Elems[_Size];
	};	



	template<class _Ty>
		class array<_Ty,0> {
			public:
			using value_type = _Ty;
			using size_type = size_t;
			using difference_type = ptrdiff_t;
			using pointer = _Ty*;
			using const_pointer = const _Ty*;
			using reference = _Ty&;
			using const_reference = const _Ty&;
			
			using __iterator = _iterator<_Ty,0>;
			using __const_iterator = _const_iterator<_Ty,0>;

			[[nodiscard]]	
				constexpr __iterator begin() noexcept {
					return __iterator{};
				}

			[[nodiscard]]
				constexpr __const_iterator begin() const noexcept {
					return __const_iterator{};
				}


			[[nodiscard]]
				constexpr __iterator end() noexcept {
					return __iterator{}; 
				}

			[[nodiscard]]
				constexpr __const_iterator end() const noexcept {
					return __const_iterator{};
				}

			[[nodiscard]]
				constexpr size_type size() const noexcept {
					return 0;
				}

			[[nodiscard]]
				constexpr size_type max_size() const noexcept {
					return 0;
				}

			[[nodiscard]]
				constexpr bool empty() const noexcept {
					return true;
				}

			[[noreturn]]
				reference at(size_type) {
					_Xran();
				}

			[[noreturn]]
				const_reference at(size_type) const {
					_Xran();
				}

			[[nodiscard]]
				reference operator[](size_type) noexcept {
					return *data();
				}

			[[nodiscard]]
				const_reference operator[](size_type) const noexcept {
					return *data();
				}

			[[nodiscard]]
				reference front() noexcept {
					return *data();
				}

			[[nodiscard]]
				const_reference front() const noexcept {
					return *data();
				}

			[[nodiscard]]
				reference back() noexcept {
					return *data();
				}

			[[nodiscard]]
				const_reference back() const noexcept {
					return *data();
				}

			[[nodiscard]]
				constexpr pointer data() noexcept {
					return nullptr;
				}

			[[nodiscard]]
				constexpr const_pointer data() const noexcept {
					return nullptr;
				}

			[[noreturn]]
				void _Xran() const {
					std::out_of_range("invalid array<T,0> subscript");
				}

		};


}

#endif
