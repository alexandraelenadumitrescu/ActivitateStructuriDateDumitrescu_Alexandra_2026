////Cerințe:
////
////Citește produsele dintr - un fișier și construiește un ABC după nume(cheie)
////Afișează toate produsele în cele 3 moduri de parcurgere
////Caută un produs după nume și afișează - l
////Calculează prețul total al tuturor produselor din stoc(stoc * pret pentru fiecare)
////Calculează prețul total al produselor unui brand dat(ex: toate produsele Apple)
////Determină numărul total de noduri din arbore
////Calculează înălțimea arborelui
////Găsește produsul cel mai scump din arbore
////Găsește produsul cu cel mai mare stoc
////Dezalocă corect tot arborele
//
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<malloc.h>
//
//
//struct Produs {
//    char* nume;
//    char* brand;
//    int stoc;
//    float pret;
//};
//typedef struct Produs Produs;
//
//struct Nod {
//    struct Nod* stg;
//    struct Nod* drp;
//    Produs info;
//};
//typedef struct Nod Nod;
//
////Citește produsele dintr - un fișier și construiește un ABC după nume(cheie)
//
//Produs citire(FILE* f) {
//
//    char buffer[100];
//    char sep[5] = ", \n";
//
//    fgets(buffer, 100, f);
//
//    Produs p;
//    char* aux = strtok(buffer, sep);
//    p.nume = (char*)malloc(strlen(aux) + 1);
//    strcpy(p.nume, aux);
//
//    aux = strtok(NULL, sep);
//    p.brand = (char*)malloc(strlen(aux) + 1);
//    strcpy(p.brand, aux);
//
//    aux = strtok(NULL, sep);
//    p.stoc = atoi(aux);
//
//    aux = strtok(NULL, sep);
//    p.pret = atof(aux);
//
//    return p;
//}
//
//void inserareABC(Nod** radacina, Produs p) {
//    if (*radacina) {
//        if (p.pret < (*radacina)->info.pret) {
//            inserareABC(&(*radacina)->stg, p);
//        }
//        else {
//            inserareABC(&(*radacina)->drp, p);
//        }
//       
//        
//    }
//    else {
//        Nod* nou = (Nod*)malloc(sizeof(Nod));
//        nou->info = p;
//        nou->stg = NULL;
//        nou->drp= NULL;
//        (*radacina)=nou;
//    }
//}
//
//Nod* citireABC(const char* numeFisier) {
//    FILE* f = fopen(numeFisier, "r");
//    Nod* radacina = NULL;
//    while (!feof(f)) {
//        inserareABC(&radacina, citire(f));
//    }
//    return radacina;
//}
//
//void afisare(Produs p) {
//    printf("%s %s %d %5.2f\n", p.nume, p.brand, p.stoc, p.pret);
//}
//
//void afisareABC(Nod* radacina) {
//    if (radacina) {
//        afisareABC(radacina->stg);
//        afisareABC(radacina->drp);
//        afisare(radacina->info);
//    }
//    
//}
//
//void cautaNume(Nod* radacina, char* nume) {
//    if (radacina) {
//        if (strcmp(radacina->info.nume, nume) == 0) {
//            afisare(radacina->info);
//        }
//        cautaNume(radacina->stg,nume);
//        cautaNume(radacina->drp,nume);
//    }
//    
//}
//
////Calculează prețul total al tuturor produselor din stoc(stoc * pret pentru fiecare)
//float pretTotal(Nod* radacina) {
//    float s = 0;
//    if (radacina) {
//        s += pretTotal(radacina->stg);
//        s += pretTotal(radacina->drp);
//        s += radacina->info.pret*radacina->info.stoc;
//    }
//    return s;
//}
//
////Calculează prețul total al produselor unui brand dat(ex: toate produsele Apple)
//float pretBrand(Nod* radacina, char* brand) {
//    float s = 0;
//    if (radacina) {
//        s += pretBrand(radacina->stg, brand);
//        s += pretBrand(radacina->drp, brand);
//        if (strcmp(radacina->info.brand, brand) == 0) {
//            s += radacina->info.pret * radacina->info.stoc;
//        }
//    }
//    return s;
//}
////Determină numărul total de noduri din arbore
//int nrNoduriArbore(Nod* radacina) {
//    if (radacina) {
//        return nrNoduriArbore(radacina->stg) + nrNoduriArbore(radacina->drp) + 1;
//    }
//    return 0;
//}
//
////Calculează înălțimea arborelui
//int inaltime(Nod* radacina) {
//    if (radacina) {
//        return inaltime(radacina->stg) > inaltime(radacina->drp) ? inaltime(radacina->stg) + 1 : inaltime(radacina->drp) + 1;
//    }
//}
//
////Găsește produsul cel mai scump din arbore
//void maxim(Nod* radacina) {
//    if (radacina) {
//        
//        if (radacina->drp==NULL) {
//            afisare( radacina->info);
//        }
//        else {
//            maxim(radacina->drp);
//        }
//    }
//}
//
//void dezalocare(Nod** radacina) {
//    if (*radacina) {
//        dezalocare(&(*radacina)->stg);
//        dezalocare(&(*radacina)->drp);
//        free((*radacina)->info.nume);
//        free((*radacina)->info.brand);
//        free(*radacina);
//        *radacina = NULL;
//    }
//    
//}
//
////Găsește produsul cu cel mai mare stoc
//int stocMaxim(Nod* radacina) {
//    
//    if (radacina) {
//        int maxS = stocMaxim(radacina->stg);
//        int maxD= stocMaxim(radacina->drp);
//        int max = radacina->info.stoc;
//        if (maxS > max) max = maxS;
//        if (maxD > max) max = maxD;
//        return max;
//    }
//    return 0;
//
//}
//
//void main() {
//
//    Nod* radacina = citireABC("inventory.txt");
//    afisareABC(radacina);
//    cautaNume(radacina, "ThinkPad");
//    printf("%5.2f\n", pretTotal(radacina));
//    printf("%5.2f\n", pretBrand(radacina,"Apple"));
//    printf("%d\n", nrNoduriArbore(radacina));
//    printf("%d\n", inaltime(radacina));
//    maxim(radacina);
//    printf("%d\n", stocMaxim(radacina));
//    dezalocare(&radacina);
//    afisareABC(radacina);
//
//
//}