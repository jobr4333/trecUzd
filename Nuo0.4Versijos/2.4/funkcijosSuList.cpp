//
// Created by Base on 2018-03-20.
//
#include "stdafx.h"
#include "main.h"
#include "funkcijosSuList.h"

list<studentas> studList;
list<studentas> kietasList;
list<studentas> luzerisList;

void skaitymasList(int iter) {
	auto start = std::chrono::high_resolution_clock::now(); //laiko matavimo start
	ifstream sk("txt/sudentai" + to_string(iter) + ".txt");
	string tempS, temp;
	int num{}, t{};
	try {
		if (!sk.good()) throw 404;
		else if (sk.peek() == ifstream::traits_type::eof()) throw 0;
	}

	catch (int errNo) {
		cout << "Ivyko klaida. Klaidos NR: " << errNo << endl;
		cout << "Paaiskinimas:" << endl << "404 - failo nera." << endl << "0 - failas tuscias." << endl << "1 - failas tuscias, tik tarpai." << endl;
		//exit(errNo);
	}

	if (sk.good()) {
		vector<string> tempStud;
		studentas temp;
		string vardas, pavarde;
		int t{};
		while (getline(sk, tempS)) {
			std::istringstream iss(tempS);
			iss >> temp.pavarde;
			iss >> temp.vardas;
			
			while (iss >> num) {
				temp.pazymiai.push_back(num);
				t++;
			}
			try {
				if (temp.pazymiai.size() == 0) { //labai palankiai veikia, nezinau kodel
					throw 1;
				}
			}
			catch (int errNo) {
				cout << "Ivyko klaida. Neteisingai ivesti pazymiai arba ju nera. Klaidos NR: " << errNo << endl;
				//exit(2);
			}
			t = 0;
			studList.push_back(temp);
			temp.pazymiai.clear();
		}
		sk.close();
	}
	auto finish = std::chrono::high_resolution_clock::now();//laiko matavimo finish
	std::chrono::duration<double> elapsed = finish - start;
	cout << left << setw(50) << "SkaitytiList vykdymo laikas " << iter << ": " << elapsed.count() << " s" << endl;
}

void spausdintiList(int iter) {
	auto start = std::chrono::high_resolution_clock::now(); //laiko matavimo start
	int studentuSkaicius = static_cast<int>(round(10 * pow(10, iter)));  //kitame faile bus 10x daugiau studentu
	ofstream rs("txt/kieti" + to_string(iter) + ".txt");
	for (auto i : studList) {
		rs << i.vardas << " " << i.pavarde << " ";
		for (size_t t = 0; t != i.pazymiai.size(); ++t) {
		rs << i.pazymiai[t] << " ";
		}
		rs << i.vidurkis << " " << i.galBalas;
		rs << endl;
	}
	rs << endl;
	auto finish = std::chrono::high_resolution_clock::now();//laiko matavimo finish
	std::chrono::duration<double> elapsed = finish - start;
	cout << left << setw(50) << "spausdintiList vykdymo laikas " << iter << ": " << elapsed.count() << " s" << endl;
}

void skaiciuotiGalutiniBalaList(int pazymiuSkaicius, int iter) {
	auto start = std::chrono::high_resolution_clock::now(); //laiko matavimo start
	int studentuSkaicius = static_cast<int>(round(10 * pow(10, iter)));
	float vid{};

	for (auto p : studList) {
		for (auto t : p.pazymiai) {
			vid = vid + t;
		}
		vid = vid / pazymiuSkaicius;
		p.vidurkis = vid;
		p.galBalas = static_cast<float>(vid*0.4 + p.pazymiai[pazymiuSkaicius - 1] * 0.6);
	}
	auto finish = std::chrono::high_resolution_clock::now();//laiko matavimo finish
	std::chrono::duration<double> elapsed = finish - start;
	cout << left << setw(50) << "skaiciuotiGalutiniBalaList vykdymo laikas " << iter << ": " << elapsed.count() << " s" << endl;
}

void kietasArNeList(int pazymiuSkaicius, int iter) {
	auto start = std::chrono::high_resolution_clock::now(); //laiko matavimo start
	unsigned i{}, n{};
	int studentuSkaicius = static_cast<int>(round(10 * pow(10, iter)));
	for (auto p : studList) {
		if (p.galBalas >= 5.0) kietasList.push_back(p);
		else luzerisList.push_back(p);
	}
	auto finish = std::chrono::high_resolution_clock::now();//laiko matavimo finish
	std::chrono::duration<double> elapsed = finish - start;
	cout << left << setw(50) << "kietasArNeList vykdymo laikas " << iter << ": " << elapsed.count() << " s" << endl;
}


void sunaikintiList() {
	studList.clear();
}