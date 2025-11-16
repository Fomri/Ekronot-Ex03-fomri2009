#include "Vector.h"

Vector::Vector(int n) {
	if (n < 2) {
		n = 2;
	}
	_capacity = n;
	_size = 0;
	_elements = new int[_capacity];
	_resizeFactor = n;
}

Vector::~Vector() {
	delete[] _elements;
}

int Vector::size() const {
	return _size;
}

int Vector::capacity() const {
	return _capacity;
}

int Vector::resizeFactor() const {
	return _resizeFactor;
}

bool Vector::empty() const {
	return _size == 0;
}

void Vector::push_back(const int& val) {
	if (_size == _capacity) {
		reserve(_capacity * _resizeFactor);
	}

	_elements[_size] = val;
	_size++;
}

int Vector::pop_back() {
	if (empty()) {
		std::cout << "error: pop from empty vector" << std::endl;
		return -9999;
	}
	_size--;
	return _elements[_size];
}

void Vector::reserve(int n) {
	if (_capacity >= n) {
		return;
	}

	int* newArray = new int[n];
	for (int i = 0; i < _size; i++) {
		newArray[i] = _elements[i];
	}

	delete[] _elements;

	_elements = newArray;
	_capacity = n;
}

void Vector::resize(int n) {
	if (n <= _capacity) {
		_size = n;
	} 
	else {
		int newCapacity = _capacity;
		while (newCapacity < n) {
			newCapacity += _resizeFactor;
		}

		reserve(newCapacity);
		_size = n;
	}
}

void Vector::assign(int val) {
	for (int i = 0; i < _size; i++) {
		_elements[i] = val;
	}
}

void Vector::resize(int n, const int& val) {
	if (n <= _capacity) {
		for (int i = _size; i < n; i++) {
			_elements[i] = val;
		}
		_size = n;
	}
	else {
		int newCapacity = _capacity;
		while (newCapacity < n) {
			newCapacity += _resizeFactor;
		}

		reserve(newCapacity);

		for (int i = _size; i < n; i++) {
			_elements[i] = val;
		}

		_size = n;
	}
}

Vector::Vector(const Vector& other) {
	_capacity = other._capacity;
	_size = other._size;
	_resizeFactor = other._resizeFactor;
	_elements = new int[_capacity];
	for (int i = 0; i < _size; i++) {
		_elements[i] = other._elements[i];
	}
}

Vector& Vector::operator=(const Vector& other) {
	if (this == &other) {
		return *this;
	}

	delete[] _elements;
	_capacity = other._capacity;
	_size = other._size;
	_resizeFactor = other._resizeFactor;

	_elements = new int[_capacity];
	for (int i = 0; i < _size; i++) {
		_elements[i] = other._elements[i];
	}
	return *this;
}

int& Vector::operator[](int n) const {
	if (n < 0 || n >= _size) {
		std::cout << "ERROR! selected index is out of bounds, returning first element" << std::endl;
		return _elements[0];
	}
	return _elements[n];
}

