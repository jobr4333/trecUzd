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

| Funkcija | n = 10 | n = 100 | n = 1000 | n = 10000 | n = 100000 | 
| ----------------| ------------ | -------- | ------- | ------- | ------- |
| Generavimas |  0.0158533 s| 0.0216818 s| 0.151053 s | 1.37125 s | 13.4309 s |
| Skaitymas |  0.005476 s| 0.0148867 s | 0.096084 s | 0.930283 s |  9.37558 s |
| Galutinio balo skaiciavimas | 3.3777e-05 s |  0.000336889 s| 0.003184 s| 0.029408 s | 0.306129 s |
| Skirstymas | 0.000237333 s| .00239067 s | 0.0208689 s|  0.23731 s | 2.67215 s |

0.5 VERSIJA kartu su 1.0

|Konteineris |I Strategija | II strategija| 
| ----------------| ------------ |  ------------ |
| Vektoriai |  ![alt text](https://i.imgur.com/1MsvFdf.png) | ![alt text](https://i.imgur.com/SMFWVna.png) |
| Listai |  ![alt text](https://i.imgur.com/1JizkZE.png) | ![alt text](https://i.imgur.com/7sY86QQ.png)
| Dekai | ![alt text](https://i.imgur.com/83ZQOUy.png) | ![alt text](https://i.imgur.com/PVikyKP.png) |
