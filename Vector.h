#pragma once

#include <initializer_list>
#include <iostream>
#include <string>

template <typename T>
class Vector {
public:
	Vector(size_t size);
	Vector(const std::initializer_list<T>& init_list);
	Vector(const T* begin, const T* const end);
	Vector(const Vector<T>& object);
	const Vector<T>& operator=(const Vector<T>& object);
	T& operator[](size_t index);
	~Vector();

	T* begin();
	T* end();
	void push_back(T value);
	void push_front(T value);
	size_t insert(T value, size_t pos);
	
	T* erase(size_t pos);
	T* erase(T* pos);
	T* erase(T* begin, T* end);

	T back() const;
	T front() const;
	void resize(size_t new_size);
	
	void print() const;
	void clear();

	size_t getsize() const { return _size; }
	size_t getcapacity() const { return _capacity; }
	bool empty() const;
private:
	bool needs_alloc() const;
	void allocate_memory();
	void initialise_object(const Vector<T>& object);

	T* eraser(T* begin, size_t counter);
	void get_object(const T* begin, const T* const end);

	T* _data;
	size_t _size;
	size_t _capacity;
};
