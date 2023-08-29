#pragma once
namespace sml
{
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
