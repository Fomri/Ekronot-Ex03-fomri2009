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


