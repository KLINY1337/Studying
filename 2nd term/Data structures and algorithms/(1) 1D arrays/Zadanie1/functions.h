#pragma once
#include <iostream>
#include <vector>
using namespace std;

void initialize_array(int* arr, int len); //static(dynamic)_arr.cpp
void cout_array(int* arr, int len); //static(dynamic)_arr.cpp
bool is_sorted(int* arr, int len); //static(dynamic)_arr.cpp
void delete_for_sorted(int* arr, int& len, int divider); //static(dynamic)_arr.cpp
void add_for_unsorted(int* arr, int& len, int paste_element); //static(dynamic)_arr.cpp

void initialize_vector(vector <int>& vecInt, int len); //vector.cpp
void cout_vector(vector <int>& vecInt); //vector.cpp
bool is_sorted_vector(vector <int>& vecInt); //vector.cpp
void delete_for_sorted_vector(vector <int> &vecInt, int divider); //vector.cpp
void add_for_unsorted_vector(vector <int> &vecInt, int paste_element); //vector.cpp

