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
