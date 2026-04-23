//#include<stdio.h>
//#include<stdlib.h>
//#include<malloc.h>
//#include<string.h>
//
//
////Scrie un program în C care :
////Structuri:
////
////Masina cu id, nrUsi, pret, model, numeSofer, serie
//struct Masina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	char serie;
//};
//typedef struct Masina Masina;
////Nod cu info + next
//struct Nod {
//	struct Nod* next;
//	Masina info;
//};
//typedef struct Nod Nod;
//
//
//Masina citire(FILE* f) {
//	char buffer[100];
//	char sep[4] = ",\n";
//
//	fgets(buffer, 100, f);
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
//	m.model = (char*)malloc(strlen(aux) + 1);
//	strcpy(m.model, aux);
//
//	aux = strtok(NULL, sep);
//	m.numeSofer = (char*)malloc(strlen(aux) + 1);
//	strcpy(m.numeSofer, aux);
//
//	aux = strtok(NULL, sep);
//	m.serie = aux[0];
//
//	return m;
//
//}
//
//
//void inserareLaSfarsit(Nod** cap, Masina m) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = m;
//	nou->next = NULL;
//	if (*cap == NULL) {
//		(*cap) = nou;
//	}
//	else {
//		Nod* aux = *cap;
//		while (aux->next) {
//			aux = aux->next;
//		}
//		aux->next = nou;
//
//	}
//}
//
//void inserareLaInceput(Nod** cap, Masina m) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->next = *cap;
//	nou->info = m;
//	*cap = nou;
//}
//
//Nod* cit(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//	Nod* cap = NULL;
//	while (!feof(f)) {
//		inserareLaSfarsit(&cap, citire(f));
//	}
//	fclose(f);
//	return cap;
//}
//
//void afisare(Masina m) {
//	printf("%d %d %5.2f %s %s %c\n", m.id, m.nrUsi, m.pret, m.model, m.numeSofer, m.serie);
//
//}
//
//void afis(Nod* cap) {
//	if (cap == NULL) {
//		return;
//	}
//	Nod* aux = cap;
//	while (aux) {
//		afisare(aux->info);
//		aux = aux->next;
//	}
//}
//
//void stergeDupaID(int id, Nod** cap) {
//	if (*cap == NULL) {
//		return;
//	}
//	else if ((*cap)->info.id == id){
//		Nod* temp = *cap;
//		(*cap) = (*cap)->next;
//		free(temp->info.numeSofer);
//		free(temp->info.model);
//		free(temp);
//	}
//	else {
//		Nod* aux = *cap;
//		Nod* prev = *cap;
//		while (aux) {
//			if (aux->info.id == id) {
//				prev->next = aux->next;
//				free(aux->info.numeSofer);
//				free(aux->info.model);
//				free(aux);
//				return;
//			}
//			prev = aux;
//			aux = aux->next;
//		}
//	}
//}
//
//void dezalocare(Nod** cap) {
//	Nod* aux = *cap;
//	while (aux) {
//		Nod* temp = aux;
//		aux = aux->next;
//		free(temp->info.numeSofer);
//		free(temp->info.model);
//		free(temp);
//	}
//	(*cap) = NULL;
//}
//
//void main() {
//	Nod* cap = cit("masini.txt");
//	afis(cap);
//	stergeDupaID(3, &cap);
//
//	afis(cap);
//	dezalocare(&cap);
//	afis(cap);
//}