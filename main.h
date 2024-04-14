#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <vector>
#include <fstream>

std::string inputText(const std::string& pot);

void izpis_KMPnext(const int* polje, int len);

void KMP(const std::string& text, const std::string& vzorec);

void Sunday(const std::string& text, const std::string& vzorec);

void bubbleSort(std::vector<int>& arr);

int sestej(int a, int b);

#endif // MAIN_H
