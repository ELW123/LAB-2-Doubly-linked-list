/* 	Collaborated with: 
	Ethan Wan, 
	Ethan Wan's prior program assignments in CS 10B, 
	Mariam Golwalla,  
	zybooks.com - CS 10C and CS 10B, 
	github.com to host our code
*/

#include "IntList.h"

using namespace std;

IntList::IntList () {
	dummyHead = new IntNode(0);
	dummyTail = new IntNode(0);

	dummyHead->next = dummyTail;
	dummyHead->prev = nullptr;

	dummyTail->prev = dummyHead;
	dummyTail->next = nullptr;
}

IntList::~IntList() {
    IntNode* curr = dummyHead;
	while (curr != nullptr) {
    	IntNode* temp = curr;
		curr = curr->next;
		delete temp;
    }
}

bool IntList::empty() const{
	if(dummyHead->next == dummyTail)
        return true;

    return false;
}

void IntList::pop_front(){
	IntNode* first = dummyHead->next;

	if (first != dummyTail) {
		dummyHead->next = first->next;
		first->next->prev = dummyHead;
		delete first;
	}
}

void IntList::push_front(int value){
	IntNode* temp = new IntNode(value);
	temp->prev = dummyHead;
	temp->next = dummyHead->next;
	temp->next->prev = temp;
	dummyHead->next = temp;
}

void IntList::push_back(int value){
	IntNode* temp = new IntNode(value);
	temp->next = dummyTail;
	temp->prev = dummyTail->prev;
	temp->prev->next = temp;
	dummyTail->prev = temp;
}

void IntList::pop_back(){
	IntNode* last = dummyTail->prev;

	if (last != dummyHead) {
		dummyTail->prev = last->prev;
		last->prev->next = dummyTail;
		delete last;
	}
}

ostream & operator<<(ostream &out, const IntList &rhs) {
	if(rhs.empty())
      return out;

    IntNode* curr = rhs.dummyHead->next;
	
	while(curr != rhs.dummyTail) {
        if (curr->next == rhs.dummyTail) {
			out << curr->data;
			return out;
		} else {
			out << curr->data << " ";
		}

		curr = curr->next;
    } 

    return out;
}

void IntList::printReverse() const{
	if(empty())
		return;

	IntNode* curr = dummyTail->prev;

	while (curr != dummyHead) {
		if (curr->prev == dummyHead) {
			cout << curr->data;
			return;
		} else {
			cout << curr->data << " ";
		}

		curr = curr->prev;
	}
} 
