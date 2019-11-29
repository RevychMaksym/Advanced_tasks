#include "Vector.h"

int main(int argc, char** argv) {
  Vector<int> obj1(5);
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
  obj1.resize(14);
  obj1.insert(563, 8);
  obj1.erase(1);
  obj1.print();
  int* begin = obj1.begin();
  int* end = obj1.end();
  std::cout << *(begin + 1) << std::endl;
  obj1.erase(begin + 1);
  obj1.print();
  obj1.erase(begin + 1, begin + 5);
  obj1.print();
  std::cout << *(begin + 1) << std::endl;
  obj1.push_front(531);
  std::cout << "Capacity: " << obj1.getcapacity() << std::endl;
  std::cout << "Size: " << obj1.getsize() << std::endl;

  Vector<double> obj2{2.53, 2.12, 3.35, 3.12, 6.63};
  std::cout << obj2.getsize() << std::endl;
  std::cout << obj2.getcapacity() << std::endl;
  std::cout << typeid(obj2).name() << std::endl;
  std::cout << obj2.getcapacity() << std::endl;
  obj2.push_back(29.13627);
  obj2.push_back(35.124);
  obj2.push_back(5.6463);
  obj2.push_back(23.77);
  obj2.push_back(14.1);
  obj2.push_back(4.136);
  obj2.resize(14);
  obj2.insert(563.73, 8);
  obj2.erase(1);
  double* begin_2 = obj2.begin();
  double* end_2 = obj2.end();
  obj2.push_front(531);
  obj2.print();
  std::cout << "Capacity: " << obj2.getcapacity() << std::endl;
  std::cout << "Size: " << obj2.getsize() << std::endl;

  std::string array[5]{"Hello", "!", "This", "Is", "Wonderful"};
  Vector<std::string> obj3(array, array + 5);
  std::cout << obj3.getsize() << std::endl;
  std::cout << obj3.getcapacity() << std::endl;
  std::cout << typeid(obj3).name() << std::endl;
  std::cout << obj3.getcapacity() << std::endl;
  obj3.push_back("Letters");
  obj3.push_back("Order");
  obj3.push_back("Are");
  obj3.push_back("In");
  obj3.push_back("Stomp");
  obj3.push_back("Something");
  obj3.resize(14);
  obj3.insert("Original string", 8);
  obj3.print();
  obj3.erase(1);
  obj3.erase(obj3.begin() + 2, obj3.begin() + 6);
  auto* begin_3 = obj2.begin();
  auto* end_3 = obj2.end();
  obj3.push_front("This is front");
  obj3.print();
  std::cout << "Capacity: " << obj3.getcapacity() << std::endl;
  std::cout << "Size: " << obj3.getsize() << std::endl;

  return 0;
}
