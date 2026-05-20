//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
//
//struct Angajat {
//	int id;
//	char* nume;
//	float salariu;
//
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
//
//Angajat citire(FILE* f) {
//	Angajat a;
//	char buffer[100];
//	char sep[4] = ",\n";
//
//	fgets(buffer, 100, f);
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
//	}
//	return 0;
//	
//}
//
//void rotireDreapta(Nod** radacina) {
//	Nod* aux = (*radacina)->st;
//	(*radacina)->st = aux->dr;
//	aux->dr = (*radacina);
//	*radacina = aux;
//
//	
//}
//
//void rotireStanga(Nod** radacina) {
//	Nod* aux = (*radacina)->dr;
//	(*radacina)->dr = aux->st;
//	aux->st = (*radacina);
//	(*radacina) = aux;
//}
//
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
//
//	if (gradEchilibru(*radacina) == 2) {
//		if (gradEchilibru((*radacina)->st) >= 0) {
//			rotireDreapta(radacina);
//		}
//		else {
//			rotireStanga(&(*radacina)->st);
//			rotireDreapta(radacina);
//		}
//		
//	}
//	else if (gradEchilibru(*radacina) == -2) {
//		if (gradEchilibru((*radacina)->dr) <= 0) {
//			rotireStanga(radacina);
//		}
//		else {
//			rotireDreapta(&(*radacina)->dr);
//			rotireStanga(radacina);
//		}
//	}
//
//}
//
//Nod* citireFisier(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//	Nod* radacina = NULL;
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
//}
//
//void main() {
//
//	Nod* arbore = citireFisier("angajati.txt");
//	afisarePreordine(arbore);
//
//}