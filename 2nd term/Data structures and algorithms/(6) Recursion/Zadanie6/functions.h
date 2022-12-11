#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

bool is_identifier(string s, int pos) {
	if (pos == 0) {
		char symbol = s[pos];
		if ((symbol >= 'a') && (symbol <= 'z') || (symbol >= 'A') && (symbol <= 'Z'))
			return is_identifier(s, pos + 1);
		else return false;
	}
	else if (pos < s.size()) {
		char symbol = s[pos];
		if ((symbol >= 'a') && (symbol <= 'z') || (symbol >= 'A') && (symbol <= 'Z') || (symbol >= '0') && (symbol <= '9'))
			return is_identifier(s, pos + 1);
		else return false;
	}
	else return true;
}

struct Node {
	Node* next = nullptr;
	int data;
	Node(int _data) : data(_data), next(nullptr) {}
};

struct list {
	Node* first;
	int size = 0;
	list() : first(nullptr) {}

	bool is_empty();
	void push_back(int _data);
	void print();
	void generate(int len);
};

bool list::is_empty() { //
	if (first == nullptr) return true;
	else return false;
}

void list::push_back(int _data) { //
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
		temp = new Node(_data);
		size++;
	}

}

void list::print() { //
	if (is_empty()) return;
	Node* pointer = first;
	while (pointer != nullptr) {
		cout << setw(2) << pointer->data << " ";
		pointer = pointer->next;
	}
}

void list::generate(int len) { //

	for (int i = 0; i < len; i++) {
		int value = rand() % 100;
		this->push_back(value);
	}
}

void reverse2(list l, int n, list& m) {
	if (n <= 0) return;
	else {
		Node* pointer = l.first;
		for (int i = 0; i < n-1; i++) {
			pointer = pointer->next;
		}
		m.push_back(pointer->data);
		reverse2(l, n - 1, m);
	}
}
