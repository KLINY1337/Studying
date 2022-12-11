#pragma once
#include <iostream>
#include <string>
using namespace std;

void fileInput(string file_name, string data);
void fileAppend(string file_name, string data);
string fileOutput(string file_name);

void filePasteNumbers(string file_name);
void fileAppendString(string file_name);
int fileReadNumber(string file_name, int index);
int fileCountNumber(string file_name);

void fileAppendArrays(string file_name_1, string file_name_2);