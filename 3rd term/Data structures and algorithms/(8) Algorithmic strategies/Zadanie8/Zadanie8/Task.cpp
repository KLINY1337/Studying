#include "Task.h"
#include <algorithm>
#include <iostream>
using namespace std;
//Конструктор класса BackpackProblem
BackpackProblem::BackpackProblem(int* calories, int* fat, int maxCalories, int size) {
	this->calories = calories;
	this->fat = fat;
	this->maxCalories = maxCalories;
	this->size = size;
}
//Метод решения задачи
tuple<int, int, vector<pair<int,int>>> BackpackProblem::solve() {
	pair<int, int>* arr = new pair<int, int>[size];

	for (int i = 0; i < size; i++) {
		arr[i].first = fat[i];
		arr[i].second = calories[i];
	}
	sort(arr, arr + size, [](pair<int, int> a, pair<int, int> b) {return a.first * 1.0 / a.second > b.first * 1.0 / b.second; });


	int currentCalories = 0;
	int currentFat = 0;
	vector<pair<int, int>> values;

	for (int i = 0; i < size; i++) {
		if (currentCalories + arr[i].second <= maxCalories) {

			currentCalories += arr[i].second;
			currentFat += arr[i].first;
			values.push_back(make_pair(arr[i].first, arr[i].second));

		}
	}
	delete[] arr;
	//cout << currentCalories << " " << currentFat;
	return make_tuple(currentFat, currentCalories, values);
}

//int main() {
//	int c[5] = { 5,3,6,1,8 };
//	int f[5] = { 9,7,2,1,4 };
//
//	BackpackProblem obj(c, f, 15, 5);
//	tuple<int, int, vector<pair<int, int>>> answer = obj.solve();
//
//	cout << get<0>(answer) << " " << get<1>(answer)<<"\n\n";
//
//	for (int i = 0; i < get<2>(answer).size(); i++) {
//		cout << get<2>(answer)[i].first << " " << get<2>(answer)[i].second << "\n";
//	}
//}