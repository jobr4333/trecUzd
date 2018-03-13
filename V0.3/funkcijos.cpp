int randomPaz(int ndSk, vector<int> & nDarbas){
    for(int i = 0; i < ndSk; i++){
        nDarbas.push_back(rand()%9+2);
        cout << nDarbas[i] << ", ";
    }
    cout << endl;
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
