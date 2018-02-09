#include "Vector.hpp"
#include <utility>

Vector::Vector(){
	length=0;
	capacity=1;
	arr= new int[1];

}

void Vector::double_capacity(){
	int* temp = new int[capacity*2];
	for(int i=0;i<length;i++){
		temp[i] = arr[i];
	}
	delete arr;
	arr = temp;
	capacity = capacity*2;
}

Vector::Vector(const Vector& other){
	length = other.length;
	capacity = other.capacity;
	arr = new int[capacity];
	for(int i=0; i<length; i++){
		arr[i] = other.arr[i];
	}
}

Vector::Vector(Vector&& other) {
	length = other.length;
	capacity = other.capacity;
	arr = other.arr;
	other.length = 0;
	other.capacity = 0;
	other.arr = nullptr;
}

Vector::~Vector(){
	length = 0;
	capacity = 0;
	for(int i=0;i<length;i++){
		arr[i] = 0;
	}
	delete arr;
}

void Vector::append(int num){
	if(length==capacity){
		double_capacity();
	}
	arr[length] = num;
	length = length + 1;	
}


void Vector::insert(int index, int num){
	if(length == capacity){
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

int Vector::get(int index) const{
	if(index>length || index<0){
		throw "Out of bounds";
	}
	return arr[index];

}

std::size_t Vector::size() const{
	return length;
}

int& Vector::operator[](int index){
	if(index<0 || length<=0){
		throw "Out of bounds";
	} else{
		int& a = arr[index];
		return a;
	}

}
