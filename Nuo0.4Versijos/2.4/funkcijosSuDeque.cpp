//
// Created by Base on 2018-03-20.
//
#include "stdafx.h"
#include "main.h"
#include "funkcijosSuDeque.h"

deque <studentas> stud;
deque <studentas> kietas;
deque <studentas> luzeris;

void skaitymasDeque(int iter) {
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
		exit(errNo);
	}

	if (sk.good()) {
		string temp;
		while (getline(sk, tempS)) {
			stud.push_back(studentas());
			std::istringstream iss(tempS);
			iss >> stud[t].pavarde;
			iss >> stud[t].vardas;
			while (iss >> num) {
				stud[t].pazymiai.push_back(num);
			}
			try {
				if (stud[t].pazymiai.size() == 0) { //labai palankiai veikia, nezinau kodel
					throw 1;
				}
			}
			catch (int errNo) {
				cout << "Ivyko klaida. Neteisingai ivesti pazymiai arba ju nera. Klaidos NR: " << errNo << endl;
				exit(2);
			}
			t++;
		}
		sk.close();
	}
	auto finish = std::chrono::high_resolution_clock::now();//laiko matavimo finish
	std::chrono::duration<double> elapsed = finish - start;
	cout << left << setw(40) << "skaitymas vykdymo laikas " << iter << ": " << elapsed.count() << " s" << endl;
}

/*bool rikiuotiPagalPavarde(const studentas &a, const studentas &b)
{
	return a.pavarde < b.pavarde;
}

void rikioti() {
	sort(stud.begin(), stud.end(), rikiuotiPagalPavarde);
}*/

void spausdintiDeque(int iter) {
	int studentuSkaicius = static_cast<int>(round(10 * pow(10, iter)));  //kitame faile bus 10x daugiau studentu
	ofstream rs("txt/kieti" + to_string(iter) + ".txt");
	for (size_t i = 0; i != kietas.size(); ++i) {
		rs << kietas[i].vardas << " " << kietas[i].pavarde << " ";
		/*for (size_t t = 0; t != stud[i].pazymiai.size(); ++t) {
		cout << stud[i].pazymiai[t] << " ";
		}*/
		rs << kietas[i].vidurkis << " " << kietas[i].galBalas;
		rs << endl;
	}
	rs << endl;
	kietas.clear();
}

void sunaikintiDeque() {
	stud.clear();
}

void skaiciuotiGalutiniBalaDeque(int pazymiuSkaicius, int iter) {
	auto start = std::chrono::high_resolution_clock::now(); //laiko matavimo start
	int studentuSkaicius = static_cast<int>(round(10 * pow(10, iter)));
	float vid{};

	for (size_t p = 0; p != studentuSkaicius; ++p) {
		for (size_t t = 0; t != pazymiuSkaicius - 1; ++t) {
			vid = vid + stud[p].pazymiai[t];
		}
		vid = vid / pazymiuSkaicius;
		stud[p].vidurkis = vid;
		stud[p].galBalas = static_cast<float>(vid*0.4 + stud[p].pazymiai[pazymiuSkaicius - 1] * 0.6);
	}
	auto finish = std::chrono::high_resolution_clock::now();//laiko matavimo finish
	std::chrono::duration<double> elapsed = finish - start;
	cout << left << setw(40) << "skaiciuotiGalutiniBala vykdymo laikas " << iter << ": " << elapsed.count() << " s" << endl;
}

void kietasArNeDeque(int pazymiuSkaicius, int iter, int i) {
	auto start = std::chrono::high_resolution_clock::now(); //laiko matavimo start
	int studentuSkaicius = static_cast<int>(round(10 * pow(10, iter)));
	for (size_t p = 0; p != studentuSkaicius; ++p) {
		if (stud[p].galBalas >= 5.0) kietas.push_back(stud[p]);
		else luzeris.push_back(stud[p]);
	}
	auto finish = std::chrono::high_resolution_clock::now();//laiko matavimo finish
	std::chrono::duration<double> elapsed = finish - start;
	cout << left << setw(40) << "kietasArNe vykdymo laikas " << iter << ": " << setw(10) << elapsed.count() << " s" << endl;
}

