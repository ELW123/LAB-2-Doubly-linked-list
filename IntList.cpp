#include "IntList.h"

using namespace std;

// should work
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

// should work
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
	
}

void IntList::pop_back(){

}

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

        curr = curr->next;
    } */
    
    return out;
}

void IntList::printReverse() const{

} 
