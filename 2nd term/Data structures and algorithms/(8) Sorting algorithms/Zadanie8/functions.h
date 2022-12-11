#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

void bubble_sort(int* a, int len);

void count_sort(int* a, int len);

int partition(int* a, int left, int right);
void quick_sort(int* a, int left, int right);

void fill_arr(int* a, int len);
void fill_random(int* a, int len);
void print_array(int* a, int len);