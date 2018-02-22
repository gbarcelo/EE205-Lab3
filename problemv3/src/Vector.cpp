#include "Vector.hpp"
#include <utility>

Vector::Vector(){
	length=0;
	capacity=1;
	arr= new int[1];

}
//Double capacity by creating a new vector with double the capacity
//Then copying the contents of the older vector to the new.
//Then deletes the old vector.
void Vector::double_capacity(){
	int* temp = new int[capacity*2];
	for(int i=0;i<length;i++){
		temp[i] = arr[i];
	}
	delete arr;
	arr = temp;
	capacity = capacity*2;
}
//Copys the vector into a new one.
Vector::Vector(const Vector& other){
	length = other.length;
	capacity = other.capacity;
	arr = new int[capacity];
	for(int i=0; i<length; i++){
		arr[i] = other.arr[i];
	}
}
//Moves vector
Vector::Vector(Vector&& other) {
	length = other.length;
	capacity = other.capacity;
	arr = other.arr;
	other.length = 0;
	other.capacity = 0;
	other.arr = nullptr;
}
//Destroys vector by setting each value to 0 then deleting the vector
Vector::~Vector(){
	length = 0;
	capacity = 0;
	for(int i=0;i<length;i++){
		arr[i] = 0;
	}
	delete arr;
}
//Inserts a number at the end of the array, and doubles the size if the 
//Capcacity limit is reached
void Vector::append(int num){
	if(length>=capacity){
		double_capacity();
	}
	arr[length] = num;
	length = length + 1;	
}

//Inserts the vector at an index by moving the elements to the right of the
//index (one greater) one more to the right then inserting the element
//at the given index, doubles size if capacity it reached.
void Vector::insert(int index, int num){
	if(length >= capacity){
		double_capacity();
	}
	if(index>length ||index<0){
		throw "Out of bounds";} else{
			for(int i=length-1; i>index-1;i--){
				arr[i+1] = arr[i];
			}	
			arr[index] = num;
			length++;
		}
}

//Removes index by moving the elements one right of the index one left, 
//removing the element at the given index
void Vector::remove(int index){
	if(index>=length || index<0 || length==0){
		throw "Out of bounds";
	} else{
		for(int i=index; i<length-1; i++){
			arr[i] = arr[i+1];	
		}
		arr[length-1]=0;
		length = length-1;
	}
}

//Gets the given index
int Vector::get(int index) const{
	if(index>length || index<0){
		throw "Out of bounds";
	}
	return arr[index];

}

//Returns length
std::size_t Vector::size() const{
	return length;
}

//Gets the address of from the given index.
int& Vector::operator[](int index){
	if(index<0 || length<=0 || index>=length){
		throw "Out of bounds";
	} else{
		int& a = arr[index];
		return a;
	}

}

