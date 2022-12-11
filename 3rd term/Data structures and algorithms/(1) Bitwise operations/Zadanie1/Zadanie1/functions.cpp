#include <iostream>
#include <string>

#include "functions.h"

using namespace std;
//Функция вывода двоичного представления числа на экран
void cout_bin(unsigned short int x) {
	string s = "";
	for (int i = 0; i < 16; i++) {
		s += to_string(x % 2);
		x = x / 2;
	}
	for (int i = s.size() - 1; i >= 0; i--)
		cout << s[i];
}
//Функция установки 1,6,9 битов в единицу (Упр. 1)
unsigned short int set_bits_1_6_9(unsigned short int x) {
	return x | 578;
}
//Функция установки 1,6,9 битов в ноль (Упр. 2)
unsigned short int null_bits_1_6_9(unsigned short int x) {
	return x & 64957;
}
//Функция умножения исходного числа на 8 (Упр. 3)
unsigned short int multiply_by_8(unsigned short int x) {
	return x << 3;
}
//Функция деления исходного числа на 8 (Упр. 4)
unsigned short int divide_by_8(unsigned short int x) {
	return x >> 3;
}
//Функция установки n-го бита в значение 1 (Упр. 5)
unsigned short int set_n_bit(unsigned short int x, int n) {
	unsigned short int mask = 1;
	mask = mask << n;
	return x | mask;
}
