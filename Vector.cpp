#include "Vector.h"

template <typename T>
Vector<T>::Vector(size_t size)
    : _capacity(size) {
  std::cout << "Size_t constructor!" << std::endl;
  _data = new T[_capacity]{};
  _size = 0;
}

template <typename T>
Vector<T>::Vector(const std::initializer_list<T>& init_list) {
  std::cout << "Init_list constructor!" << std::endl;
  _size = init_list.size();
  _capacity = _size * 2;
  _data = new T[_capacity];
  T* begin = _data;
  for (auto& value : init_list) {
    *begin++ = value;
  }
}

template <typename T>
Vector<T>::Vector(const T* begin, const T* const end) {
  std::cout << "Array constructor" << std::endl;
  _size = end - begin;
  std::cout << "Size_ = " << _size << std::endl;
  _capacity = _size * 2;
  _data = new T[_capacity];
  T* temp_begin = _data;
  while (begin != end) {
    *temp_begin++ = *begin++;
  }
}

template <typename T>
Vector<T>::Vector(const Vector<T>& object) {
  _data = new T[object._size];
  _size = object._size;
  _capacity = object._capacity;
  memcpy(_data, object._data, sizeof(T) * _size);
}

template <typename T>
const Vector<T>& Vector<T>::operator=(const Vector<T>& object) {
  if (this == &object) {
    return *this;
  };
  delete[] _data;
  _data = new T[object._size];
  _size = object._size;
  memcpy(_data, object._data, sizeof(T) * _size);
  return *this;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
  return _data[index];
}

template <typename T>
Vector<T>::~Vector() {
  delete[] _data;
}

template <typename T>
void Vector<T>::push_back(T value) {
  if (_data != nullptr) {
    insert(value, _size);
  } else {
    std::cout << "Error push_back {value} failed!" << std::endl;
    return;
  }
}

template <typename T>
void Vector<T>::push_front(T value) {
  if (_data != nullptr) {
    insert(value, 0);
  } else {
    std::cout << "Error push_front {value} failed!" << std::endl;
  }
}

template <typename T>
size_t Vector<T>::insert(T value, size_t pos) {
  if (_data != nullptr) {
    if (needs_alloc() || pos > _capacity) {
      allocate_memory();
    }
    size_t pos_counter = pos;
    for (size_t counter = _size; counter > pos_counter; --counter) {
      _data[counter] = _data[counter - 1];
    }
    _data[pos_counter] = value;
    _size++;
  }
  return pos;
}

template <typename T>
T* Vector<T>::erase(size_t pos) {
  for (size_t counter = pos; counter <= _size; ++counter) {
    _data[counter] = _data[counter + 1];
  }
  _data[_size] = {};
  --_size;
  return &(_data[pos]);
}

template <typename T>
T* Vector<T>::erase(T* pos) {
  std::cout << "Erase T* pos" << std::endl;
  T* temp_begin = pos;
  std::cout << typeid(temp_begin).name() << std::endl;
  while (pos < end()) {
    *pos = *(pos + 1);
    pos++;
  }
  return temp_begin;
}

template <typename T>
T* Vector<T>::erase(T* _begin, T* _end) {
  std::cout << "Erase T* begin, T* end" << std::endl;
  T* temp_begin = _begin;
  size_t counter = _end - _begin;
  std::cout << typeid(temp_begin).name() << std::endl;
  while (_begin < end()) {
    *_begin = *(_begin + counter);
    _begin++;
  }
  return temp_begin;
}

template <typename T>
T Vector<T>::back() const {
  return _data[_size];
}

template <typename T>
T Vector<T>::front() const {
  return _data[0];
}

template <typename T>
T* Vector<T>::begin() {
  return _data;
}

template <typename T>
T* Vector<T>::end() {
  return (_data + _size);
}

template <typename T>
void Vector<T>::resize(size_t new_size) {
  if (_data != nullptr) {
    if (new_size < _size) {
      _capacity = new_size;
      _size = new_size;
      allocate_memory();
    } else if (new_size > _capacity) {
      _capacity = new_size;
      allocate_memory();
    }
  } else {
    std::cout << "Resize Error #0001x1 - resizing failed! " << std::endl;
  }
}

template <typename T>
void Vector<T>::print() const {
  if (_data != nullptr) {
    for (size_t i = 0; i < _capacity; ++i) {
      std::cout << _data[i] << " ";
    }
    std::cout << "\n";
  } else {
    std::cout << "Nullptr exception!" << std::endl;
  }
}

template <typename T>
void Vector<T>::clear() {
  ~Vector();
}

template <typename T>
bool Vector<T>::empty() const {
  if (_size == 0) {
    return true;
  }
  return false;
}

template <typename T>
bool Vector<T>::needs_alloc() const {
  return _size >= _capacity;
}

template <typename T>
void Vector<T>::allocate_memory() {
  _capacity *= 2;
  T* temp = new T[_capacity]{};

  for (unsigned i = 0; i < _size; ++i) {
    temp[i] = std::move(_data[i]);
  }
  delete[] _data;
  _data = temp;
}
