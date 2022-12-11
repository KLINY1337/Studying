#include <string>
#include <vector>
#include <iostream>
using namespace std;

void str_sort(string& s) {
	for (int i = 0; i < s.size(); i++)
		if (!((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))) s[i] = ' ';
}

void cout_vector(vector <string>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j];
		}
		cout << " ";
	}
}

string cut_str(string& start_s) {
	string s = "";
	int i = 0;

	while (start_s[i] != '.' && i < start_s.size()) {
		s += start_s[i];
		i++;
	}

	return s;
}

int letters_pairs(string s, vector <string> &vec) {

	for (int i = 0; i < s.size() - 1; i++) {
		string temp = "";

		temp += s[i];
		temp += s[i + 1];

		if (temp.find(" ") == -1) vec.push_back(temp);
	}

	for (int i = 0; i < vec.size(); i++)
		if (count(vec.begin(), vec.end(), vec[i]) > 1) {
			vec.erase(vec.begin() + i); i = 0;
		}

	return vec.size();
}