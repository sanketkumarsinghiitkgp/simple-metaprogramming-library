#include <cstdint>
#include "../src/type_conditions_and_logic.h"
#include "../src/type_list.h"

using namespace sml;

void testIsSame() {
        static_assert(!is_same<float, double>::value, "float and double are the same.");
        static_assert(!is_same<long, int>::value, "int and long are the same.");
        static_assert(is_same<long long, long long int>::value, "long long and long long int aren't the same.");
        static_assert(!is_same<int32_t, float>::value, "int32_t and float are the same.");
        static_assert(!is_same<int64_t, float>::value, "int64_t and float are the same.");
        static_assert(!is_same<long long, double>::value, "long long and double are the same.");
        static_assert(!is_same<type_list<int>, type_list<double>>::value, "type_list<int> and type_list<double> are the same.");
        static_assert(is_same<type_list<type_list<int>>, type_list<type_list<int>>>::value, "is_same<type_list<type_list<int>>, type_list<type_list<int>>>::value are not same.");
        static_assert(!is_same<type_list<type_list<double>>, type_list<type_list<int>>>::value, "is_same<type_list<type_list<double>>, type_list<type_list<int>>>::value are not same.");
        int a, b; double c;
        static_assert(is_same<decltype(a), decltype(b)>::value, "decltype for int a and int b aren't the same.");
        static_assert(!is_same<decltype(a), decltype(c)>::value, "decltype for int a and double c are the same.");
}

void typeConditionsAndLogicTests() {
	testIsSame();
}
