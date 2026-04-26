//Cerințe:
//
//Citește produsele dintr - un fișier și construiește un ABC după nume(cheie)
//Afișează toate produsele în cele 3 moduri de parcurgere
//Caută un produs după nume și afișează - l
//Calculează prețul total al tuturor produselor din stoc(stoc * pret pentru fiecare)
//Calculează prețul total al produselor unui brand dat(ex: toate produsele Apple)
//Determină numărul total de noduri din arbore
//Calculează înălțimea arborelui
//Găsește produsul cel mai scump din arbore
//Găsește produsul cu cel mai mare stoc
//Dezalocă corect tot arborele

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>


struct Produs {
    char* nume;
    char* brand;
    int stoc;
    float pret;
};
typedef struct Produs Produs;

struct Nod {
    struct Nod* stg;
    struct Nod* drp;
    Produs info;
};

//Citește produsele dintr - un fișier și construiește un ABC după nume(cheie)

Produs citire(FILE* f) {


    char buffer[100];
    char sep[5] = ", \n";

    fgets(buffer, 100, f);

    Produs p;
    char* aux = strtok(buffer, sep);
    p.nume = (char*)malloc(strlen(aux) + 1);
    strcpy(p.nume, aux);

    aux = strtok(NULL, sep);
    p.brand = (char*)malloc(strlen(aux) + 1);
    strcpy(p.brand, aux);

    aux = strtok(NULL, sep);
    p.stoc = atoi(aux);

    aux = strtok(NULL, sep);
    p.pret = atof(aux);

    return p;
}



void main() {

}