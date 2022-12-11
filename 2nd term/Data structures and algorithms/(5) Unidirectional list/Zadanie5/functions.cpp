#include "functions.h"
#include <iostream>
#include <iomanip>
#include "random"
using namespace std;

bool list :: is_empty() { //
	if (first == nullptr) return true;
	else return false;
}



void list :: push_back(int _data) { //
	Node* pointer = new Node(_data);
	if (is_empty()) {
		first = pointer;
		size++;
	}
	else {
		Node* temp = first;
		while (temp != nullptr) {
			if (temp->next == nullptr) { temp->next = pointer; break; }
			else temp = temp->next;
		}
		//temp = new Node(_data);
		size++;
	}
	
}


void list :: print() { //
	if (is_empty()) return;
	Node* pointer = first;
	while (pointer != nullptr) {
		cout << setw(2)<<pointer->data << " ";
		pointer = pointer->next;
	}
}

void list::generate(int len) { //

	for (int i = 0; i < len; i++) {
		int value = rand() % 100;
		this->push_back(value);
	}
}

Node* list::operator[] (const int index) { //
	if (is_empty()) return nullptr;
	Node* pointer = first;
	for (int i = 0; i < index; i++) {
		pointer = pointer->next;
		if (!pointer) return nullptr;
	}
	return pointer;
}

void delete_M(list l, list m) { //
	for (int i = m.size - 1; i >= l.size-1; i--)
		m[i]->next = nullptr;
}


//int main() {
//	srand(time(NULL));
//	list l,m;
//	l.generate(5);
//	m.generate(12);
//	l.print();
//	cout<<endl;
//	m.print();
//	delete_M(l, m);
//	cout << endl;
//	m.print();
//	/*cout << endl;
//	list2 n;
//	n.match(l, m);
//	n.print();*/
//}