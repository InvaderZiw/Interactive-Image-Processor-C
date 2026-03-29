Descriere generală

În această temă am implementat un procesor de imagini în limbajul C, lucrând direct cu matrice de pixeli RGB și alocare dinamică de memorie. Programul permite aplicarea unor operații de bază pe imagini (flip, rotate, crop, extend, paste) și aplicarea de filtre folosind convoluții, precum și un mod interactiv de lucru prin comenzi.

Am lucrat la nivel low-level, manipulând manual memoria și valorile pixelilor, fără a folosi biblioteci externe pentru procesarea imaginilor.

Task 1 - Flip Horizontal

Pentru acest task am realizat oglindirea pe orizontală a imaginii.

Am parcurs fiecare linie a matricei și am interschimbat:

primul element cu ultimul,
al doilea cu penultimul,
și așa mai departe până la jumătatea liniei, folosind o variabilă temporară (temp).
Task 2 - Rotate Left

Pentru rotația la stânga cu 90 de grade:

am alocat dinamic o matrice de dimensiune M x N;
am mapat elementele astfel încât:
primul element din matricea nouă să fie ultimul element de pe prima linie din matricea inițială,
al doilea element să fie ultimul element de pe a doua linie etc.

Astfel am realizat rotația completă a imaginii.

Task 3 - Crop

Pentru operația de crop:

am alocat dinamic o matrice de dimensiune h x w;
am copiat submatricea din imaginea originală care începe la coordonatele (x, y).

Practic, am extras o subimagine din imaginea inițială.

Task 4 - Extend

Pentru extinderea imaginii:

am alocat o matrice de dimensiune (N + 2 * rows) x (M + 2 * cols);
am inițializat toți pixelii noi cu culoarea (new_R, new_G, new_B);
apoi am copiat imaginea originală în noua matrice, începând de la poziția (rows, cols).

Rezultatul este o imagine „încadrată” de un chenar de culoare constantă.

Task 5 - Copy Paste

Pentru operația de paste:

am copiat pixelii din imaginea sursă în imaginea destinație, începând de la coordonatele (x, y);
am avut grijă ca operația să nu depășească limitele imaginii destinație;
pentru acest lucru am folosit condiții în bucle (inclusiv operatorul ternar) astfel încât copierea să se oprească atunci când se ajunge la margini.

Imaginea sursă nu este modificată.

Task 6 - Apply Filter

Pentru aplicarea filtrului:

am alocat o matrice mai mare cu calloc, de dimensiune
(N + filter_size - 1) x (M + filter_size - 1);
aceasta funcționează ca o „ramă” în jurul imaginii, unde pixelii din afara imaginii au valoarea (0, 0, 0);

Astfel:

am putut aplica filtrul și pe margini fără cazuri speciale;
pentru fiecare pixel am calculat suma ponderată a vecinilor pe baza filtrului (convoluție);
rezultatul a fost limitat în intervalul [0, 255].

Pe scurt: am creat padding cu zero și am aplicat filtrul ca o submatrice glisantă peste imagine.

Task 7 - Interactive Image Processor

Pentru acest task am implementat un sistem interactiv de procesare a imaginilor:

am folosit un while(1) pentru a citi comenzi continuu;
am interpretat comenzile folosind un pointer și un switch;
pentru fiecare comandă:
am citit parametrii necesari;
am aplicat operația corespunzătoare asupra imaginii;

Am implementat suport pentru:

load / save imagini BMP
aplicare operații (flip, rotate, crop, extend, paste)
creare și aplicare filtre
ștergere imagini și filtre

De asemenea:

am gestionat indexarea imaginilor și filtrelor;
am avut grijă la alocarea și dezalocarea corectă a memoriei (fără memory leaks).
Observații de implementare
Am folosit alocare dinamică pentru toate imaginile și filtrele.
Am lucrat direct cu matrice tridimensionale (NxMx3) pentru pixeli RGB.
Am acordat atenție gestionării memoriei și dezalocării corecte.
Pentru filtrare am folosit o abordare cu padding pentru a trata corect marginile.
