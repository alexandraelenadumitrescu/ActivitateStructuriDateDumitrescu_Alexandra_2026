//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<malloc.h>
//
//struct Tara {
//	char* nume;
//	float supraf;
//	int loc;
//};
//typedef struct Tara Tara;
//struct Nod {
//	Tara info;
//	struct Nod* next;
//};
//typedef struct Nod Nod;
//
//struct Hash {
//	int dim;
//	Nod** vector;
//
//};
//typedef struct Hash Hash;
//
//Hash init(int dim) {
//	Hash ht;
//	ht.dim = dim;
//	//ht.vector = (Nod*)malloc(sizeof(Nod) * dim);
//	ht.vector = (Nod**)malloc(sizeof(Nod*) * dim);
//	for (int i = 0; i < dim; i++) {
//		ht.vector[i] = NULL;
//
//	}
//	return ht;
//}
//
//
//Tara citire(FILE* f) {
//	char buffer[100];
//	char sep[4] = ",\n";
//
//	fgets(buffer, 100, f);
//	char* aux = strtok(buffer, sep);
//	Tara t;
//	t.nume = (char*)malloc(strlen(aux) + 1);
//	strcpy(t.nume, aux);
//
//	aux = strtok(NULL, sep);
//	t.supraf = atof(aux);
//
//	aux = strtok(NULL, sep);
//	t.loc = atoi(aux);
//
//	return t;
//
//}
//int calcHash(int dim, Tara t) {
//	int s = 0;
//	for (int i = 0; i < strlen(t.nume); i++) {
//		s += t.nume[i];
//	}
//	return s % dim;
//}
//
//void inserare(Tara t, Hash* ht) {
//	int poz = calcHash(ht->dim, t);
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = t;
//	nou->next = NULL;
//	if (ht->vector[poz] == NULL) {
//		ht->vector[poz] = nou;
//	}
//	else {
//		Nod* aux = ht->vector[poz];
//		while (aux->next) {
//			aux = aux->next;
//		}
//		aux->next = nou;
//	}
//
//}
//
//Hash hai(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//	Hash ht = init(8);
//
//	while (!feof(f)) {
//		Tara t = citire(f);
//		inserare(t, &ht);
//	}
//	return ht;
//
//}
//
//void afisare(Tara t)
//{
//	printf("%s %5.2f %d\n", t.nume, t.supraf, t.loc);
//}
//
//void af(Hash ht) {
//	for (int i = 0; i < ht.dim; i++) {
//		if (ht.vector[i] != NULL) {
//			Nod* aux = ht.vector[i];
//			while (aux) {
//				afisare(aux->info);
//				aux = aux->next;
//			}
//		}
//	}
//}
//
//float getMedie(Hash ht) {
//	int count = 0;
//	float sum = 0;
//	for (int i = 0; i < ht.dim; i++) {
//		if (ht.vector[i] != NULL) {
//			Nod* aux = ht.vector[i];
//			while (aux) {
//				count++;
//				sum += aux->info.supraf;
//				
//				aux = aux->next;
//			}
//		}
//	}
//	return (float)(sum / count);
//}
//
//int getLoc(char* nume, Hash ht) {
//	int loc = 0;
//	for (int i = 0; i < ht.dim; i++) {
//		if (ht.vector[i] != NULL) {
//			Nod* aux = ht.vector[i];
//			while (aux) {
//				//afisare(aux->info);
//				printf("%s\n", aux->info.nume);
//				if (strcmp(aux->info.nume, nume) == 0) {
//					//return aux->info.loc;
//					loc = aux->info.loc;
//					return loc;
//				}
//				aux = aux->next;
//			}
//		}
//	}
//	return loc;
//}
//
//Tara deep(Hash ht, char* nume) {
//	for (int i = 0; i < ht.dim; i++) {
//		if (ht.vector[i] != NULL) {
//			Nod* aux = ht.vector[i];
//			while (aux) {
//				//afisare(aux->info);
//				//printf("%s\n", aux->info.nume);
//				if (strcmp(aux->info.nume, nume) == 0) {
//					//return aux->info.loc;
//					Tara t;
//					t.loc = aux->info.loc;
//					t.supraf = aux->info.supraf;
//					t.nume = (char*)malloc(strlen(aux->info.nume) + 1);
//					strcpy(t.nume, aux->info.nume);
//					return t;
//				}
//				aux = aux->next;
//			}
//		}
//	}
//}
//
//void dezalocare(Hash* ht) {
//	for (int i = 0; i < ht->dim; i++) {
//		if (ht->vector[i] != NULL) {
//			Nod* aux = ht->vector[i];
//			while (aux) {
//				//afisare(aux->info);
//				//printf("%s\n", aux->info.nume);
//
//
//			}
//			aux = aux->next;
//		}
//	}
//}
//
//
//
//
//
//
//void main() {
//	printf("--------------\n");
//	Hash ht = hai("tari.txt");
//	af(ht);
//	printf("--------------\n");
//	printf("%5.2f\n", getMedie(ht));
//	printf("--------------\n");
//	printf("%d\n", getLoc("ESP", ht));
//	printf("--------------\n");
//	Tara t = deep(ht, "SUA");
//
//	afisare(t);
//
//
//
//}