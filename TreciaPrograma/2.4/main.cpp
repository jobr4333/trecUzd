// 2.4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "main.h"
#include "funkcijosSuStruktura.h"
#include "funkcijosBeStrukturos.h"
#include <chrono>

int main() {
	studentas StudentInstance;

	list<studentas> studList;
	list<studentas> kietasList;
	list<studentas> luzerisList;

	int failuSkaicius = 5;										//kiek failu bus generuojama
	int pazymiuSkaicius = 5+1;									//kiek pazymiu bus generuojama
	int iter{};
	/*for (size_t iter = 0; iter != failuSkaicius; ++iter) {
		irasytiFailan(pazymiuSkaicius, iter);					//generuojami nauji failai su duomenimis
	}*/
	int i = 1; //SVARBU. Tai Strategijos NR.
	cout << "PIRMA STRATEGIJA" << endl;
	cout << "Vektoriai" << endl;
	for (size_t iter = 0; iter != failuSkaicius; ++iter) {
		StudentInstance.skaitymas(iter);										//skaitomi failai
		StudentInstance.skaiciuotiGalutiniBala(pazymiuSkaicius, iter);
		StudentInstance.kietasArNe(pazymiuSkaicius, iter, i);
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