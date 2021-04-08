#include "IntList.h"
#include <iostream>

using namespace std;

// should work
IntList::IntList () {
	dummyHead = nullptr;
	dummyTail = nullptr;
}

IntList::~IntList() {
	while (!empty()) {
        pop_front();
    }
}

// should work
bool IntList::empty() const{
	if(dummyHead->next == nullptr && dummyTail->prev == nullptr)
        return true;

    return false;
}

void IntList::pop_front(){
	if (!empty()) {
        IntNode* temp = dummyHead->next;
        dummyHead->next = dummyHead->next->next;
        delete temp;
    }

    if(dummyHead->next == nullptr)
        dummyTail->prev = nullptr;

}

void IntList::push_front(int value){
	
}

void IntList::push_back(int value){
	
}

void IntList::pop_back(){

}

ostream & operator<<(ostream &out, const IntList &rhs) {
	if(rhs.empty())
      return out;

    IntNode* curr = rhs.dummyHead->next;
    out << curr->data;

	while(curr->next != nullptr) {
            curr = curr->next;
            out << ' ' << curr->data;
        }
    
    return out;
}

void IntList::printReverse() const{

} 
