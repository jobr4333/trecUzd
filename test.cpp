#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main() {
    int nDarbas[100], dSk, galIv, temp;
    string name, surname;
    cout << "vardas ir pavarde?" << endl;
    cin >> name >> surname;
    cout << "1. Kiek atliktu namu darbu? " << endl;
    cin >> dSk;
    cout << "Kokie gauti ivertinimai?" << endl;
    for(int i = 0; i < dSk; i++) {
        cout << i+1 << ". ";
        cin >> temp;
        if(temp > 0 && temp < 11) nDarbas[i] = temp;
        else cout << "Klaida. Desimtbales sistemos pazymi iveskite is naujo." << endl;
    }
    cout << "Galutinio egzamino ivertinimas?" << endl;
    cin >> galIv;

    float galBalas{}, vid{};
    for(int i = 0; i < dSk; i++){
        vid = vid + nDarbas[i];
    }
    vid = vid/dSk;
    galBalas = 0.4 * vid + 0.6 * galIv;
    cout << name << " " << surname << " galutinis balas: ";
    cout << set.precise(2) << galBalas << endl;

}
