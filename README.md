# Projektas

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
