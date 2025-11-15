#include "Vector.h"

Vector::Vector(int n) {
	int _capicity = n;
	int _size = 0;
	int* _elements = new int[_capacity];
	int _resizeFactor = 2;
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

}