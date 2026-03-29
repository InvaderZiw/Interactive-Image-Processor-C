task-1:
Am interschimbat(cu ajutorul unui temp) primul element cu ultimul element de pe fiecare linie a matricei pana la jumatatea liniei
task-2:
Am alocat dinamic o matrice de dimensiune MxN si am facut astfel incat primul element de pe matrice sa ia valoarea ultimului element de pe prima linie, al doilea element sa ia valoarea ultimului element de pe a doua linie s.a.m.d.
task-3:
Am alocat dinamic o matrice de dimensiune hxw ,apoi am lipit subimaginea care are primul element al sau elemtul imaginii de coordonate (x,y) pe matricea alocata
task-4:
Am alocat o matrice de dim (N+(2rows))x(M+(2cols)) si i am dat fiecarui element din matrice culorile paramtrilor dati in functie iar apoi incepand cu elementul de coordonate (rows,cols) am setat matricea sa ia valorile imaginii originale
task-5:
Ok...M-am folosit de operatorul ternar pentru ca loop urile mele sa se opreasca in cazul in care imaginea sursa e mai mare decat suprafata comuna a imaginilor ,iar in loop am setat pixelii din imaginea destinatie sa ia valoare imaginii sursa.
task-6:
Ok...Am alocat cu calloc o matice de dimensiune (N+filter_size-1)x(M+fillter_size-1) astfel incat cand filtrez un pixel care e pe margine, veciinii sai sa fie 0 si sa pot filtra conform cerintei ,dupa care am atribuit valoare elementelor de pe pozitia (filter_size-1)/2 (filter_size-1)/2 valoarea imaginii pana la elementul de pe pozitia N+(filter_size-1)/2-1 ,respectiv M+(filter_size-1)/2-1.
TLDR: Am creat un fel de rama pentru imagine, elementele de pe rama avand valoare (0,0,0) ca sa pot filtra marginile
Apoi am atribuit fiecarui element de culoare al imaginii initiale suma submatricei de dimensiune filter_size x filter_size primul element avand acelasi indice cu primul element din matricea alocata ca sa iasa suma elementelor vecine primului element din imagine ,in acest caz, care se aplica si la restul pixelilor din imagine.
task-7:
M-am folosit de un while(1) pentru un loop infinit in care am citit comanda ,iar prin intermediul unui pointer p care a primit niste valori specifice acolo unde se putea, am codificat comenzile in cod ,iar apoi prin intermediul unui switch(*p) am realizat cazuri pentru fiecare comanda unde am citit in fiecare caz parametrii dati de comanda