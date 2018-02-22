#include "List.hpp"
#include <utility>

List::List(){
	head = nullptr;
	length = 0;
}

//Copies over the info of the List as well as the contents of the list to
//a new list
List::List(const List& other){
	if(other.head != nullptr){
		ListNode* temp_other = other.head;
		head = new ListNode(temp_other->get_data());
		ListNode* curr_node = head;
		temp_other = temp_other->get_next();
		length = other.length;
			while(temp_other != nullptr){
				ListNode* a = new ListNode(temp_other->get_data());
				curr_node->set_next(a);
				curr_node = a;
				temp_other = temp_other->get_next();
			}
	} else{
	head = other.head;
	length = other.length;
	}
}

//Moves the list to a new list.
List::List(List&& other){
	head = other.head;
	other.head = nullptr;
	length = other.length;
	other.length= 0;
}

//Sets each Listnodes values to nullptr & 0 and deletes them, 
//then sets the List's data to 0 & nullptr
List::~List(){
	if(head!=nullptr){
		ListNode* temp = head;
		while(temp->get_next()!=nullptr){
			temp->set_next(temp->get_next());
			head->set_next(nullptr);
			delete head;
			head = temp;
		}
		head->set_next(nullptr);
		delete head;
	}
	length = 0;
}

//Creates a new listnode with given integer and inserts it at the end of the
//list
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

//Inserts a new node by creating a new node then inserting that new node
//at the given index and setting the correct pointers for and to that new node
void List::insert(int index, int num){
	if(index>length || index<0){
		throw "Out of bounds";
	} else if(index==0){
		ListNode *b = new ListNode(num);
		ListNode *oldhead = head;
		head = b;
		b->set_next(oldhead);
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

//Removes the node at the given index and uses temp nodes to set the correct
//Pointers for the nodes between the removed node
void List::remove(int index){
	if(index>=length || index<0 || length==0){
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
		delete temp2;
		length--;
	} else if(index==0) {
		ListNode* temp = head;
		head = temp->get_next();
		temp->set_next(nullptr);
		temp->set_data(0);
		length--;
	}
}

//Gets the int value of the Listnode at the given index.
int List::get(int index) const{
	if(index>=length || index<0 || length==0){
		throw "Out of bounds";
	} else{ 
		ListNode* temp = head;
		for(int i=0;i<index;i++){
			temp = temp->get_next();
		}
		return temp->get_data();}
}

//Returns length
std::size_t List::size() const{
	return length;
}

//Returns the addres of the int of the Listnode at the given index.
int& List::operator[](int index){
	if(index>=length || index<0 || length==0){
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
