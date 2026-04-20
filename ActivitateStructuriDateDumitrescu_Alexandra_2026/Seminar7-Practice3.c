#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ---- Structura Masina (aceeasi ca la tine) ----
struct StructuraMasina {
    int id;
    int nrUsi;
    float pret;
    char* model;
    char* numeSofer;
    unsigned char serie;
};
typedef struct StructuraMasina Masina;

// ---- Linear Probing: stare slot ----
typedef enum { GOL, OCUPAT, STERS } Stare;

typedef struct {
    Masina info;
    Stare stare;
} Slot;

typedef struct {
    Slot* vector;   // vector de sloturi directe, NU de pointeri la liste
    int dim;
} HashTableLP;

// ---- Hash (acelasi ca la tine) ----
int calculeazaHash(const char* cheie, int dimensiune) {
    int suma = 0;
    for (int i = 0; i < strlen(cheie); i++) {
        suma += cheie[i];
    }
    return suma % dimensiune;
}

// ---- Initializare ----
HashTableLP initializareLP(int dimensiune) {
    HashTableLP ht;
    ht.dim = dimensiune;
    ht.vector = (Slot*)malloc(dimensiune * sizeof(Slot));
    for (int i = 0; i < dimensiune; i++) {
        ht.vector[i].stare = GOL;
    }
    return ht;
}

// ---- Inserare cu probing circular ----
void inserareLP(HashTableLP* ht, Masina masina) {
    int poz = calculeazaHash(masina.numeSofer, ht->dim);
    int original = poz;

    // sari peste sloturile ocupate
    while (ht->vector[poz].stare == OCUPAT) {
        poz = (poz + 1) % ht->dim;     // circular: dupa ultima revii la 0
        if (poz == original) return;    // tabela plina, nu mai inserezi
    }

    // poz e GOL sau STERS — ambele sunt ok pentru inserare
    ht->vector[poz].info = masina;
    ht->vector[poz].stare = OCUPAT;
}

// ---- Cautare ----
Masina cautareLP(HashTableLP ht, const char* numeSofer) {
    int poz = calculeazaHash(numeSofer, ht.dim);
    int original = poz;

    // nu te opresti la STERS, continui — elementul cautat poate fi mai departe
    while (ht.vector[poz].stare != GOL) {
        if (ht.vector[poz].stare == OCUPAT &&
            strcmp(ht.vector[poz].info.numeSofer, numeSofer) == 0) {
            return ht.vector[poz].info;
        }
        poz = (poz + 1) % ht.dim;
        if (poz == original) break;     // am facut turul complet
    }

    Masina goala;
    goala.id = -1;
    return goala;
}

// ---- Stergere — marchezi STERS, nu GOL! ----
void stergereLP(HashTableLP* ht, const char* numeSofer) {
    int poz = calculeazaHash(numeSofer, ht->dim);
    int original = poz;

    while (ht->vector[poz].stare != GOL) {
        if (ht->vector[poz].stare == OCUPAT &&
            strcmp(ht->vector[poz].info.numeSofer, numeSofer) == 0) {
            free(ht->vector[poz].info.model);
            free(ht->vector[poz].info.numeSofer);
            ht->vector[poz].stare = STERS;  // NU GOL — altfel rupi lantul
            return;
        }
        poz = (poz + 1) % ht->dim;
        if (poz == original) return;
    }
}

// ---- Dezalocare ----
void dezalocareLP(HashTableLP* ht) {
    for (int i = 0; i < ht->dim; i++) {
        if (ht->vector[i].stare == OCUPAT) {
            free(ht->vector[i].info.model);
            free(ht->vector[i].info.numeSofer);
        }
        // STERS: char* deja eliberate la stergere, nu le mai atingi
    }
    free(ht->vector);
    ht->vector = NULL;
    ht->dim = 0;
}

// ---- Afisare ----
void afisareLP(HashTableLP ht) {
    for (int i = 0; i < ht.dim; i++) {
        printf("Pozitia %d: ", i);
        if (ht.vector[i].stare == GOL)    printf("(gol)\n");
        else if (ht.vector[i].stare == STERS) printf("(sters)\n");
        else {
            printf("%s - %.2f lei\n",
                ht.vector[i].info.numeSofer,
                ht.vector[i].info.pret);
        }
    }
}


void main() {

}