#include <initializer_list>
#include <iostream>

class MyInt {
 public:
  MyInt() {
    std::cout << "default" << std::endl;
    _value = 0;
  };
  MyInt(const MyInt& rhs) {
    std::cout << "copy" << std::endl;
    _value = rhs._value;
  }
  MyInt(const int& value) {
    std::cout << "from int" << std::endl;
    _value = value;
  };

  MyInt& operator+=(const MyInt& rhs) {
    _value += rhs._value;
    return *this;
  }

  MyInt& operator++() {
    _value++;
    return *this;
  }

  MyInt operator++(int) {
    auto tmp = *this;
    ++*this;
    return tmp;
  }

private:
  int _value;
};

MyInt operator+(MyInt lhs, const MyInt& rhs) {
  return lhs += rhs;
};


int main() {
  MyInt a;
  MyInt b{};
  // MyInt c(a);
  // MyInt d = b;
  // MyInt e(7);
  // int x = 8;
  // MyInt f(x);
  MyInt g = a + b;
  MyInt h = a + 1;
  MyInt i = 2 + b;
  // d += a;
  g += 3;
  ++h;
  h++;
  i = ++h;
  i = h++ + a;

  return 0;
}
