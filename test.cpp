#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>

using std::cout; using std::cin; using std::endl; using std::string; using std::vector; using std::sort; using std::ifstream; using std::setprecision; using std::setw;  using std::left;
struct studentas {
    string vardas;
    string pavarde;
    vector <int> pazymiai;
    float vidurkis{}, mediana{}, galBalas{};
};
vector<studentas> stud;

int randomPaz(int ndSk, vector<int> & nDarbas){
    for(int i = 0; i < ndSk; i++){
        nDarbas.push_back(rand()%9+2);
        cout << nDarbas[i] << ", ";
    }
    cout << endl;
}

void skaitymas(){
    ifstream sk("kursiokai.txt");
    string tempS;
    int num{}, t{};
    sk.ignore(80, '\n');
    //cout << tempS << endl;
    while(getline(sk, tempS)) {
        stud.push_back(studentas());
        std::istringstream iss(tempS);
        iss >> stud[t].pavarde;
        iss >> stud[t].vardas;
        while(iss >> num) {
            stud[t].pazymiai.push_back(num);
        }
        //cout << "2: " << stud[1].vardas << endl;
        /*cout << stud[t].vardas << " " << stud[t].pavarde << " ";
        for(size_t o = 0; o < stud[t].pazymiai.size(); o++) cout << " " << stud[t].pazymiai[o];
        cout << endl;*/
        t++;;
    }

    sort(stud.begin( ), stud.end( ), [ ]( const studentas& p, const studentas& b ){
    return p.pavarde < b.pavarde;
    });


    sk.close();
}

int vidurkis(){
    int ndSk = stud[0].pazymiai.size()-1; //ndSk = ND skaicius. Po skaitymo nd pazymiai yra sujungti kartu su egzamino pazymiu kuris yra paskutinis narys eileje, todel ji atmetam
    float vid{};
    for(size_t i = 0; i < stud.size(); i++){
        for(size_t u = 0; u < ndSk; u++){
            vid = vid + stud[i].pazymiai[u];
        }
        vid = vid/ndSk;
        stud[i].vidurkis = 0.4 * vid + 0.6 * stud[i].pazymiai[ndSk];
        vid = 0;
    }
}

int mediana() {
    int ndSk = stud[0].pazymiai.size()-1;
    int temp{};
    float temp2{}; //ndSk = ND skaicius. Po skaitymo nd pazymiai yra sujungti kartu su egzamino pazymiu kuris yra paskutinis narys eileje, todel ji atmetam

    for(size_t i = 0; i < stud.size(); i++) {
        if(stud[i].pazymiai.size() % 2 == 1) {
            temp = (ndSk/2)+1; //temp yra vidurinio eiluteje elemento indeksas
            stud[i].mediana = stud[i].pazymiai[temp];
        }

        else {
            temp = (ndSk)/2; // temp = vidurinio nario indeksas
            for(size_t u = 0; u < 2; u++) {
                temp2 = temp2 + stud[i].pazymiai[temp]; //sudeda du vidurinius narius is kuriu skaiciuos mediana
                temp++;
            }
            temp2 = temp2/2; //skaiciuoja mediana (dvieju nariu vidurkis)
            stud[i].mediana = 0.4 * temp2 + 0.6 * stud[i].pazymiai[ndSk];
        }
         //ndSk nes namu darbu eileje egzamino ivertinimas yra paskutinis
         temp = 0;
         temp2 = 0;
    }
}
int main(){
    int ndSk{}, galIv{}, suvestiNdPaz[100], temp{};
    float galBalas{};
    string vardas, pavarde;
    vector<int> nDarbas{};
    skaitymas();
    mediana();
    vidurkis();


    cout << setw(15) << left <<  "Vardas" << setw(15) << "pavarde" << setw(10) <<  "vidurkis" << setw(10) << "mediana" << endl << endl;
    for(size_t i = 0; i < stud.size(); i++){
        cout << setw(15) <<  stud[i].vardas << setw(15) << stud[i].pavarde << setw(10) << setprecision(3) <<  stud[i].vidurkis << setw(10) << setprecision(3) << stud[i].mediana << endl;
        //for(size_t o = 0; o < stud[i].pazymiai.size(); o++) cout << "  " << stud[i].pazymiai[o];
    }

    //galBalas = 0.4 * med + 0.6 * galIv;
}
