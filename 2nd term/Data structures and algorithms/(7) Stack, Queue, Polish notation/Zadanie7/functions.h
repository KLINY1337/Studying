#pragma once
#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
	string name;
	int size;
	int curlen;
	int* a;
public:

	Stack(string _name, int _size);
	bool AddEl(int _el);
	bool TakeEl(int& m);
	string StackName();
	int StackSize();
	int CurrentLength();
};



int solve_prefix(string prefix);

