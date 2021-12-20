#include <iostream>
#include <string>

#include "typename.h"

namespace test {
struct Abc {
  struct Bcd {};
};
}  // namespace test

constexpr bool t = GetTypeName<test::Abc>() == "Abc";
static_assert(t, "wrong");

int main() {
  std::cout << GetTypeName<test::Abc>() << std::endl;
  return 0;
}