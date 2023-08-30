#include "../src/math.h"
using namespace sml;

void testAdd() {
	static_assert(add<int,5,6>::value == 11, "5+6!=11");
	static_assert(add<double, 5.0, 6.0>::value == 11.0, "5.0 + 6.0 != 11.0");
	static_assert(add<double, 5, 6>::value == 11.0, "5 + 6 != 11.0");
	static_assert(add<float, 5.0, 6.0>::value == 11.0, "5.0f + 6.0f != 11.0");
	static_assert(add<double, 5.0f, 6.0f>::value == 11.0, "5.0f + 6.0f != 11.0");
}

void testMultiply() {
	static_assert(multiply<int,5,6>::value == 30, "5+6!=30");
	static_assert(multiply<double, 5.0, 6.0>::value == 30.0, "5.0 + 6.0 != 30.0");
	static_assert(multiply<double, 5, 6>::value == 30.0, "5 + 6 != 30.0");
	static_assert(multiply<double, 5, 6>::value == 30.0, "5 + 6 != 30.0");
	static_assert(multiply<float, 5.0, 6.0>::value == 30.0, "5.0f + 6.0f != 30.0");
	static_assert(multiply<double, 5.0f, 6.0f>::value == 30.0, "5.0f + 6.0f != 30.0");
}

void testSubtract() {
	static_assert(subtract<int,5,6>::value == -1, "5+6!=11");
	static_assert(subtract<double, 5.0, 6.0>::value == -1.0, "5.0 + 6.0 != 11.0");
	static_assert(subtract<double, 5, 6>::value == -1.0, "5 + 6 != 11.0");
	static_assert(subtract<float, 5.0, 6.0>::value == -1.0, "5.0f + 6.0f != 11.0");
	static_assert(subtract<double, 5.0f, 6.0f>::value == -1.0, "5.0f + 6.0f != 11.0");
}

void testDivide() {
	static_assert(divide<int, 11, 2>::value == 5, "11/2 != 5");
	static_assert(divide<double, 11.0, 2.0>::value == 5.5, "11.0/2.0 != 5.5");
	static_assert(divide<double, 11, 2>::value == 5.5, "11/2 != 5.5");
	static_assert(divide<float, 11.0, 2.0>::value == 5.5f, "11.0/2.0 != 5.5");
}

void testMod() {
	static_assert(divide<int, 11, 2>::value == 1, "11%2 != 1");
	static_assert(divide<int, 10, 2>::value == 0, "10%2 != 0");
}

void testSquare() {
	static_assert(square<int, 5>::value == 25, "5 square != 25");
	static_assert(square<int, 0>::value == 0, "0 square != 0");
	static_assert(square<int, -1>::value == 1, "-1 square != 1");
}

void testPow() {
	static_assert(pow<double, 5.0, 2>::value == 25.0, "5.0^2 == 25.0");
	static_assert(pow<int, 5, 3>::value == 125, "5^3 == 125");
	static_assert(pow<int, -5,2>::value == 25, "(-5)^2 == 25");
	static_assert(pow<int, -5,3>::value == -125, "(-5)^3 == 125");
	static_assert(pow<int, 5, 0>::value == 1, "5^0 == 1");
	static_assert(pow<int, 5, 1>::value == 5, "5^1 == 5");
}
void mathTests() {
	testAdd();
	testMultiply();
	tstSubtract();
	testDivide();
	testMod();
	testSquare();
	testPow();
}
