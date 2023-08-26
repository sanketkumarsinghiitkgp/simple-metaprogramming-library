#include "../src/type_list.h"
#include <iostream>
using namespace sml;

void testEmptyTypeList() {
	static_assert(length<type_list<>>::value == 0, "testEmptyTypeList failed");
	std::cout<<"typeof(type_list<>)"<<typeid(length<type_list<>>).name()<<std::endl;
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

int main()
{
	testNonEmptyTypeList();
	testEmptyTypeList();
	testAppendToTypeList();
}
