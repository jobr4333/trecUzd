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
using std::copy_if;
using std::remove_if;
using std::back_inserter;

/*struct studentas {
	string vardas;
	string pavarde;
	vector <int> pazymiai;
	int egz;
	double vidurkis{}, mediana{}, galBalas{};
};*/

class studentas {
	private:
		string vardas;
		string pavarde;
		vector <int> pazymiai;
		double vidurkis{}, mediana{}, galBalas{};

	public: 
		void studentas::skaitymas(int iter);
		void studentas::rikioti();
		bool studentas::rikiuotiPagalPavarde(const studentas &a, const studentas &b);
		void studentas::spausdinti(int iter);
		void studentas::irasytiFailan(int pazymiuSkaicius, int iter);
		void studentas::sunaikinti();
		void studentas::skaiciuotiGalutiniBala(int pazymiuSkaicius, int iter);
		void studentas::kietasArNe(int pazymiuSkaicius, int iter, int i);

};

#endif // MAIN_H_INCLUDED
