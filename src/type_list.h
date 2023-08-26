#pragma once
#include <cstddef>
namespace sml
{
	template <typename... Ts>
	struct type_list {};

	template <typename T>
	struct length;

	template <>
	struct length<type_list<>>
	{
		static constexpr std::size_t value = 0;
	};

	template <typename T, typename... Ts>
	struct length<type_list<T,Ts...>>
	{
		static constexpr std::size_t value = 1+length<type_list<Ts...>>::value;
	};

	template <typename TypeList, typename T>
	struct append;
	
	template <typename... Ts, typename T>
	struct append<type_list<Ts...>,T>
	{
		using type = type_list<Ts...,T>;
	};
}
