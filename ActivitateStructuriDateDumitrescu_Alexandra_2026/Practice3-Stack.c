//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<malloc.h>
//
//struct Masina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* numeSofer;
//	char* model;
//	char serie;
//};
//
//typedef struct Masina Masina;
//
//
//
//struct Nod {
//	struct Nod* next;
//	Masina info;
//};
//
//typedef struct  Nod Nod;
//
//void push(Nod** cap, Masina m) {
//	Nod* aux = (Nod*)malloc(sizeof(Nod));
//	aux->info = m;
//	
//	aux->next = *cap;
//	*cap = aux;
//
//}
//
//Masina pop(Nod** cap) {
//	Masina m;
//	m.id = -1;
//	if (*cap) {
//		Nod* temp = *cap;
//		m = (*cap)->info;
//		*cap = (*cap)->next;
//		free(temp->info.numeSofer);//atentie e shallow si dezaloc aiurea
//		free(temp->info.model);
//		free(temp);
//	}
//	return m;
//}
//
//Masina citeste(FILE* f) {
//	char buffer[100];
//	char sep[4] = ",\n";
//
//
//	fgets(buffer, 100, f);
//
//	char* aux = strtok(buffer, sep);
//	Masina m;
//	m.id = atoi(aux);
//
//	aux = strtok(NULL, sep);
//	m.nrUsi = atoi(aux);
//
//	aux = strtok(NULL, sep);
//	m.pret = atof(aux);
//
//	aux = strtok(NULL, sep);
//	m.numeSofer = (char*)malloc(strlen(aux)+1);
//	strcpy(m.numeSofer, aux);
//
//	aux = strtok(NULL, sep);
//	m.model = (char*)malloc(strlen(aux) + 1);
//	strcpy(m.model, aux);
//
//	aux = strtok(NULL, sep);
//	m.serie = aux[0];
//
//	return m;
//
//
//}
//
//Nod* citire(const char* numeFisier) {
//	FILE*f =fopen(numeFisier, "r");
//	Nod* cap=NULL;
//	while (!feof(f)) {
//		Masina m = citeste(f);
//		push(&cap, m);
//	}
//	return cap;
//}
//
//void afiseaza(Masina m) {
//	printf("%d %d %f %s %s %c\n", m.id, m.nrUsi, m.pret, m.numeSofer, m.model, m.serie);
//}
//
//void afisStack(Nod* cap) {
//	Nod* aux = (Nod*)malloc(sizeof(Nod));
//	aux = cap;
//	while (aux) {
//
//		afiseaza(aux->info);
//		aux = aux->next;
//	}
//}
//
//void dezalocare(Nod** cap) {
//	while (*cap) {
//		Nod* aux = *cap;
//		*cap = (*cap)->next;
//		free(aux->info.numeSofer);
//		free(aux->info.model);
//		
//		free(aux);
//		
//	}
//}
//
//
//void main() {
//	Nod* cap = citire("masini.txt");
//	afisStack(cap);
//
//	dezalocare(&cap);
//	afisStack(cap);
//}