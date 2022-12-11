#include "functions.h"
#include <cmath>

int solve_prefix(string prefix) {
	Stack operandStack("",prefix.size()+1);
	for (int i = prefix.size() - 1; i >= 0; i--) {
		if (isdigit(prefix[i])) operandStack.AddEl(prefix[i] - '0');
		else {
			int operand1;
			operandStack.TakeEl(operand1);
			
			int operand2;
			operandStack.TakeEl(operand2);
			if (prefix[i] == '+') operandStack.AddEl(operand1 + operand2);
			else
				if (prefix[i] == '-') operandStack.AddEl(operand1 - operand2);
				else
					if (prefix[i] == '*') operandStack.AddEl(operand1 * operand2);
					else
						if (prefix[i] == '/') operandStack.AddEl(operand1 / operand2);
						else
							if (prefix[i] == '^') operandStack.AddEl(pow(operand1, operand2));
		}
	}
	int result;
	operandStack.TakeEl(result);
	return result;
}

Stack::Stack(string _name, int _size) {
	name = _name; // присвоение имени стека
	size = _size; // присвоение размера стека
	a = new int[size]; // выделение памяти для массива
	curlen = -1; // инициализация текущей длины -1
}

int Stack::StackSize() { // возврат размера стека
	return size;
}

int Stack::CurrentLength() { // возврат текущей длины стека
	return curlen + 1;
}

string Stack::StackName() { // возврат имени стека
	return name;
}

bool Stack::AddEl(int _el) {
	curlen++; // инкрементирование текущей длины
	if (curlen <= size - 1) { a[curlen] = _el; return true; } // инициализация элемента стека
	else
		return false;
}

bool Stack::TakeEl(int& m) {
	if (CurrentLength() > 0) { // извлечение элемента стека
		m = a[CurrentLength() - 1];
		curlen--; // декрементирование текущей длины стека
		return true;
	}
	else return false;

}