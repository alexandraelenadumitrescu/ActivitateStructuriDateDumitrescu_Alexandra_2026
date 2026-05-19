////CERINTE - Arbore Binar de Cautare(ABC) cu struct Angajat
////==========================================================
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//typedef struct {
//    int id;
//    char* nume;
//    float salariu;
//} Angajat;
//
//typedef struct Nod Nod;
//struct Nod {
//    Angajat info;
//    Nod* st;
//    Nod* dr;
//};
//
////Fisierul angajati.txt are formatul :
////id, nume, salariu
////Exemplu : 3, Popescu Ion, 4500.00
////
////Cheie de sortare in arbore : campul id.
//
////------------------------------------------------------------
////CERINTE OBLIGATORII
////------------------------------------------------------------
////
////1.[Citire din fisier]
////Implementeaza functia :
////Angajat citireAngajatDinFisier(FILE * file);
////Citeste o linie din fisier si returneaza un Angajat.
////Atentie: nume este char* — aloci memorie cu malloc.
//Angajat citire(FILE* f) {
//
//    Angajat a;
//    char buffer[100];
//    char sep[4] = ",\n";
//
//    fgets(buffer, 100, f);
//    char* aux = strtok(buffer, sep);
//    a.id = atoi(aux);
//
//    aux = strtok(NULL, sep);
//    a.nume = (char*)malloc(strlen(aux) + 1);;
//    strcpy(a.nume, aux);
//
//    aux = strtok(NULL, sep);
//    a.salariu = atof(aux);
//
//    return a;
//}
//
//
////
////2.[Inserare]
////    Implementeaza functia :
////    void inserareInArbore(Nod * *radacina, Angajat a);
////    -Daca arborele e gol, creezi nodul radacina.
////        - Daca id < nod curent → inserezi in subarborele stang.
////        - Daca id > nod curent → inserezi in subarborele drept.
////        - Daca id == nod curent → actualizezi numele si salariul
////        (eliberezi vechiul nume, aloci memorie pentru cel nou).
////        Nodul nou are st = NULL si dr = NULL.
////
//void inserare(Nod** radacina, Angajat a) {
//    
//    if (*radacina) {
//        if ((*radacina)->info.id > a.id) {
//            inserare(&(*radacina)->st, a);
//        }
//        else {
//            inserare(&(*radacina)->dr, a);
//        }
//
//    }
//    else {
//        Nod* nou = (Nod*)malloc(sizeof(Nod));
//        nou->info = a;
//        nou->st = NULL;
//        nou->dr = NULL;
//        *radacina = nou;
//
//    }
//}
////        3.[Afisare inordine]
////        Implementeaza functia :
////    void afisareInordine(Nod * radacina);
////Parcurgere: st → nod → dr.
////Rezultat : angajatii afisati in ordine crescatoare dupa id.
//void afisare(Angajat a) {
//    printf("id: %d nume: %s salariu: %.2f\n", a.id, a.nume, a.salariu);
//}
//
//void afisareInordine(Nod* radacina) {
//    if (radacina) {
//        afisareInordine(radacina->st);
//        afisare(radacina->info);
//        afisareInordine(radacina->dr);
//    }
//}
//
//Nod* citireDinFisier(const char* numeFisier) {
//    FILE* f = fopen(numeFisier, "r");
//    Nod* radacina = NULL;
//    while (!feof(f)) {
//        inserare(&radacina, citire(f));
//    }
//    return radacina;
//}
////
////4.[Afisare preordine]
////Implementeaza functia :
////void afisarePreordine(Nod * radacina);
////Parcurgere: nod → st → dr.
////
//
//void afisarePreordine(Nod* radacina) {
//    if (radacina) {
//        afisare(radacina->info);
//        afisarePreordine(radacina->st);
//        
//        afisarePreordine(radacina->dr);
//    }
//}void afisarePostordine(Nod* radacina) {
//    if (radacina) {
//        afisarePostordine(radacina->st);
//        
//        afisarePostordine(radacina->dr);
//        afisare(radacina->info);
//
//    }
//}
////5.[Afisare postordine]
////Implementeaza functia :
////void afisarePostordine(Nod * radacina);
////Parcurgere: st → dr → nod.
////
////6.[Cautare dupa id]
////Implementeaza functia :
////Nod * cautaDupaId(Nod * radacina, int id);
////Returneaza pointerul la nodul gasit, sau NULL daca nu exista.
////(Nu deep copy — returnezi direct nodul din arbore.)
//Nod* cauta(Nod* radacina, int id) {
//    if (radacina) {
//        if (radacina->info.id == id) {
//            return radacina;
//        }
//        else {
//            if (radacina->info.id < id) {
//                cauta(radacina->dr, id);
//            }
//            else {
//                cauta(radacina->st, id);
//            }
//        }
//    }
//    else {
//        return NULL;
//    }
//}
////7.[Dezalocare]
////    Implementeaza functia :
////    void dezalocare(Nod * *radacina);
////    -Dezaloci intai st, apoi dr(postordine).
////        - Eliberezi free(nod->info.nume) inainte de free(nod).
////        - La final setezi * radacina = NULL.
////
//void dezalocare(Nod** radacina) {
//    if (*radacina) {
//        dezalocare(&(*radacina)->st);
//        dezalocare(&(*radacina)->dr);
//        free((*radacina)->info.nume);
//        free(*radacina);
//        *radacina = NULL;
//    }
//}
////        ------------------------------------------------------------
////        CERINTE BONUS
////        ------------------------------------------------------------
////
////        8.[Numar noduri]
////        int numarNoduri(Nod * radacina);
////    Returneaza numarul total de noduri din arbore.
////
////        9.[Inaltime arbore]
////        int inaltimeArbore(Nod * radacina);
////    Returneaza inaltimea arborelui(0 daca e NULL).
////
////        10.[Salariu total]
////        float salariuTotal(Nod * radacina);
////    Returneaza suma salariilor tuturor angajatilor din arbore.
////
////        11.[Angajat cu salariul maxim]
////        Nod * angajatMaxSalariu(Nod * radacina);
////    Returneaza pointerul la nodul cu salariul cel mai mare.
////
////        ------------------------------------------------------------
////        MAIN sugerat
////        ------------------------------------------------------------
//
//        int main() {
//            Nod* arbore = citireDinFisier("angajati.txt");
//            afisareInordine(arbore);
//            afisarePreordine(arbore);
//            afisarePostordine(arbore);
//
//            afisare(cauta(arbore, 5)->info);
//
//            dezalocare(&arbore);
//
//        // citire din fisier
//        // afisare inordine
//        // afisare preordine
//        // afisare postordine
//        // cautare dupa id (ex: id=5)
//        // afisare rezultat cautare
//        // bonus: numar noduri, inaltime, salariu total
//        // dezalocare
//
//
//
//        return 0;
//    }