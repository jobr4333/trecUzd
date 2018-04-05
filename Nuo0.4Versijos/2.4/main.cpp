// 2.4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "main.h"
#include "funkcijosSuStruktura.h"
#include "funkcijosBeStrukturos.h"
#include "funkcijosSuList.h"
#include <chrono>

int main() {
	int failuSkaicius = 5;										//kiek failu bus generuojama
	int pazymiuSkaicius = 6;									//kiek pazymiu bus generuojama
	int iter{};
	/*for (size_t iter = 0; iter != failuSkaicius; ++iter) {
		irasytiFailan(pazymiuSkaicius, iter);					//generuojami nauji failai su duomenimis
	}*/
	for (size_t iter = 0; iter != failuSkaicius; ++iter) {
		skaitymas(iter);										//skaitomi failai
		skaiciuotiGalutiniBala(pazymiuSkaicius, iter);
		kietasArNe(pazymiuSkaicius, iter);
		spausdinti(iter);		
		sunaikinti();											//sunaikinama naudota struktura (kad duomenys nesusilietu)
		cout << "______________________________" << endl;
	}

	for (size_t iter = 0; iter != failuSkaicius; ++iter) {
		skaitymasList(iter);										//skaitomi failai
		skaiciuotiGalutiniBalaList(pazymiuSkaicius, iter);
		kietasArNeList(pazymiuSkaicius, iter);
		spausdintiList(iter);
		sunaikintiList();											//sunaikinama naudota struktura (kad duomenys nesusilietu)
		cout << "______________________________" << endl;
	}

}