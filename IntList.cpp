#include "IntList.h"

using namespace std;

// works
IntList::IntList () {
	dummyHead = new IntNode(0);
	dummyTail = new IntNode(0);

	dummyHead->next = dummyTail;
	dummyHead->prev = nullptr;

	dummyTail->prev = dummyHead;
	dummyTail->next = nullptr;
}

// works
IntList::~IntList() {
    IntNode* curr = dummyHead;
	while (curr != nullptr) {
    	IntNode* temp = curr;
		curr = curr->next;
		delete temp;
    }
}

// works
bool IntList::empty() const{
	if(dummyHead->next == dummyTail)
        return true;

    return false;
}

// works
void IntList::pop_front(){
	IntNode* first = dummyHead->next;

	if (first != dummyTail) {
		dummyHead->next = first->next;
		first->next->prev = dummyHead;
		delete first;
	}
}

// works
void IntList::push_front(int value){
	IntNode* temp = new IntNode(value);
	temp->prev = dummyHead;
	temp->next = dummyHead->next;
	temp->next->prev = temp;
	dummyHead->next = temp;
}

// not sure
void IntList::push_back(int value){
	IntNode* temp = new IntNode(value);
	temp->next = dummyTail;
	temp->prev = dummyTail->prev;
	temp->prev->next = temp;
	dummyTail->prev = temp;
}

// not sure
void IntList::pop_back(){
	IntNode* last = dummyTail->prev;

	if (last != dummyHead) {
		dummyTail->prev = last->prev;
		last->prev->next = dummyTail;
		delete last;
	}
}

// works
ostream & operator<<(ostream &out, const IntList &rhs) {
	if(rhs.empty())
      return out;

    IntNode* curr = rhs.dummyHead->next;

	for (int i = 1; curr != rhs.dummyTail; curr = curr->next) {
		if (i < 2) // first node output
			out << curr->data;
		else // succeeding node outputs
			out << " " << curr->data;
		
		i++;
	}

	/*
	while(curr != rhs.dummyTail) {
        out << curr->data;

		if (curr->next = rhs.dummyTail)
			out << " ";

        curr = curr->next;
    } */
    
    return out;
}

void IntList::printReverse() const{
	if(empty())
		return;

	IntNode* curr = dummyTail->prev;

	/*
	if (dummyTail->prev == dummyHead) {
		cout << curr->data;
		return;
	} */

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
