#include "IntList.h"

#include <iostream>
using namespace std;

int main() {
	IntList intlist;
	intlist.push_front(5);
	intlist.push_front(7);
	intlist.push_front(9);
	cout << intlist << endl;

	intlist.pop_front();
	cout << intlist << endl;
	
	return 0;
}
