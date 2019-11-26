#pragma once

#include <initializer_list>
#include <iostream>

template <typename T>
class Vector {
 public:
  Vector(size_t size);
  // Vector(std::initializer_list<T>);
  // Vector(T* begin, T* end, size_t size);
  Vector(const Vector<T>& object);
  const Vector<T>& operator=(const Vector<T>& object);
  ~Vector();

  T begin() const;
  T end() const;
  void push_back(T value);
  void push_front(T value);
  size_t insert(T value, unsigned pos);

  // T* erase(size_t pos);
  // T* erase(int* pos);
  // T* erase(int* begin, int* end);

  T* back() const;
  T* front() const;
  void resize(size_t new_size);

  void show() const;
  void clear();
  bool needs_alloc() const;
  void allocate_memory();

  size_t getsize() { return _size; }
  size_t getcapacity() { return _capacity; }
  bool empty() { return _is_empty; }

 private:
  T* _data;
  size_t _size;
  size_t _capacity;
  bool _is_empty;
};
