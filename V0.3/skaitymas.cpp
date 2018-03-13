bool skaitymas(bool & arSkaitymasPavyko){
    ifstream sk("kursiokai.txt");
    string tempS, temp;
    int num{}, t{};
    try {
        if(!sk.good()) throw 404;
        else if(sk.peek() == ifstream::traits_type::eof()) throw 0;

    }
    catch(int errNo) {
        cout << "Ivyko klaida. Klaidos NR: " << errNo << endl;
        cout << "Paaiskinimas:" << endl << "404 - failo nera." << endl << "0 - failas tuscias." << endl << "1 - failas tuscias, tik tarpai." << endl;
        exit(errNo);
    }

    if(sk.good()) {
        string temp;
        arSkaitymasPavyko = true;
        sk.ignore(80, '\n');
        while(getline(sk, tempS) && arSkaitymasPavyko == true) {
            stud.push_back(studentas());
            std::istringstream iss(tempS);
            iss >> stud[t].pavarde;
            iss >> stud[t].vardas;

            while(iss >> num) {
                stud[t].pazymiai.push_back(num);
            }
            try {
                if(stud[t].pazymiai.size() == 0) { //labai palankiai veikia, nezinau kodel
                    throw 1;
                }
            }
            catch (int errNo){
                cout << "Ivyko klaida. Neteisingai ivesti pazymiai arba ju nera. Klaidos NR: " << errNo << endl;
                exit(2);
            }
            t++;
        }

        sort(stud.begin( ), stud.end( ), [ ]( const studentas& p, const studentas& b ){
            return p.pavarde < b.pavarde;
        });
        sk.close();

    }
}
