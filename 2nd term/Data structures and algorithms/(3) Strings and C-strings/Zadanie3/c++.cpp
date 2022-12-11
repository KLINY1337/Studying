#include <string>
#include <iostream>
#include "functions.h"
using namespace std;

bool check_dict(string s, string dict) {

	string slovo = "";
	dict += " ";

	for (int i = 0; i < dict.size(); i++) {
		if (dict[i] != ' ') slovo += dict[i];
		else {
			if (s == slovo) return true;
			else slovo = "";
		}
	}
	return false;
}

void nabor_slovo(string text, string dict, vector <Field>& vec) {
	text += " ";
	string slovo = "";

	for (int i = 0; i < text.size(); i++) {
		if (text[i] != ' ') slovo += text[i];
		else {
			Field words;
			if (check_dict(slovo, dict)) { 
				words.amount++;
				words.word2 = slovo;
				int flag = 0;
				for (int j = 0; j < vec.size(); j++) {
					if (words.word2 == vec[j].word2) {
						vec[j].amount++;
						flag++;
					}

				}
				if (flag == 0) vec.push_back(words);
			}
			slovo = "";
		}
	}
}


