#include "typename.h"
#include <iostream>
#include <string>

namespace test {
	struct Abc {
		struct Bcd {

		};
	};
}

constexpr bool t = GetTypeName<test::Abc>() == "Abc";
static_assert(t, "wrong");

int main() {
	std::cout << GetTypeName<test::Abc>() << std::endl;
	return 0;
}