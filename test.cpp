#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <fstream>

using std::cout; using std::cin; using std::endl; using std::string; using std::vector; using std::sort;
using namespace std;

int randomPaz(int ndSk, vector<int> & nDarbas){
    for(int i = 0; i < ndSk; i++){
        nDarbas.push_back(rand()%9+2);
        cout << nDarbas[i] << ", ";
    }
    cout << endl;
}

void skaitymas(){
    ifstream sk("kursiokai.txt");

}
int main(){
    int ndSk{}, galIv{}, temp{}, suvestiNdPaz[100];
    float galBalas{};
    string vardas, pavarde;
    vector<int> nDarbas{};

    cout << "1.Jusu vardas ir pavarde?" << endl;
    cin >> vardas >> pavarde;

    /*______Atsitiktinai generuojami pazymiai (ivedamas pazymiu kiekis)_____________*/

    cout << "kiek pazymiu?" << endl;
    cin >> ndSk;
    randomPaz(ndSk, nDarbas);

    /*______Rankiniu budu ivedami ivertinimai________*/

    /*cout << "2. Kokie gauti ivertinimai? Spauskite 0, jei ivedete visus ivertinimus." << endl;
    while(true) {
        cout << "Pazymys nr " << ndSk+1 << ". ";
        cin >> temp;
        cout << endl;
        if(temp > 0 && temp < 11) suvestiNdPaz[ndSk] = temp, ndSk++;
        else if(temp == 0) break;
        else cout << "Klaida" << endl;
    }

    for(int i = 0; i < ndSk; i++) {
        nDarbas.push_back(suvestiNdPaz[i]);
    }

    cout << "ndSk: " << ndSk << endl << "nDarbas.size:  " << nDarbas.size() <<  endl;
    for(int i = 0; i < nDarbas.size(); i++){
        cout << nDarbas[i] << ", ";
    }*/

    sort(nDarbas.begin(), nDarbas.end());
    cout << endl << "surikiuotas " << endl;

    for(int i = 0; i < nDarbas.size(); i++){
        cout << nDarbas[i] << ", ";
    }
    cout << endl;

    cout << "3. Galutinio egzo ivertinimas?" << endl;
    cin >> galIv;

    cout << "4. Skaiciuoti vidurki ar mediana? " << endl << "vidurkis - spausti 1;" << endl << " mediana - spausti 2" << endl;
    cin >> temp;

    if(temp == 1) { //pasirinkimas skaiciuoti vidurki
        float vid{};
        for(int i = 0; i < ndSk; i++){
            vid = vid + nDarbas[i];
        }
        vid = vid/ndSk;
        galBalas = 0.4 * vid + 0.6 * galIv;
    }
    else if(temp == 2) { //pasirinkimas skaiciuot mediana
        float med{};
        float temp2{};

        cout << endl;
        if(ndSk % 2 == 1) {
            temp = (ndSk/2)+1; //temp yra vidurinio eiluteje elemento indeksas
            med = nDarbas[temp];
        }
        else {
            temp2 = 0;
            temp = ndSk/2;
            for(int i = 0; i < 2; i++) {
                temp2 = temp2 + nDarbas[temp-1];
                temp++;
            }
            temp2 = temp2/2;
            med = temp2;
        }
        cout << "mediana yra = " << med << endl;
        galBalas = 0.4 * med + 0.6 * galIv;
    }
    cout << vardas << " " << pavarde << " " << "galutinis balas: " << setprecision(3) << galBalas << endl;
}
