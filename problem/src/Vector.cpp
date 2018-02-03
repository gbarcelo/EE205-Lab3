#include "Vector.hpp"

#include <utility>

// Con-/De-structors:
// - Default constructor
Vector::Vector() : arr(NULL), length(0), capacity(0) { }

// - Deep Copy constructor
Vector::Vector(const Vector& other) : arr(new int(*other.arr)), length(other.length), capacity(other.capacity) { }

// - Steal Copy constructor
Vector::Vector(Vector&& other) : arr(other.arr), length(other.length), capacity(other.capacity) {
  other.arr = nullptr;
  other.length = 0;
  other.capacity = 0; // Question: Necessary?
}

// Deallocate memory
Vector::~Vector() { }

// Private Method:
void Vector::double_capacity() {
  // Double capacity of current vector
}
