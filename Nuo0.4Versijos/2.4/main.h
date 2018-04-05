#pragma once

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <list>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::ifstream;
using std::setprecision;
using std::setw;
using std::left;
using std::exception;
using std::list;

struct studentas {
	string vardas;
	string pavarde;
	vector <int> pazymiai;
	float vidurkis{}, mediana{}, galBalas{};
};

#endif // MAIN_H_INCLUDED
