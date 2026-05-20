//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
//struct Angajat {
//	int id;
//	char* nume;
//	float salariu;
//};
//
//typedef struct Angajat Angajat;
//
//struct Nod {
//	Angajat info;
//	struct Nod* st;
//	struct Nod* dr;
//};
//
//typedef struct Nod Nod;
//
//Angajat citire(FILE* f) {
//	Angajat a;
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
//
//int inaltime(Nod* radacina) {
//	if (radacina) {
//		int stg = inaltime(radacina->st);
//		int drp = inaltime(radacina->dr);
//		return stg > drp ? stg + 1 : drp + 1;
//	}
//	return 0;
//}
//
//int gradEchilibru(Nod* radacina) {
//	if (radacina) {
//		return inaltime(radacina->st) - inaltime(radacina->dr);
//
//	}
//	return 0;
//}
//
//void rotireDreapta(Nod** radacina) {
//	Nod* aux = (Nod*)malloc(sizeof(Nod));
//	aux = (*radacina)->st;
//	(*radacina)->st = aux->dr;
//	aux->dr = (*radacina);
//	*radacina = aux;
//
//}
//
//void rotireStanga(Nod** radacina) {
//	Nod* aux = (Nod*)malloc(sizeof(Nod));
//	aux = (*radacina)->dr;
//	(*radacina)->dr = aux->st;
//	aux->st = (*radacina);
//	*radacina = aux;
//}
//
//void inserare(Nod** radacina, Angajat a) {
//	if (*radacina) {
//		if ((*radacina)->info.id < a.id) {
//			inserare(&(*radacina)->dr, a);
//		}
//		else {
//			inserare(&(*radacina)->st, a);
//
//		}
//	}
//	else {
//		Nod* aux = (Nod*)malloc(sizeof(Nod));
//		aux->info = a;
//		aux->st = NULL;
//		aux->dr = NULL;
//		*radacina = aux;
//	}
//	int echilibru = gradEchilibru(*radacina);
//	if (echilibru == 2) {
//		if (gradEchilibru((*radacina)->st) >= 0) {
//			//rotire dreapta
//			rotireDreapta(radacina);
//		}
//		else {
//			//rotire stanga copil
//			rotireStanga(&(*radacina)->st);
//			//rotire dreapta radacina
//			rotireDreapta(radacina);
//
//		}
//
//	}
//	else if (echilibru == -2) {
//		if (gradEchilibru((*radacina)->dr) <= 0) {
//			//rotire stanga
//			rotireStanga(radacina);
//		}
//		else {
//			//rotire dreapta copil
//			rotireDreapta(&(*radacina)->dr);
//			//rotire stanga radacina
//			rotireStanga(radacina);
//		}
//	}
//}
//
//Nod* citireFisier(const char* numeFisier) {
//	Nod* radacina = NULL;
//	FILE* f=fopen(numeFisier, "r");
//	while (!feof(f)) {
//		inserare(&radacina, citire(f));
//	}
//	return radacina;
//}
//
//void afisare(Angajat a) {
//	printf("%d %s %5.2f\n", a.id, a.nume, a.salariu);
//}
//
//void afisarePreordine(Nod* radacina) {
//	if (radacina) {
//		afisare(radacina->info);
//		afisarePreordine(radacina->st);
//		afisarePreordine(radacina->dr);
//	}
//	
//}
////AVL - Angajat(id, nume, salariu) | cheie sortare : id
////(citire, afisare, cele 3 afisari, dezalocare - identice cu ABC)
////
////1. Calculeaza inaltimea unui subarbore; returneaza 0 daca nodul e NULL.
////2. Calculeaza gradul de echilibru al unui nod ca diferenta dintre inaltimea subarborelui stang si drept.
////3. Roteste arborele spre dreapta in jurul nodului dat.
////4. Roteste arborele spre stanga in jurul nodului dat.
////5. Insereaza un angajat ca la ABC, apoi verifica si corecteaza echilibrul pentru toate cele 4 cazuri(LL, LR, RR, RL).
////6. Deschide un fisier, citeste toti angajatii si construieste arborele AVL; returneaza radacina.
//
//void main() {
//	Nod* arbore = citireFisier("angajati.txt");
//	afisarePreordine(arbore);
//
//}