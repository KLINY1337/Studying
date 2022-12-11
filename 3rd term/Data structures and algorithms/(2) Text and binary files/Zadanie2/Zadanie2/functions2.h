#pragma once
#include <string>
#include <iostream>
using namespace std;
void textToBin(string file_name_txt, string file_name_bin);
void binToText(string file_name_txt, string file_name_bin);
void fileOutputBin(string file_name);
string fileGet(string file_name, int index);
void fileDelete(string file_name, int index);
void switchTI(string file_name, string number, string date);
void checkCars(string file_name, string car, string date);