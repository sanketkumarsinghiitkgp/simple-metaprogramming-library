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
		static constexpr int value = 0;
	};

	template <typename T, typename... Ts>
	struct length<type_list<T,Ts...>>
	{
		static constexpr int value = 1+length<type_list<Ts...>>::value;
	};

	template <typename TypeList, typename T>
	struct append;
	
	template <typename... Ts, typename T>
	struct append<type_list<Ts...>,T>
	{
		using type = type_list<Ts...,T>;
	};

	template <typename TypeList, typename T>
	struct append_front;

	template <typename... Ts, typename T>
	struct append_front<type_list<Ts...>,T>
	{
		using type = type_list<T,Ts...>;
	};

	template <typename TypeList, typename T>
	struct find
	{
		static constexpr int value = -1;
	};

	template <typename... Ts, typename Head>
	struct find<type_list<Head, Ts...>, Head>
	{
		static constexpr int value = 0;
	};

	template <typename... Ts, typename Head, typename T>
	struct find<type_list<Head, Ts...>, T>
	{
		static constexpr int tailValue = find<type_list<Ts...>, T>::value;
		static constexpr int value = tailValue != -1 ? 1 + tailValue : -1;
	};


	template <typename TypeList, typename T>
	struct erase;
	
	template <typename T>
	struct erase<type_list<>, T>
	{
		using type = type_list<>;
	};

	template <typename... Ts, typename Head>
	struct erase<type_list<Head, Ts...>, Head>
	{
		using type = type_list<Ts...>;
	};

	template <typename... Ts, typename Head, typename T>
	struct erase<type_list<Head, Ts...>, T>
	{
		using tail_list = typename erase<type_list<Ts...>,T>::type;
		using type = typename append_front<tail_list,Head>::type;
	};

	template <typename First, typename Second>
	struct is_same
	{
		static constexpr bool value = false;
	};

	template <typename T>
	struct is_same<T, T>
	{
		static constexpr bool value = true;
	};
}
