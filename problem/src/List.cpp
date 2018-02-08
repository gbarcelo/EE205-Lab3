#include <iostream>
#include "List.hpp"
#include <utility>

List::List(){
	head = nullptr;
	length = 0;
}

List::List(const List& other){
	head = other.head;
	length = other.length;
}

List::List(List&& other){
	head = other.head;
	other.head = nullptr;
	length = other.length;
	other.length= 0;
}

List::~List(){
	head = nullptr;
}

void List::append(int num){
	if(length!=0){
	ListNode *b = new ListNode(num);
	ListNode* temp = head;
	while(temp->get_next()!=nullptr){
		temp = temp->get_next();
	}
	temp->set_next(b);
	length++;
	} else if(length ==0){
	head = new ListNode(num);
	length++;
	}
}
void List::insert(int index, int num){
	if(index>length || index<0){
		throw "Out of bounds";
	} else if(length == 0 && index==0){
			ListNode *b = new ListNode(num);
			head = b;
			length++;
	} else{
	ListNode* temp = head;
	ListNode *a = new ListNode(num);
	for(int i=0;i<index-1;i++){
		temp = temp->get_next();
	}
	if(temp->get_next() ==nullptr){
		temp->set_next(a);
	} else if(temp ->get_next() != nullptr){
		a->set_next(temp->get_next());
		temp->set_next(a);
	}
	length++;
		}
	}

void List::remove(int index){
	if(index>length || index<0 || length==0){
		throw "Out of bounds";
	} else if(index!=0){
		ListNode* temp1 = head;
		ListNode* temp2;
		for(int i=0;i<index-1;i++){
			temp1 = temp1->get_next();
		}
		temp2 = temp1->get_next();
		temp1 = temp2->get_next();
		temp2->set_next(nullptr);
		temp2->set_data(0);
		length--;
	} else if(index==0) {
		ListNode* temp = head;
		head = temp->get_next();
		temp->set_next(nullptr);
		temp->set_data(0);
		length--;
	}
}
int List::get(int index) const{
	if(index>length || index<0 || length==0){
		throw "Out of bounds";
	} else{ 
		ListNode* temp = head;
		for(int i=0;i<index;i++){
			temp = temp->get_next();
		}
		return temp->get_data();
}
}
std::size_t List::size() const{
	return length;
}

int& List::operator[](int index){
	if(index>length || index<0 || length==0){
		throw "Out of bounds";
	} else{
		
		ListNode* temp;
		temp = head;
		for(int b=0;b<index;b++){
			temp = temp->get_next();
		}
		int &a = temp->data;
		return a;
	}
}
