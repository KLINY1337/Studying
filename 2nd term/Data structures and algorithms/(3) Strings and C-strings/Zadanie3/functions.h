#pragma once
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Field {
	char word[100];
	string word2;
	int amount=0;
};


bool check_dict(string s, string dict); // c++.cpp
void nabor_slovo(string text, string dict, vector <Field>& vec); // c++.cpp

bool check_dict_c(char* s, char* dict); // c.cpp
void nabor_slovo_ñ(char* text, char* dict, vector <Field> &vec); // c.cpp