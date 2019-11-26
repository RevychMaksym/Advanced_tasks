#include "Vector.h"

int main(int argc, char** argv) {
  Vector<int> obj1(5);
  std::cout << std::boolalpha << obj1.empty() << std::endl;
  std::cout << obj1.getsize() << std::endl;
  std::cout << obj1.getcapacity() << std::endl;
  std::cout << typeid(obj1).name() << std::endl;
  std::cout << obj1.getcapacity() << std::endl;
  obj1.push_back(29);
  obj1.push_back(35);
  obj1.push_back(5);
  obj1.push_back(23);
  obj1.push_back(14);
  obj1.push_back(4);
  Vector<int> obj2{obj1};
  Vector<int> obj3(5);
  obj3 = obj1;
  obj1.show();
  obj2.show();
  obj3.show();
  constexpr size_t SIZE = 5;
  int* arr = new int[SIZE]{1, 3, 5, 7, 8};
  int* begin = arr;
  int* end = arr + SIZE;
  Vector<int> arr_obj(begin, end, SIZE);
  std::cout << obj1.begin() << std::endl;
  std::cout << obj1.end() << std::endl;
  size_t a = obj1.insert(90, 3);
  std::cout << obj1.getsize() << std::endl;
  obj1.show();
  std::cout << "\n" << obj1.getsize() << std::endl;
  std::cout << "\n" << obj1.getcapacity() << std::endl;
}
