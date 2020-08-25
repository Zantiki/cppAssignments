# Svar teori:

## 1: a og b

![Output on run](1ab.png "Title")

## 2
Når man kjører koden

``
char *line = nullptr;   // eller char *line = 0;
strcpy(line, "Dette er en tekst");
``

Vil man få feil, da man prøver å assigne en null-addresse til en faktisk streng.
## 3
For koden i oppgave 3 vil man få såkalt stack-smashing da vi incrementer pekeren lengre enn
strengen den peker til og stack-overflowen som da oppstår blør inn i execution-stacken.

## 4
Se four() funksjon i Oving2.cpp
## 5
Se five() funksjon i Oving2.cpp
## 6
Se six() funksjon i Oving2.cpp