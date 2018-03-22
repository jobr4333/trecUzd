# Projektas (antra objektinio programavimo užduotis)

**V0.3
Versijos (v0.2) kodo reorganizavimas refactoringas:**
Kur tikslinga, programoje naudokite (jeigu dar nenaudojote) struct'ūras
Funkcijas, naujus duomenų tipus (struct’ūras) perkelkite į antraštinius (angl. header (*.h)) failus, t.y. tokiu būdu turėtumete projekte turėti kelis *.cpp failus, kaip ir kelis *.h failus.
Kur tikslinga, panaudokite išimčių valdymą (angl. Exception Handling)

Funkcijos perkeltos į atskirą funkcijos.cpp failą, suskurtas header.h failas.
Panaudotas Exception Handling duomenų skaityme. Apsaugo nuo klaidų kurias sukelia:
- tuščias duomenų failas
- duomenų failo nebuvimas
- pažymių nebuvimas ar klaida kuriame nors iš jų

**V0.4
Programos veikimo greičio (spartos) analizė**

Sugeneruokite penkis atsitiktinius studentų failus, sudarytus iš: 10, 100, 1000, 10000, 100000 įrašų.

Pagal galutinį balą surūšiuokite (padalinkite) studentus į dvi kategorijas:
Į studentus, kurių galutinis balas >= 5.0
Į studentus, kurių galutinis balas < 5.0

Išmatuokite (kuo tiksliau) visos programos (t.y. failų sukūrimą irgi reikia matuoti) veikimo laiką testuojant su šiais keturiais skirtingo dydžio duomenų failais.

Failo 0 generavimo laikas: 0.0158533 s
Failo 0 skaitymo laikas: 0.005476 s
Failo 0 Galutinio balo skaiciavimo laikas: 3.3777e-05 s
Failo 0 skirstymo laikas: 0.000237333 s
___________________________________
Failo 1 generavimo laikas: 0.0216818 s
Failo 1 skaitymo laikas: 0.0148867 s
Failo 1 Galutinio balo skaiciavimo laikas: 0.000336889 s
Failo 1 skirstymo laikas: 0.00239067 s
___________________________________
Failo 2 generavimo laikas: 0.151053 s
Failo 2 skaitymo laikas: 0.096084 s
Failo 2 Galutinio balo skaiciavimo laikas: 0.003184 s
Failo 2 skirstymo laikas: 0.0208689 s
___________________________________
Failo 3 generavimo laikas: 1.37125 s
Failo 3 skaitymo laikas: 0.930283 s
Failo 3 Galutinio balo skaiciavimo laikas: 0.029408 s
Failo 3 skirstymo laikas: 0.23731 s
___________________________________
Failo 4 generavimo laikas: 13.4309 s
Failo 4 skaitymo laikas: 9.37558 s
Failo 4 Galutinio balo skaiciavimo laikas: 0.306129 s
Failo 4 skirstymo laikas: 2.67215 s
