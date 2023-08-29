#pragma once

namespace sml
{
	// TODO we need template type checking using concepts here
	template <typename T, T A, T B>
	struct add
	{
		static constexpr T value = A + B;
	};

	template <typename T, T A, T B>
	struct multiply
	{
		static constexpr T value = A * B;
	};
	template <typename T, T A, T B>
	struct subtract
	{
		static constexpr T value = A - B;
	};

	template <typename T, T A, T B>
	struct divide
	{
		static constexpr T value = A / B;
	};

	template <typename T, T A, T B>
	struct mod
	{
		static constexpr T value = A % B;
	};

	template <typename T, T A>
	struct square
	{
		static constexpr T value = multiply<T, A, A>::value;
	};

	//TODO handle all integers separately and all floating points separately, non-numeric should be treated like non-negative integers.
	// this implementation is only for positive integral types.
	template <typename T, T A, int B>
	struct pow;

	//B>0
	template <typename T, int B>
	struct pow<T, 0, B>
	{
		static constexpr T value = 0;
	};

	template <typename T, T A>
	struct pow<T, A, 0>
	{
		static constexpr T value = 1;
	};

	template <typename T, T A, int B>
	requires (B %2 == 1)
	struct pow<T, A, B>
	{
		//TODO maybe indent such long nested template expressions.
		static constexpr T value= multiply<T, square<T, pow<T, A, divide<int, B, 2>::value>::value>::value, A>::value;
	};

	template <typename T, T A, int B>
	struct pow<T, A, B>
	{
		static constexpr T value= square<T, pow<T, A, divide<int, B, 2>::value>::value>::value;
	};
}
