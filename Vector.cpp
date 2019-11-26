#include "Vector.h"

template <typename T>
Vector<T>::Vector(size_t size)
    : _capacity(size) {
  _data = new T[_capacity]{};
  _size = 0;
  _is_empty = true;
}

// template<typename T>
// Vector<T>::Vector(std::initializer_list<T>)
//{
//
//}
//

// template<typename T>
// Vector<T>::Vector(T* begin, T* end, size_t size)
//{
//	_size = size;
//	_data = begin;
//	_data_end = _data + _size;
//
//	_capacity = (end - begin) / sizeof(T);
//}

template <typename T>
Vector<T>::Vector(const Vector<T>& object) {
  _data = new T[object._size];
  _size = object._size;
  _capacity = object._capacity;
  _is_empty = object._is_empty;
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
Vector<T>::~Vector() {
  delete[] _data;
}

template <typename T>
void Vector<T>::push_back(T value) {
  if (_data != nullptr) {
    if (!_is_empty) {
      if (needs_alloc()) {
        allocate_memory();
      }
    }
    _data[_size] = value;
    _is_empty = false;
    _size++;
  } else {
    std::cout << "Error push_back {value} failed!" << std::endl;
    return;
  }
}

template <typename T>
void Vector<T>::push_front(T value) {
  if (_data != nullptr) {
    if (!_is_empty) {
      if (needs_alloc()) {
        allocate_memory();
      }
    }
    T* backup = new T[_capacity];
    size_t counter = 0;
    for (unsigned i = 0; i < _size; ++i) {
      backup[++counter] = std::move(_data[i]);
    }
    _data = backup;
    _data[0] = value;
    _is_empty = false;
    _size++;
  } else {
    std::cout << "Error push_front {value} failed!" << std::endl;
    return;
  }
}

template <typename T>
size_t Vector<T>::insert(T value, unsigned pos) {
  if (_data != nullptr) {
    if (needs_alloc()) {
      allocate_memory();
    }
    size_t pos_counter = pos;
    for (size_t counter = _size; counter >= pos_counter; --counter) {
      _data[counter + 1] = _data[counter];
    }
    _data[pos_counter] = value;
    _size++;
    if (needs_alloc()) {
      allocate_memory();
    }
    _is_empty = false;
  }

  return pos;
}

template <typename T>
T* Vector<T>::back() const {
  return _data + _size;
}

template <typename T>
T* Vector<T>::front() const {
  return _data;
}

template <typename T>
T Vector<T>::begin() const {
  return _data[0];
}

template <typename T>
T Vector<T>::end() const {
  return _data[0 + _size];
}

template <typename T>
void Vector<T>::resize(size_t new_size) {
  if (_data != nullptr) {
    if (new_size < _size) {
      _size = new_size;
      T* temp = new T[new_size];

      for (unsigned i = 0; i < new_size; ++i) {
        temp[i] = std::move(_data[i]);
      }
      delete[] _data;
      _data = temp;
    } else if (new_size > _capacity) {
      while (new_size > _capacity) {
        allocate_memory();
      }
    }

    T* temp = new T[new_size];

    for (unsigned i = 0; i < _size; ++i) {
      temp[i] = std::move(_data[i]);
    }
    _data = temp;
  } else {
    std::cout << "Resize Error #0001x1 - resizing failed! " << std::endl;
    return;
  }
}

template <typename T>
void Vector<T>::show() const {
  if (_data != nullptr) {
    for (unsigned i = 0; i < _size; ++i) {
      std::cout << _data[i] << " ";
    }
    std::cout << "\n";
  } else {
    std::cout << "Error!" << std::endl;
    return;
  }
}

template <typename T>
void Vector<T>::clear() {
  for (unsigned i = 0; i < _size; ++i) {
    _data[i] = 0;
  }
  _is_empty = true;
}

template <typename T>
bool Vector<T>::needs_alloc() const {
  return _size >= _capacity;
}

template <typename T>
void Vector<T>::allocate_memory() {
  T* temp = new T[2 * _capacity]{};

  for (unsigned i = 0; i < _size; ++i) {
    temp[i] = std::move(_data[i]);
  }
  _capacity *= 2;
  _data = temp;
}
