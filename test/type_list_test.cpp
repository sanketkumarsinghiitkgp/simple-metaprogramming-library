#include "../src/type_list.h"
#include "../src/type_conditions_and_logic.h"

using namespace sml;

void testEmptyTypeList() {
	static_assert(length<type_list<>>::value == 0, "testEmptyTypeList failed");
}

void testNonEmptyTypeList() {
	static_assert(length<type_list<int, double, type_list<int,double>, type_list<>>>::value == 4, "testNonEmptyTypeList failed");
}

void testAppendToTypeList() {
	using EmptyList = type_list<>;
	static_assert(length<EmptyList>::value == 0, "testAppendToTypeList failed for EmptyList");
	using SingleTypeList = append<EmptyList,int>::type;
	static_assert(length<SingleTypeList>::value == 1, "testAppendToTypeList failed for SingleTypeList");
	using ThreeLengthTypeList = append<append<SingleTypeList,type_list<int,double>>::type,int>::type;
	static_assert(length<ThreeLengthTypeList>::value == 3, "testAppendToTypeList failed for ThreeLengthTypeList");
}

void testFindInList() {
	using EmptyList = type_list<>;
	using OneLengthListContaining = type_list<int>;
	using OneLengthListNotContaining = type_list<double>;
	using FoundAtTheHead = type_list<int, double, float, char>;
	using FoundAtTheEnd = type_list<double, float, char, int>;
	using FoundInTheMiddle = type_list<double, float, int, char>;
	static_assert(find<EmptyList, int>::value == -1, "testFindInList failed for EmptyList");
	static_assert(find<OneLengthListContaining, int>::value == 0, "testFindInList failed for OneLengthListContaining");
	static_assert(find<OneLengthListNotContaining, int>::value == -1, "testFindInList failed for OneLengthListNotContaining");
	static_assert(find<FoundAtTheHead, int>::value == 0, "testFindInList failed for FoundAtTheHead");
	static_assert(find<FoundAtTheEnd, int>::value == 3, "testFindInList failed for FoundAtTheEnd");
	static_assert(find<FoundInTheMiddle, int>::value == 2, "testFindInList failed for FoundInTheMiddle");
}

void testEraseFromList() {
	using EmptyList = type_list<>;
	using OneLengthListContaining = type_list<int>;
	using OneLengthListNotContaining = type_list<double>;
	using FoundAtTheHead = type_list<int, double, float, char>;
	using FoundAtTheEnd = type_list<double, float, char, int>;
	using FoundInTheMiddle = type_list<double, float, int, char>;
	static_assert(is_same<typename erase<EmptyList, int>::type, type_list<>>::value, "testFindInList failed for EmptyList");
	static_assert(is_same<typename erase<OneLengthListContaining, int>::type, type_list<>>::value, "testFindInList failed for OneLengthListContaining");
	static_assert(is_same<typename erase<OneLengthListNotContaining, int>::type, type_list<double>>::value, "testFindInList failed for OneLengthListNotContaining");
	static_assert(is_same<typename erase<FoundAtTheHead, int>::type, type_list<double, float, char>>::value, "testFindInList failed for FoundAtTheHead");
	static_assert(is_same<typename erase<FoundAtTheEnd, int>::type, type_list<double, float, char>>::value, "testFindInList failed for FoundAtTheEnd");
	static_assert(is_same<typename erase<FoundInTheMiddle, int>::type, type_list<double, float, char>>::value, "testFindInList failed for FoundInTheMiddle");
}

void typeListTests()
{
	testNonEmptyTypeList();
	testEmptyTypeList();
	testAppendToTypeList();
	testFindInList();
	testEraseFromList();
}
