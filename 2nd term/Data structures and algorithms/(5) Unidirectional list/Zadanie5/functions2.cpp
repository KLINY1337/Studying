#include "functions.h"
#include <iostream>
#include <iomanip>
#include "random"
using namespace std;

bool list2::is_empty() {
	if (first == nullptr) return true;
	else return false;
}

void list2::push_back(int _dataL, int _dataM) { //

		//cout << l[i]->data << " " << m[i]->data<<endl;
		Node2* pointer = new Node2(_dataL, _dataM);
		if (is_empty()) {
			first = pointer;
		}
		else {
			Node2* temp = first;
			while (temp != nullptr) {
				if (temp->next == nullptr) { temp->next = pointer; break; }
				else temp = temp->next;
			}
			//temp = new Node2(_dataL, _dataM);
		}
}

void list2::match(list l, list m) {
	for (int i = 0; i < max(l.size,m.size); i++) {
		if (i >= l.size) push_back(-1, m[i]->data);
		else
		if (i >= m.size) push_back(l[i]->data, -1);
		else push_back(l[i]->data, m[i]->data);
	}
}

void list2::print() { //

	if (is_empty()) return;
	Node2* pointer = first;
	while (pointer != nullptr) {
		cout << setw(2) << pointer->dataL << " " << pointer->dataM << "\n";
		pointer = pointer->next;
	}

}