#pragma once
#include <iostream>
#include <list>
#include <fstream>
#include <list>
#include <chrono>

using std::list;
using std::string;
using std::to_string;
using std::ofstream;
using std::list;

int randomPazymys();
void skaitymasList(int iter, list<studentas> &studList);
//bool rikiuotiPagalPavardeList(const studentas &a, const studentas &b);
void spausdintiList(int iter, list<studentas> &studList);
void irasytiFailan(int pazymiuSkaicius, int iter);
void skaiciuotiGalutiniBalaList(int pazymiuSkaicius, int iter, list<studentas>&studList);
void kietasArNeList(int pazymiuSkaicius, int iter, int i, list<studentas> &studList, list<studentas> &kietasList, list<studentas> &luzerisList);
void sunaikintiList(list<studentas> &studList);

