//
// Created by Base on 2018-03-20.
//
#include "stdafx.h"
#include "main.h"
#include "funkcijosSuList.h"

void skaitymasList(int iter, list<studentas> &studList) {
	auto start = std::chrono::high_resolution_clock::now(); //laiko matavimo start
	ifstream sk("txt/sudentai" + to_string(iter) + ".txt");
	string tempS, temp;
	int t{};
	try {
		if (!sk.good()) throw 404;
		else if (sk.peek() == ifstream::traits_type::eof()) throw 0;
	}

	catch (int errNo) {
		cout << "Ivyko klaida. Klaidos NR: " << errNo << endl;
		cout << "Paaiskinimas:" << endl << "404 - failo nera." << endl << "0 - failas tuscias." << endl << "1 - failas tuscias, tik tarpai." << endl;
		exit(errNo);
	}

	if (sk.good()) {
		studentas temp;
		int num{}, t{};

		while (getline(sk, tempS)) {
			std::istringstream iss(tempS);
			iss >> temp.pavarde;
			iss >> temp.vardas;

			for (size_t u = 0; u < 5; u++) {
				iss >> num;
				temp.pazymiai.push_back(num);
			}
			iss >> temp.egz;
			try {
				if (temp.pazymiai.size() == 0) { //labai palankiai veikia, nezinau kodel
					throw 1;
				}
			}
			catch (int errNo) {
				cout << "Ivyko klaida. Neteisingai ivesti pazymiai arba ju nera. Klaidos NR: " << errNo << endl;
				exit(2);
			}
			studList.push_back(temp);
			temp.pazymiai.clear();
		}
		sk.close();
	}
	cout << studList.size() << endl;

	auto finish = std::chrono::high_resolution_clock::now();//laiko matavimo finish
	std::chrono::duration<double> elapsed = finish - start;
	cout << left << setw(50) << "SkaitytiList vykdymo laikas " << iter << ": " << elapsed.count() << " s" << endl;
}

void spausdintiList(int iter, list<studentas> &kietasList) {
	auto start = std::chrono::high_resolution_clock::now(); //laiko matavimo start
	int studentuSkaicius = static_cast<int>(round(10 * pow(10, iter)));  //kitame faile bus 10x daugiau studentu
	ofstream rs("txt/kieti" + to_string(iter) + ".txt");
	for (auto i : kietasList) {
		rs << i.vardas << " " << i.pavarde << " ";
		for (size_t t = 0; t != i.pazymiai.size(); ++t) {
			rs << i.pazymiai[t] << " ";
		}
		rs << i.vidurkis << " " << i.mediana << " " << i.galBalas;
		rs << endl;
	}
	rs << endl;
	auto finish = std::chrono::high_resolution_clock::now();//laiko matavimo finish
	std::chrono::duration<double> elapsed = finish - start;
	cout << left << setw(50) << "spausdintiList vykdymo laikas " << iter << ": " << elapsed.count() << " s" << endl;
}

void skaiciuotiGalutiniBalaList(int pazymiuSkaicius, int iter, list<studentas>&studList) {
	auto start = std::chrono::high_resolution_clock::now(); //laiko matavimo start
	auto studentuSkaicius = static_cast<int>(round(10 * pow(10, iter)));
	float vid{};
	studentas temp;

	auto u = 1;
	auto pazymiuKiekis = pazymiuSkaicius - 2; //todel kad paskutinis pazymys eileje yra egzo rezultatas IR todel kad indeksai prasideda nuo 0 (jei reikia trecio nario masyve, TAI rasoma masyvas[2], o ne masyvas[3];

	for (auto &p : studList) { //vidurkis  VVVV
		for (size_t t = 0; t != 5; ++t) {
			vid = vid + p.pazymiai[t];
		}
		vid = vid / 5;
		//???????????????????????????????????????????????????????????????????
		p.vidurkis = vid;

		vid = 0;
		//cout << " vid : "<< p.vidurkis << endl;
		
		sort(p.pazymiai.begin(), p.pazymiai.end()); //mediana VVVV
		if (pazymiuSkaicius-1 % 2 == 0) p.mediana = (p.pazymiai[pazymiuKiekis /2] + p.pazymiai[(pazymiuKiekis /2)-1]) / 2.0;
		else p.mediana = p.pazymiai[pazymiuKiekis/2+1];
		//cout << " med : " << p.mediana << endl;
		if (u == 1) p.galBalas = static_cast<float>(p.vidurkis*0.4 + p.egz * 0.6);
		else if (u == 2) p.galBalas = static_cast<float>(p.mediana*0.4 + p.egz * 0.6);
	}
	auto finish = std::chrono::high_resolution_clock::now();//laiko matavimo finish
	std::chrono::duration<double> elapsed = finish - start;
	cout << left << setw(50) << "skaiciuotiGalutiniBalaList vykdymo laikas " << iter << ": " << elapsed.count() << " s" << endl;
}

bool arLuzeris (studentas&val) {
	return val.galBalas < 5.0;
}

void kietasArNeList(int pazymiuSkaicius, int iter, int i, list<studentas> &studList, list<studentas>&kietasList, list<studentas>&luzerisList) {
	auto start = std::chrono::high_resolution_clock::now(); //laiko matavimo start
	int studentuSkaicius = static_cast<int>(round(10 * pow(10, iter)));
	if (i == 1) { // pirma strategija su 3 konteineriais
		for (auto p : studList) {
			if (p.galBalas >= 5.0) kietasList.push_back(p);
			else luzerisList.push_back(p);
		}
	}
		
	else if (i == 2) { //antra strategija su 2 konteineriais
		copy_if(studList.begin(), studList.end(), back_inserter(luzerisList), arLuzeris);
		studList.erase(remove_if(studList.begin(), studList.end(), arLuzeris), studList.end());
	}
	auto finish = std::chrono::high_resolution_clock::now();//laiko matavimo finish
	std::chrono::duration<double> elapsed = finish - start;
	cout << left << setw(50) << "kietasArNeList vykdymo laikas " << iter << ": " << elapsed.count() << " s" << endl;
	kietasList.clear();
}


void sunaikintiList(list<studentas> &studList) {
	studList.clear();
}