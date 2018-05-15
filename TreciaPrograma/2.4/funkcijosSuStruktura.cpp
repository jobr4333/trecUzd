//
// Created by Base on 2018-03-20.
//
#include "stdafx.h"
#include "studentas.h"
#include "funkcijosSuStruktura.h"
#include "funkcijosBeStrukturos.h"

vector<studentas> stud;
vector<studentas> kietas;
vector<studentas> luzeris;

void studentas::skaitymas(int iter) {
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
		vector<string> tempStud;
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
				exit(1);
			}
			t++;
		}
		sk.close();
		for (t = 0; t != 10 * pow(10, iter); t++) {
			try {
				if (stud[t].pazymiai.size() < 6) { //labai palankiai veikia, nezinau kodel
					throw 2;
				}
			}
			catch (int errNo) {
				cout << "Ivyko klaida. Nepakankamai pazymiu faile NR: " << iter+1 << ". eilutes NR: " << t+1 << endl << "Klaidos NR: " << errNo << endl;
				exit(2);
			}
		}
	}

	

	auto finish = std::chrono::high_resolution_clock::now();//laiko matavimo finish
	std::chrono::duration<double> elapsed = finish - start;
	cout << left << setw(40) << "skaitymas vykdymo laikas " << iter << ": " << elapsed.count() << " s" << endl;
}

bool studentas::rikiuotiPagalPavarde(studentas& a, studentas& b)
{
	return a.Pavarde() < b.Pavarde();
}

void studentas::rikioti() {
	/*sort(stud.begin(), stud.end(), rikiuotiPagalPavarde);*/
}

void studentas::spausdinti(int iter) {
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

void studentas::sunaikinti() {
	stud.clear();
}

void studentas::irasytiFailan(int pazymiuSkaicius, int iter) {
	auto start = std::chrono::high_resolution_clock::now(); //laiko matavimo start
	int studentuSkaicius = static_cast<int>(round(10 * pow(10, iter)));  //kitame faile bus 10x daugiau studentu

	ofstream rs("txt/sudentai" + to_string(iter) + ".txt"); //generuojamas failo pavadinimas

	for (size_t p = 0; p != studentuSkaicius; ++p) { // stud.size() = studentu skaicius faile = (1 * 10^i)
		auto temp = to_string(p);
		rs << "Vardas" + temp + " " << "Pavarde" + temp + " "; //generuojami vardai ir pavardes

		for (size_t t = 0; t != pazymiuSkaicius; ++t) { //irasomi pazymiai
			rs << randomPazymys() << " ";
		}
		rs << endl;
	}
	rs.close();
	auto finish = std::chrono::high_resolution_clock::now();//laiko matavimo finish
	std::chrono::duration<double> elapsed = finish - start;
	cout << left << setw(40) << "irasytiFailan vykdymo laikas " << iter << ": " << elapsed.count() << " s" << endl;
}

void studentas::skaiciuotiGalutiniBala(int pazymiuSkaicius, int iter) {
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

void studentas::kietasArNe(int pazymiuSkaicius, int iter, int i) {
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

