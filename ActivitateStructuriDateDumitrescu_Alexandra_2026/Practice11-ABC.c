//#include<stdio.h>
//#include<stdlib.h>
//#include<malloc.h>
//#include<string.h>
//
////ABC - Angajat(id, nume, salariu) | cheie sortare : id
//struct Angajat {
//	int id;
//	char* nume;
//	float salariu;
//};
//typedef struct Angajat Angajat;
//
//typedef struct Nod {
//	Angajat info;
//	struct Nod* st;
//	struct Nod* dr;
//} Nod;
//
//
////
////1. Citeste un angajat dintr - un fisier deschis si returneaza structura.
//// 
//Angajat citeste(FILE* f) {
//	Angajat a;
//
//	char buffer[100];
//	char sep[4] = ",\n";
//	
//	fgets(buffer, 100, f);
//
//	char* aux = strtok(buffer, sep);
//	a.id = atoi(aux);
//
//	aux = strtok(NULL, sep);
//	a.nume = (char*)malloc(strlen(aux) + 1);
//	strcpy(a.nume, aux);
//
//	aux = strtok(NULL, sep);
//	a.salariu = atof(aux);
//
//	return a;
//
//}
////2. Afiseaza campurile unui angajat.
//void afisare(Angajat a) {
//	printf("id : %d  nume : %s  salariu : %5.2f\n", a.id, a.nume, a.salariu);
//}
//void inserare(Nod** radacina, Angajat a) {
//	if (*radacina) {
//		if ((*radacina)->info.id < a.id) {
//			inserare(&(*radacina)->dr, a);
//		}
//		else {
//			inserare(&(*radacina)->st, a);
//		}
//	}
//	else {
//		Nod* aux = (Nod*)malloc(sizeof(Nod));
//		aux->info = a;
//		aux->st = NULL;
//		aux->dr = NULL;
//		*radacina = aux;
//	}
//}
//
//Nod* citireFisier(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//	Nod* radacina = NULL;
//	while (!feof(f)) {
//		inserare(&radacina, citeste(f));
//	}
//	return radacina;
//}
//
//
////3. Afiseaza toti angajatii din arbore in ordine crescatoare dupa id.
//void afisarePreordine(Nod* radacina) {
//	if (radacina) {
//		afisare(radacina->info);
//		afisarePreordine(radacina->st);
//		afisarePreordine(radacina->dr);
//	}
//}
//void afisareInordine(Nod* radacina) {
//	if (radacina) {
//		
//		afisareInordine(radacina->st);
//		afisare(radacina->info);
//		afisareInordine(radacina->dr);
//	}
//}
////4. Afiseaza toti angajatii din arbore in preordine.
////5. Afiseaza toti angajatii din arbore in postordine.
////6. Cauta un nod dupa id si returneaza pointerul la el, sau NULL daca nu exista.
////7. Dezaloca recursiv toti angajatii si nodurile din arbore.
////8. Deschide un fisier, citeste toti angajatii si construieste arborele; returneaza radacina.
//
//void dezalocare(Nod** radacina) {
//	if (*radacina) {
//		dezalocare(&(*radacina)->st);
//		dezalocare(&(*radacina)->dr);
//		free((*radacina)->info.nume);
//		free(*radacina);
//		*radacina = NULL;
//	}
//}
//
//void main() {
//	Nod* arbore = citireFisier("angajati.txt");
//	afisarePreordine(arbore);
//	printf("\n");
//	afisareInordine(arbore);
//	dezalocare(&arbore);
//	afisarePreordine(arbore);
//
//}