#pragma once
#ifndef TASK_H
#define TASK_H

#include <utility>
#include <tuple>
#include <vector>

class BackpackProblem {
private:
	int* calories;
	int* fat;
	int maxCalories;
	int size;

public:
	BackpackProblem(int* calories, int* fat, int maxCalories, int size);
	std::tuple<int, int, std::vector<std::pair<int, int>>> solve();
};

#endif // !TASK_H
