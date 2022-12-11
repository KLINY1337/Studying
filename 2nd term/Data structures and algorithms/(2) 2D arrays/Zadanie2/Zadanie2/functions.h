#pragma once
#include <iostream>
#include <string>
#include <vector>

const int Rows = 7; // Ограничение строк для статического массива
const int Cols = 7; // Ограничение столбцов для статического массива

using namespace std;
double static_determinant(double(*matrix)[Cols], int n); // static.cpp
void initialize_static(double(*matrix)[Cols], int n); // static.cpp
void cout_static(double(*matrix)[Cols], int n); // static.cpp

double dynamic_determinant(double** matrix, int n); // dynamic.cpp
void initialize_dynamic(double** matrix, int n); // dynamic.cpp
void cout_dynamic(double** matrix, int n); // dynamic.cpp

void str_sort(string& s); // vector.cpp
int letters_pairs(string s, vector <string>& vec); // vector.cpp
void cout_vector(vector <string>& vec); // vector.cpp
string cut_str(string& start_s); // vector.cpp