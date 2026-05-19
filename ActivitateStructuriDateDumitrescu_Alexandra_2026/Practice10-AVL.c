#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// ============================================================
// REUTILIZATE DIN ABC - implementeaza-le la fel ca inainte
// ============================================================

Angajat citire(FILE* f) {
    // citeste o linie din fisier
    // parsezi cu strtok: id, nume (malloc+strcpy), salariu
    char buffer[100];
    char sep[4] = ",\n";
    
    fgets(buffer, 100, f);

    char* aux = strtok(buffer, sep);
    Angajat a;
    a.id = atoi(aux);

    aux = strtok(NULL, sep);
    a.nume = (char*)malloc(strlen(aux) + 1);
    strcpy(a.nume, aux);

    aux = strtok(NULL, sep);
    a.salariu = atof(aux);

    return a;
}

void afisare(Angajat a) {
    // printf cu id, nume, salariu
    printf("id: %d   nume:%s  salariu: %5.2f\n", a.id, a.nume, a.salariu);
}

void afisareInordine(Nod* radacina) {
    // st -> nod -> dr
    if (radacina) {
        afisareInordine(radacina->st);
        afisare(radacina->info);
        afisareInordine(radacina->dr);
    }
   
}

void afisarePreordine(Nod* radacina) {
    // nod -> st -> dr
    if (radacina) {
        afisare(radacina->info);
        afisarePreordine(radacina->st);

        afisarePreordine(radacina->dr);
    }
    
}

void afisarePostordine(Nod* radacina) {
    // st -> dr -> nod
    if (radacina) {
        afisarePostordine(radacina->st);

        afisarePostordine(radacina->dr);
        afisare(radacina->info);
    }
    

}



// ============================================================
// NOU - specific AVL
// ============================================================

int inaltime(Nod* radacina) {
    // daca radacina == NULL returneaza 0
    // altfel returneaza 1 + max(inaltime(st), inaltime(dr))
    if (radacina) {
        
            int st = inaltime(radacina->st);
            int dr = inaltime(radacina->dr);
            return st > dr ? st + 1 : dr + 1;
    }
    return 0;
}

int gradEchilibru(Nod* radacina) {
    // returneaza inaltime(st) - inaltime(dr)
    // daca radacina == NULL returneaza 0
    if (radacina) {
        return inaltime(radacina->st) - inaltime(radacina->dr);
    }
    return 0;
}

void rotireDreapta(Nod** radacina) {
    // aux = (*radacina)->st
    // (*radacina)->st = aux->dr
    // aux->dr = *radacina
    // *radacina = aux
    Nod* aux = (Nod*)malloc(sizeof(Nod));
    aux = (*radacina)->st;
    (*radacina)->st = aux->dr;
    aux->dr = *radacina;
    *radacina = aux;
}

void rotireStanga(Nod** radacina) {
    Nod* aux = (Nod*)malloc(sizeof(Nod));
    aux = (*radacina)->dr;
    (*radacina)->dr = aux->st;
    aux->st = (*radacina);
    *radacina = aux;
}

void inserareAVL(Nod** radacina, Angajat a) {
    if (*radacina == NULL) {
        // aloci nod nou cu malloc(sizeof(Nod))
        // setezi info = a, st = NULL, dr = NULL
        // *radacina = nod nou
        Nod* nou = (Nod*)malloc(sizeof(Nod));
        nou->info = a;
        nou->st = NULL;
        nou->dr = NULL;
        *radacina = nou;
    }
    else {
        if (a.id < (*radacina)->info.id) {
            // recursie pe subarborele stang
            inserareAVL(&(*radacina)->st, a);
        }
        else if (a.id > (*radacina)->info.id) {
            // recursie pe subarborele drept
            inserareAVL(&(*radacina)->dr, a);
        }
        // daca a.id == id existent: ignori (sau actualizezi)

        int grad = gradEchilibru(*radacina);

        if (grad == 2) {
            if (gradEchilibru((*radacina)->st) >= 0) {
                // caz LL: rotireDreapta(radacina)
                rotireDreapta(radacina);
            }
            else {
                // caz LR: rotireStanga(&(*radacina)->st), apoi rotireDreapta(radacina)
                rotireStanga(&(*radacina)->st);
                rotireDreapta(radacina);
            }
        }
        else if (grad == -2) {
            if (gradEchilibru((*radacina)->dr) <= 0) {
                // caz RR: rotireStanga(radacina)
                rotireStanga(radacina);
            }
            else {
                // caz RL: rotireDreapta(&(*radacina)->dr), apoi rotireStanga(radacina)
                rotireDreapta(&(*radacina)->dr);
                rotireStanga(radacina);
            }
        }
    }
}

Nod* citireDinFisier(const char* numeFisier) {
    // deschizi fisierul
    // Nod* radacina = NULL
    // while (!feof(f)) inserareAVL(&radacina, citire(f))
    // inchizi fisierul
    // returnezi radacina
    Nod* radacina = NULL;
    FILE* f = fopen(numeFisier, "r");
    while (!feof(f)) {
        inserareAVL(&radacina, citire(f));
    }
    fclose(f);
    return radacina;
}

void dezalocare(Nod** radacina) {
    if (*radacina) {
        dezalocare(&(*radacina)->st);
        dezalocare(&(*radacina)->dr);
        free((*radacina)->info.nume);
        free(*radacina);
        *radacina = NULL;
    }
}

int main() {
    Nod* arbore = citireDinFisier("angajati.txt");

    // afisareInordine(arbore)
    afisareInordine(arbore);
     afisarePreordine(arbore);
        afisarePostordine(arbore);
        dezalocare(&arbore);
        afisarePostordine(arbore);

    return 0;
}