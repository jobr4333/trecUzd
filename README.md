# Projektas (antra objektinio programavimo užduotis)

V0.3
Atlikite versijos (v0.2) kodo reorganizavimą (refactoring'ą):
Kur tikslinga, programoje naudokite (jeigu dar nenaudojote) struct'ūras
Funkcijas, naujus duomenų tipus (struct’ūras) perkelkite į antraštinius (angl. header (*.h)) failus, t.y. tokiu būdu turėtumete projekte turėti kelis *.cpp failus, kaip ir kelis *.h failus.
Kur tikslinga, panaudokite išimčių valdymą (angl. Exception Handling)

Funkcijos perkeltos į atskirą funkcijos.cpp failą, suskurtas header.h failas.
Panaudotas Exception Handling duomenų skaityme. Apsaugo nuo klaidų kurias sukelia:
- tuščias duomenų failas
- duomenų failo nebuvimas
- pažymių nebuvimas ar klaida kuriame nors iš jų

V0.4
Programos veikimo greičio (spartos) analizė:

Patobulinkite (jeigu reikia v0.1 realizaciją) ir sugeneruokite penkis atsitiktinius studentų failus, sudarytus iš: 10, 100, 1000, 10000, 100000 įrašų. Vardus ir Pavardes galite generuoti "šabloninius", kaip pvz. Vardas1 Pavarde1, Vardas2 Pavarde2 ir t.t.
Sūrušiuokite (padalinkite) studentus į dvi kategorijas:
Studentai, kurie surinko < 60% už namų darbų užduotis (“vargšiukai”, “nuskriaustukai” ir pan.)
Studentai, kurie surinko >= 60% už namų darbų užduotis ("kietiakiai", "galvočiai" ir pan.) ir buvo prileisti prie egzamino.
P.s. Logiškesnė užduoties formuluotė būtų studentus dalinti į dvi kategorijas pagal galutinį balą, o ne namų darbų įvertį. Jeigu jau realizavote pagal namų darbus - palikite kaip yra, tačiau jeigu dar nedarėte - tuomet rūšiuokite pagal galutinį balą. Tuomet, kieno galutinis balas < 5.0, galėtume laikyti "vargšiuku", o tuos kieno >= 5.0 - "kietiakais".

Išmatuokite (kuo tiksliau) visos programos (t.y. failų sukūrimą irgi reikia matuoti) veikimo laiką testuojant su šiais keturiais skirtingo dydžio duomenų failais.
