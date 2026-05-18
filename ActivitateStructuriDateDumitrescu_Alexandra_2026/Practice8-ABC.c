//CERINTE - Arbore Binar de Cautare(ABC) cu struct Angajat
//==========================================================
#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct {
    int id;
    char* nume;
    float salariu;
} Angajat;

typedef struct Nod Nod;
struct Nod {
    Angajat info;
    Nod* st;
    Nod* dr;
};

//Fisierul angajati.txt are formatul :
//id, nume, salariu
//Exemplu : 3, Popescu Ion, 4500.00
//
//Cheie de sortare in arbore : campul id.

//------------------------------------------------------------
//CERINTE OBLIGATORII
//------------------------------------------------------------
//
//1.[Citire din fisier]
//Implementeaza functia :
//Angajat citireAngajatDinFisier(FILE * file);
//Citeste o linie din fisier si returneaza un Angajat.
//Atentie: nume este char* — aloci memorie cu malloc.
Angajat citire(FILE* f) {

    Angajat a;
    char buffer[100];
    char sep[3] = ",\n";

    fgets(buffer, 100, f);
    char* aux = strtok(buffer, sep);
    a.id = atoi(aux);

    aux = strtok(NULL, sep);
    a.id = (char*)malloc(strlen(aux) + 1);;
    strcpy(a.id, aux);

    aux = strtok(NULL, sep);
    a.salariu = atof(aux);

    return a;
}
//
//2.[Inserare]
//    Implementeaza functia :
//    void inserareInArbore(Nod * *radacina, Angajat a);
//    -Daca arborele e gol, creezi nodul radacina.
//        - Daca id < nod curent → inserezi in subarborele stang.
//        - Daca id > nod curent → inserezi in subarborele drept.
//        - Daca id == nod curent → actualizezi numele si salariul
//        (eliberezi vechiul nume, aloci memorie pentru cel nou).
//        Nodul nou are st = NULL si dr = NULL.
//
void inserare(Nod** radacina, Angajat a) {
    
    if (*radacina) {
        if ((*radacina)->info.id > a.id) {
            inserare(&(*radacina)->st, a);
        }
        else {
            inserare(&(*radacina)->dr, a);
        }

    }
    else {
        Nod* nou = (Nod*)malloc(sizeof(Nod));
        nou->info = a;
        nou->st = NULL;
        nou->dr = NULL;
        *radacina = nou;

    }
}
//        3.[Afisare inordine]
//        Implementeaza functia :
//    void afisareInordine(Nod * radacina);
//Parcurgere: st → nod → dr.
//Rezultat : angajatii afisati in ordine crescatoare dupa id.
//
//4.[Afisare preordine]
//Implementeaza functia :
//void afisarePreordine(Nod * radacina);
//Parcurgere: nod → st → dr.
//
//5.[Afisare postordine]
//Implementeaza functia :
//void afisarePostordine(Nod * radacina);
//Parcurgere: st → dr → nod.
//
//6.[Cautare dupa id]
//Implementeaza functia :
//Nod * cautaDupaId(Nod * radacina, int id);
//Returneaza pointerul la nodul gasit, sau NULL daca nu exista.
//(Nu deep copy — returnezi direct nodul din arbore.)
//
//7.[Dezalocare]
//    Implementeaza functia :
//    void dezalocare(Nod * *radacina);
//    -Dezaloci intai st, apoi dr(postordine).
//        - Eliberezi free(nod->info.nume) inainte de free(nod).
//        - La final setezi * radacina = NULL.
//
//        ------------------------------------------------------------
//        CERINTE BONUS
//        ------------------------------------------------------------
//
//        8.[Numar noduri]
//        int numarNoduri(Nod * radacina);
//    Returneaza numarul total de noduri din arbore.
//
//        9.[Inaltime arbore]
//        int inaltimeArbore(Nod * radacina);
//    Returneaza inaltimea arborelui(0 daca e NULL).
//
//        10.[Salariu total]
//        float salariuTotal(Nod * radacina);
//    Returneaza suma salariilor tuturor angajatilor din arbore.
//
//        11.[Angajat cu salariul maxim]
//        Nod * angajatMaxSalariu(Nod * radacina);
//    Returneaza pointerul la nodul cu salariul cel mai mare.
//
//        ------------------------------------------------------------
//        MAIN sugerat
//        ------------------------------------------------------------

        int main() {
        //Nod* arbore = NULL;

        // citire din fisier
        // afisare inordine
        // afisare preordine
        // afisare postordine
        // cautare dupa id (ex: id=5)
        // afisare rezultat cautare
        // bonus: numar noduri, inaltime, salariu total
        // dezalocare

        return 0;
    }