#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "functions.h"
using namespace std;

bool check_dict_c(char* s, char* dict) {

	char slovo[100];
	
	int p = 0;
	for (int i = 0; i < strlen(dict); i++) {
		if (dict[i] != ' ') { slovo[p] = dict[i]; p++; }
		else {
			slovo[p] = '\0';
			
			if (strcmp(s,slovo)==0) return true;
			else { memset(slovo, 0, strlen(slovo)); p = 0; }
		}
	}
	return false;
}

void nabor_slovo_ñ(char* text, char* dict, vector <Field>& vec) {
	dict[strlen(dict) - 1] = ' ';
	dict[strlen(dict)] = '\0';
	text[strlen(text) - 1] = ' ';
	text[strlen(text)] = '\0';
	char slovo [100];
	int p = 0;

	for (int i = 0; i < strlen(text); i++) {
		if (text[i] != ' ') { slovo[p] = text[i]; p++; }
		else {
			slovo[p] = '\0';
			Field words;
			if (check_dict_c(slovo, dict)) { 
				words.amount++;
				strcpy(words.word, slovo);

				int flag = 0;
				for (int j = 0; j < vec.size(); j++) {
					if (strcmp(words.word, vec[j].word) == 0) {
						vec[j].amount++;
						flag++;
					}

				}
				if (flag == 0) vec.push_back(words);
				
			}
			memset(slovo, 0, strlen(slovo)); p = 0;
		}
	}

}

