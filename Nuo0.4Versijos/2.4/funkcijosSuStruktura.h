//
// Created by Base on 2018-03-20.
//

#ifndef INC_2_4_CLION_FUNKCIJOSSUSTRUKTURA_H
#define INC_2_4_CLION_FUNKCIJOSSUSTRUKTURA_H

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::ifstream;
using std::ofstream;
using std::setprecision;
using std::setw;
using std::left;
using std::exception;
using std::to_string;

void skaitymas(int iter);
void rikioti();
bool rikiuotiPagalPavarde(const studentas &a, const studentas &b);
void spausdinti(int iter);
void irasytiFailan(int pazymiuSkaicius, int iter);
int randomPazymys();
void sunaikinti();
void skaiciuotiGalutiniBala(int pazymiuSkaicius, int iter);
void kietasArNe(int pazymiuSkaicius, int iter);

#endif //INC_2_4_CLION_FUNKCIJOSSUSTRUKTURA_H
