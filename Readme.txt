Filimon Dan-George
312 CA

Tema 4

0. Organizare
Algoritmul in sine este in "logic.c". "main.c" este sursa care contine main-ul si care include "logic.h", interfata catre functia de rezolvare.
Exista foarte multe fisiere fiindca tema a fost proiectata asa incat diversele sale componente sa poata fi inlocuite cu alte implementari.
Spre exemplu, algoritmul pe care l-am ales pentru 8-puzzle poate fi schimbat pentru un altul, euristica folosita (Manhattan) poate fi schimbata pentru alta (numarul de numere pe pozitie gresita/corecta de exemplu).
In plus si structurile abstracte de date - coada prioritara si arbore de cautare echilibrat pot fi implementat altfel, de aceea priorityqueue.h si binarysearchtree.h definesc niste functii care trebuie implementate, eventual folosind alte structuri la baza.
Spre exemplu, am folosit skip list-uri pentru implementarea cozii de prioritati. La fel de bine s-ar fi putut fi folosit heap-uri iar in loc de arbori rosu negru inclinati la stanga as fi putut la fel de bine folosi AVL-uri. Speram sa incerc cu diverse alte structuri de date dar pana la urma n-am mai avut timp de teste.

1. Algoritm
Pentru expandarea unui nod din arborele multicai (definit in multiwaytree.{h,c}), aleg fii sai cei mai promitatori din punct de vedere al distantei aproximative pana la solutie, determinata folosind euristica Manhattan.
Apoi, adun la estimarea euristica distanta de la radacina la acest nod si obtin "prioritatea" pe baza careia nodul va fi inserat in coada prioritara. Voi extrage la fiecare pas nodul cu "prioritate" minima, deci cel pentru care suma de mai sus este minima, combinand tehnica de Hill-climbing (expandare in adancime bazata doar pe euristica) cu o cautare in latime (introducand nodurile intr-o coada). Rezultatul este algoritmul A*, care pentru o functie de euristica admisibila este garantat sa obtina o solutie cu un numar minim de pasi [1].
Euristica Manhattan este admisibila (optimista) deoarece la fiecare stare valoarea intoarsa reprezinta o margine inferioara pentru numarul de mutari necesare. Acest lucru se poate demonstra daca avem in vedere ca suma distantelor Manhattan reprezinta numarul de mutari necesare pentru fiecare piesa luata independent (fara niciun alt obstacol), intuitiv clar o margine inferioara.

3. Bibliografie

[1] http://en.wikipedia.org/wiki/A*_search_algorithm
a. 8-puzzle + A*
http://www.redfish.com/dkunkle/mypapers/EightPuzzle.pdf
http://theory.stanford.edu/~amitp/GameProgramming/AStarComparison.html
http://sequoia.ict.pwr.wroc.pl/~witold/aiuwr/rpi_heuristic_search4.ps
http://www.zib.de/reinefeld/bib/93ijcai.pdf

b. Arbori rosu-negru inclinati la stanga
http://www.cs.princeton.edu/~rs/talks/LLRB/LLRB.pdf
http://www.cs.princeton.edu/~rs/talks/LLRB/RedBlack.pdf

c. Idee foarte buna cu link[dir]
http://www.eternallyconfuzzled.com/tuts/datastructures/jsw_tut_rbtree.aspx
