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

PIRMA STRATEGIJA
Vektoriai
skaitymas vykdymo laikas                0: 0.00135778 s
skaiciuotiGalutiniBala vykdymo laikas   0: 4.3555e-05 s
kietasArNe vykdymo laikas               0: 0.000198667 s
______________________________
skaitymas vykdymo laikas                1: 0.0101649 s
skaiciuotiGalutiniBala vykdymo laikas   1: 0.000294667 s
kietasArNe vykdymo laikas               1: 0.00242178 s
______________________________
skaitymas vykdymo laikas                2: 0.0830289 s
skaiciuotiGalutiniBala vykdymo laikas   2: 0.00302711 s
kietasArNe vykdymo laikas               2: 0.027556   s
______________________________
skaitymas vykdymo laikas                3: 0.882705 s
skaiciuotiGalutiniBala vykdymo laikas   3: 0.030092 s
kietasArNe vykdymo laikas               3: 0.214246   s
______________________________
skaitymas vykdymo laikas                4: 9.26558 s
skaiciuotiGalutiniBala vykdymo laikas   4: 0.299634 s
kietasArNe vykdymo laikas               4: 2.25346    s
______________________________
Listai
10
SkaitytiList vykdymo laikas                       0: 0.000968001 s
skaiciuotiGalutiniBalaList vykdymo laikas         0: 6.7111e-05 s
kietasArNeList vykdymo laikas                     0: 0.000152445 s
spausdintiList vykdymo laikas                     0: 0.00158445 s
______________________________
100
SkaitytiList vykdymo laikas                       1: 0.00596134 s
skaiciuotiGalutiniBalaList vykdymo laikas         1: 0.000572001 s
kietasArNeList vykdymo laikas                     1: 0.00138933 s
spausdintiList vykdymo laikas                     1: 0.00742223 s
______________________________
1000
SkaitytiList vykdymo laikas                       2: 0.0578516 s
skaiciuotiGalutiniBalaList vykdymo laikas         2: 0.005272 s
kietasArNeList vykdymo laikas                     2: 0.0138391 s
spausdintiList vykdymo laikas                     2: 0.0652898 s
______________________________
10000
SkaitytiList vykdymo laikas                       3: 0.591956 s
skaiciuotiGalutiniBalaList vykdymo laikas         3: 0.0520285 s
kietasArNeList vykdymo laikas                     3: 0.132981 s
spausdintiList vykdymo laikas                     3: 0.594509 s
______________________________
100000
SkaitytiList vykdymo laikas                       4: 5.63554 s
skaiciuotiGalutiniBalaList vykdymo laikas         4: 0.48489 s
kietasArNeList vykdymo laikas                     4: 1.30785 s
spausdintiList vykdymo laikas                     4: 5.67966 s
______________________________
Dekai
skaitymas vykdymo laikas                0: 0.00100178 s
skaiciuotiGalutiniBala vykdymo laikas   0: 0.000108445 s
kietasArNe vykdymo laikas               0: 0.000144   s
______________________________
skaitymas vykdymo laikas                1: 0.00855956 s
skaiciuotiGalutiniBala vykdymo laikas   1: 0.00127333 s
kietasArNe vykdymo laikas               1: 0.000871111 s
______________________________
skaitymas vykdymo laikas                2: 0.0840396 s
skaiciuotiGalutiniBala vykdymo laikas   2: 0.0115933 s
kietasArNe vykdymo laikas               2: 0.00923289 s
______________________________
skaitymas vykdymo laikas                3: 0.865069 s
skaiciuotiGalutiniBala vykdymo laikas   3: 0.110949 s
kietasArNe vykdymo laikas               3: 0.0814903  s
______________________________
skaitymas vykdymo laikas                4: 8.49628 s
skaiciuotiGalutiniBala vykdymo laikas   4: 1.05264 s
kietasArNe vykdymo laikas               4: 0.849308   s
______________________________
ANTRA STRATEGIJA
vektoriai
skaitymas vykdymo laikas                0: 0.001104 s
skaiciuotiGalutiniBala vykdymo laikas   0: 4.8445e-05 s
kietasArNe vykdymo laikas               0: 8.3111e-05 s
______________________________
skaitymas vykdymo laikas                1: 0.00803867 s
skaiciuotiGalutiniBala vykdymo laikas   1: 0.000350222 s
kietasArNe vykdymo laikas               1: 0.000659112 s
______________________________
skaitymas vykdymo laikas                2: 0.0740667 s
skaiciuotiGalutiniBala vykdymo laikas   2: 0.00309556 s
kietasArNe vykdymo laikas               2: 0.00607111 s
______________________________
skaitymas vykdymo laikas                3: 0.749578 s
skaiciuotiGalutiniBala vykdymo laikas   3: 0.0293298 s
kietasArNe vykdymo laikas               3: 0.0569182  s
______________________________
skaitymas vykdymo laikas                4: 7.27494 s
skaiciuotiGalutiniBala vykdymo laikas   4: 0.283608 s
kietasArNe vykdymo laikas               4: 1.54713    s
______________________________
Listai
10
SkaitytiList vykdymo laikas                       0: 0.00127111 s
skaiciuotiGalutiniBalaList vykdymo laikas         0: 9.2889e-05 s
kietasArNeList vykdymo laikas                     0: 0.000107111 s
spausdintiList vykdymo laikas                     0: 0.00144222 s
______________________________
100
SkaitytiList vykdymo laikas                       1: 0.00612978 s
skaiciuotiGalutiniBalaList vykdymo laikas         1: 0.000586667 s
kietasArNeList vykdymo laikas                     1: 0.000704445 s
spausdintiList vykdymo laikas                     1: 0.00577378 s
______________________________
1000
SkaitytiList vykdymo laikas                       2: 0.0585987 s
skaiciuotiGalutiniBalaList vykdymo laikas         2: 0.005524 s
kietasArNeList vykdymo laikas                     2: 0.00776445 s
spausdintiList vykdymo laikas                     2: 0.0379374 s
______________________________
10000
SkaitytiList vykdymo laikas                       3: 0.580149 s
skaiciuotiGalutiniBalaList vykdymo laikas         3: 0.0529631 s
kietasArNeList vykdymo laikas                     3: 0.0767685 s
spausdintiList vykdymo laikas                     3: 0.348989 s
______________________________
100000
SkaitytiList vykdymo laikas                       4: 5.84163 s
skaiciuotiGalutiniBalaList vykdymo laikas         4: 0.519607 s
kietasArNeList vykdymo laikas                     4: 0.731618 s
spausdintiList vykdymo laikas                     4: 3.40563 s
______________________________
Dekai
skaitymas vykdymo laikas                0: 0.001116 s
skaiciuotiGalutiniBala vykdymo laikas   0: 0.000127111 s
kietasArNe vykdymo laikas               0: 0.000113778 s
______________________________
skaitymas vykdymo laikas                1: 0.00893334 s
skaiciuotiGalutiniBala vykdymo laikas   1: 0.00128667 s
kietasArNe vykdymo laikas               1: 0.001004   s
______________________________
skaitymas vykdymo laikas                2: 0.0848014 s
skaiciuotiGalutiniBala vykdymo laikas   2: 0.0114031 s
kietasArNe vykdymo laikas               2: 0.00861956 s
______________________________
skaitymas vykdymo laikas                3: 0.867831 s
skaiciuotiGalutiniBala vykdymo laikas   3: 0.110864 s
kietasArNe vykdymo laikas               3: 0.0851871  s
______________________________
skaitymas vykdymo laikas                4: 8.37994 s
skaiciuotiGalutiniBala vykdymo laikas   4: 1.07662 s
kietasArNe vykdymo laikas               4: 0.897999   s
