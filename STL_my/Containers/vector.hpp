#ifndef VECTOR_HPP
#define VECTOR_HPP

#include<memory>



template<class _Ty, typename _Alloc = std::allocator<_Ty>> 
class vector {

	using _Alty_traits = std::allocator_traits<_Ty>;
	constexpr vector() noexcept = default;
};





#endif // VECTOR_HPP
