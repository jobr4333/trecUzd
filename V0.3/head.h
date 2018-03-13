#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
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
using std::setprecision;
using std::setw;
using std::left;
using std::exception;

struct studentas {
    string vardas;
    string pavarde;
    vector <int> pazymiai;
    float vidurkis{}, mediana{}, galBalas{};
};

vector<studentas> stud;

#endif // HEAD_H_INCLUDED
