// 2.4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "studentas.h"
#include "funkcijosSuStruktura.h"
#include "funkcijosBeStrukturos.h"
#include <chrono>


int main() {
	studentas StudentInstance;
	int failuSkaicius = 5;										//kiek failu bus generuojama
	int const pazymiuSkaicius = 5+1;									//kiek pazymiu bus generuojama
	int iter{};

	/*for (size_t iter = 0; iter != failuSkaicius; ++iter) {
		StudentInstance.irasytiFailan(pazymiuSkaicius, iter);					//generuojami nauji failai su duomenimis
	}
	*/
	int i = 1; //SVARBU. Tai Strategijos NR.

	cout << "PIRMA STRATEGIJA" << endl;
	cout << "Vektoriai" << endl;
	for (size_t iter = 0; iter != failuSkaicius; ++iter) {
		StudentInstance.skaitymas(iter);										//skaitomi failai
		StudentInstance.skaiciuotiGalutiniBala(pazymiuSkaicius, iter);
		StudentInstance.kietasArNe(pazymiuSkaicius, iter, i);
		StudentInstance.rikioti();
		StudentInstance.spausdinti(iter);
		StudentInstance.sunaikinti();											//sunaikinama naudota struktura (kad duomenys nesusilietu)
		cout << "______________________________" << endl;
	}

	//-------------------------------------
	i = 2; //SVARBU. Tai Strategijos NR.
	//-------------------------------------

	cout << "ANTRA STRATEGIJA" << endl;
	cout << "vektoriai" << endl;
	for (size_t iter = 0; iter != failuSkaicius; ++iter) {
		StudentInstance.skaitymas(iter);										//skaitomi failai
		StudentInstance.skaiciuotiGalutiniBala(pazymiuSkaicius, iter);
		StudentInstance.kietasArNe(pazymiuSkaicius, iter, i);
		StudentInstance.spausdinti(iter);
		StudentInstance.sunaikinti();											//sunaikinama naudota struktura (kad duomenys nesusilietu)
		cout << "______________________________" << endl;
	}
}