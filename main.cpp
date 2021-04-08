/* 	Collaborated with: 
	Ethan Wan, 
	Ethan Wan's prior program assignments in CS 10B, 
	Mariam Golwalla,  
	zybooks.com - CS 10C and CS 10B, 
	github.com to host our code
*/

#include "IntList.h"

#include <iostream>
using namespace std;

int main() {
	IntList intlist;

	if (intlist.empty())
		cout << "intlist is empty - correct empty function" << endl;
	else
		cout << "incorrect empty function - intlist should be empty" << endl;

	intlist.push_front(5);

	if (intlist.empty())
		cout << "intlist is not empty - correct empty function" << endl;
	else
		cout << "incorrect empty function - intlist should not be empty" << endl;

	intlist.push_front(7);
	intlist.push_front(9);
	cout << intlist << endl;

	if (intlist.empty())
		cout << "intlist is not empty - correct empty function" << endl;
	else
		cout << "incorrect empty function - intlist should not be empty" << endl;

	intlist.pop_front();
	cout << intlist << endl;

	intlist.push_back(6);
	cout << intlist << endl;

	intlist.pop_back();
	cout << intlist << endl;

	intlist.printReverse();
	cout << intlist << endl;
	
	return 0;
}
