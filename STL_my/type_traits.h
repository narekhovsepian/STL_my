#pragma once
#include<iostream>


namespace std_my
{
	template<class _Ty>
	struct remove_reference
	{
		using type = _Ty;
	};

	template<class _Ty>
	struct remove_reference<_Ty&>
	{
		using type = _Ty;
	};

	template<class _Ty>
	struct remove_reference<_Ty&&>
	{
		using type = _Ty;
	};

	template<class _Ty>
	using remove_reference_t = typename remove_reference<_Ty>::type;

	template<class _Ty>
	constexpr remove_reference_t<_Ty>&& move(_Ty&& _Arg) noexcept
	{
		return static_cast<remove_reference_t<_Ty>&&>(_Arg);
	}

	template<class _Ty>
	constexpr _Ty&& forward(remove_reference_t<_Ty>& Arg) noexcept
	{
		return static_cast<_Ty&&>(Arg);
	}

	template<class _Ty>
	constexpr _Ty&& forward(remove_reference_t<_Ty>&& Arg) noexcept
	{
		static_assert(!std::is_lvalue_reference_v<_Ty>, "bad forward call");
		return static_cast<_Ty&&>(Arg);
	}

}

