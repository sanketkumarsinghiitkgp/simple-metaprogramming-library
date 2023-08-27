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
	template <typename... Ts, typename Tail>
	struct erase<type_list<Ts..., Tail>, Tail>
	{
		using type = type_list<Ts...>;
	};
	
	// using tail instead of head since we have implemented push_back only (append is like push_back)
	// so reconstructing the type_list after erasing is easier this way.
	template <typename... Ts, typename Tail, typename T>
	struct erase<type_list<Ts..., Tail>, T>
	{
		using head_list = typename erase<type_list<Ts...>, T>::type;
		using type = typename append<head_list, Tail>::type;
	};
}
