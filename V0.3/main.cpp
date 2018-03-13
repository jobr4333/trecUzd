#include "head.h"
#include "skaitymas.cpp"
#include "funkcijos.cpp"

int main(){
    int ndSk{}, galIv{}, suvestiNdPaz[100], temp{};
    float galBalas{};
    bool arSkaitymasPavyko{};
    string vardas, pavarde;
    vector<int> nDarbas{};
    skaitymas(arSkaitymasPavyko);
    mediana();
    vidurkis();
    cout << setw(15) << left <<  "Vardas" << setw(15) << "pavarde" << setw(10) <<  "vidurkis" << setw(10) << "mediana" << endl << endl;
    for(size_t i = 0; i < stud.size(); i++){
        cout << setw(15) <<  stud[i].vardas << setw(15) << stud[i].pavarde << setw(10) << setprecision(3) <<  stud[i].vidurkis << setw(10) << setprecision(3) << stud[i].mediana << endl;
    }
}
