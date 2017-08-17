#include <iostream>
#include <string>
#include <stdlib.h> 
#include "LinkedList.cpp"

using namespace std;

int main () {
	LinkedList<int>* list = new LinkedList<int>();
	list->set(2);
	for (int i = 0; i < 20; ++i)
	{
		list->push(rand() % 102);
	}

	while(list->next()){
		cout << list->get() << endl;
	}

	cout << "\nSORTED\n\n";
	list->setCurrentNode(0);
	cout <<  "DEBUG LINE: " << list->get() << endl;
	list->sort();

	
	list->setCurrentNode(0);
	while(list->next()){
		cout << list->get() << endl;
	}

	cout << endl << list->length() << endl;
	return 0;
}


