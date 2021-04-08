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
	intlist.push_front(5);
	intlist.push_front(7);
	intlist.push_front(9);
	cout << intlist << endl;

	intlist.pop_front();
	cout << intlist << endl;
	
	return 0;
}
