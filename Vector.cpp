#include "Vector.h"

template <typename T>
Vector<T>::Vector(size_t size)
    : _size(0), _capacity(size) {
  std::cout << "Size_t constructor!" << std::endl;
  _data = new T[_capacity]{};
}

template <typename T>
Vector<T>::Vector(const std::initializer_list<T>& init_list)
    : _size(init_list.size()), _capacity(_size * 2) {
  std::cout << "Init_list constructor!" << std::endl;
  get_object(init_list.begin(), init_list.end());
}

template <typename T>
Vector<T>::Vector(const T* begin, const T* const end)
    : _size(std::distance(begin, end)), _capacity(_size * 2) {
  std::cout << "Array constructor" << std::endl;
  get_object(begin, end);
}

template <typename T>
Vector<T>::Vector(const Vector<T>& object)
    : _size(object._size), _capacity(object._capacity) {
  initialise_object(object);
}

template <typename T>
const Vector<T>& Vector<T>::operator=(const Vector<T>& object) {
  if (this == &object) {
    return *this;
  };
  _size = object._size;
  _capacity = object._capacity;
  initialise_object(object);
  return *this;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
  return _data[index];
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
Vector<T>::~Vector() {
  delete[] _data;
}

template <typename T>
void Vector<T>::initialise_object(const Vector<T>& object) {
  _data = new T[object._size];
  memcpy(_data, object._data, sizeof(T) * _size);
}

template <typename T>
void Vector<T>::push_back(T value) {
  if (_data != nullptr) {
    insert(value, _size);
  } else {
    std::cout << "Error push_back {value} failed!" << std::endl;
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
  return eraser(&_data[pos], 1);
}

template <typename T>
T* Vector<T>::erase(T* pos) {
  std::cout << "Erase T* pos" << std::endl;
  return eraser(pos, 1);
}

template <typename T>
T* Vector<T>::erase(T* _begin, T* _end) {
  std::cout << "Erase T* begin, T* end" << std::endl;
  return eraser(_begin, std::distance(_begin, _end));
}

template <typename T>
T* Vector<T>::eraser(T* begin, size_t counter) {
  T* temp_begin = begin;
  while (begin < end()) {
    *begin = *(begin + counter);
    begin++;
  }
  return temp_begin;
}

template <typename T>
void Vector<T>::get_object(const T* begin, const T* const end) {
  _data = new T[_capacity];
  T* temp_begin = _data;
  while (begin != end) {
    *temp_begin++ = *begin++;
  }
}

template <typename T>
T Vector<T>::back() const {
  return _size;
}

template <typename T>
T Vector<T>::front() const {
  if (_data != nullptr) {
    return 0;
  }
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
  if (_data == nullptr) {
    std::cout << "Resize Error #0001x1 - resizing failed! " << std::endl;
    return;
  }
  if (new_size == _capacity) {
    return;
  }

  if (new_size < _size) {
    _size = new_size;
  }
  _capacity = new_size;
  allocate_memory();
}

template <typename T>
void Vector<T>::clear() {
  delete[] _data;
}

template <typename T>
bool Vector<T>::empty() const {
  return _size == 0;
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
