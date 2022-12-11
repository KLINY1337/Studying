#pragma once


struct Node {
	Node* next = nullptr;
	Node* previous = nullptr;
	int data;
	Node(int _data) : data(_data), next(nullptr) {}
};



struct list {
	Node* first;
	int size=0;
	list() : first(nullptr) {}

	bool is_empty();

	void push_back(int _data);
	void print();


	void generate(int len);
	Node* operator[](const int index);
};
////////////////////////////////////////////////////////////////////////////////////////

struct Node2 {
	Node2* next = nullptr;
	int dataL;
	int dataM;
	Node2(int _dataL, int _dataM) : dataL(_dataL), dataM(_dataM), next(nullptr) {}
};

struct list2 {
	Node2* first;

	list2() : first(nullptr) {}

	bool is_empty();
	void push_back(int _dataL, int _dataM);
	void print();
	void match(list l, list m);
};

void delete_M(list l, list m);