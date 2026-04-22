#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

//Hash table complet — cerință :
//Scrie un program în C care :
//Structuri:
//
//Masina cu id, nrUsi, pret, model, numeSofer, serie
struct Masina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	char serie;
};
typedef struct Masina Masina;
//Nod cu info + next
struct Nod {
	struct Nod* next;
	Masina info;
};
typedef struct Nod Nod;
//HashTable cu vector + dim
struct HT {
	Nod** vector;
	int dim;
};
typedef struct  HT HT;
//Ia mașinile din fișierul masini.txt și bagă - le într - un hash table cu dimensiunea 7.
//Afișează tot tabelul.Caută mașina lui "Ionescu" și afișeaz - o dacă există.La final dezalocă tot.
Masina citire(FILE* f) {
	char buffer[100];
	char sep[4] = ",\n";

	fgets(buffer, 100, f);
	char* aux = strtok(buffer, sep);
	Masina m;
	m.id = atoi(aux);

	aux = strtok(NULL, sep);
	m.nrUsi = atoi(aux);

	aux = strtok(NULL, sep);
	m.pret = atof(aux);

	aux = strtok(NULL, sep);
	m.model = (char*)malloc(strlen(aux) + 1);
	strcpy(m.model, aux);

	aux = strtok(NULL, sep);
	m.numeSofer = (char*)malloc(strlen(aux) + 1);
	strcpy(m.numeSofer, aux);

	aux = strtok(NULL, sep);
	m.serie = aux[0];

	return m;

}

int calcHash(int dim, Masina m) {
	int s = 0;
	for (int i = 0;i < strlen(m.numeSofer);i++) {
		s += m.numeSofer[i];
	}
	return s % dim;
}

HT init(int dim) {
	HT ht;
	ht.dim = dim;
	ht.vector = (Nod**)malloc(sizeof(Nod*)*dim);
	for (int i = 0;i < dim;i++) {
		ht.vector[i] = NULL;
	}
	return ht;
}

void inserare(HT* ht, Masina m) {
	int h = calcHash(ht->dim, m);
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = m;
	nou->next = NULL;
	
		if (ht->vector[h] == NULL) {
			ht->vector[h] = nou;
		}
		else {
			Nod* aux = ht->vector[h];
			while (aux->next) {
				aux = aux->next;
			}
			aux->next = nou;
		}
	
}

HT populare(const char* numeFisier, int dim) {
	FILE* f = fopen(numeFisier, "r");
	HT ht = init(dim);
	while(!feof(f)){
		inserare(&ht, citire(f));
	}
	fclose(f);
	return ht;
}

void afisare(Masina m) {
	printf("%d %d %f %s %s %c\n", m.id, m.nrUsi, m.pret, m.numeSofer, m.model, m.serie);

}

void af(HT ht) {
	for (int i = 0;i < ht.dim;i++) {
		if (ht.vector[i]) {
			Nod* aux = ht.vector[i];
			while (aux) {
				afisare(aux->info);
				aux = aux->next;
			}
		}
	}
}

Masina cauta(Masina m, HT ht) {
	Masina empty;
	empty.id = -1;
	if (ht.vector[calcHash(ht.dim,m)] == NULL) {
		return empty;
	}
	else {
		Nod* aux = ht.vector[calcHash(ht.dim,m)];
		while (aux) {
			if (strcmp(aux->info.numeSofer, m.numeSofer) == 0) {
				return aux->info;
			}
			aux = aux->next;
		}
	}
	return empty;
}

void dezalocare(HT* ht) {
	for (int i = 0;i < ht->dim;i++) {
		
		if (ht->vector[i] != NULL) {
			Nod* aux = ht->vector[i];
			while (aux) {
				Nod* temp = aux;
				aux = aux->next;
				free(temp->info.numeSofer);
				free(temp->info.model);
				free(temp);
			}
			
		}
	}
	free(ht->vector);
	ht->vector = NULL;
	ht->dim = 0;
	printf("dezalocare cu succes\n");
	
}

void main() {
	HT ht = populare("masini.txt", 10);
	af(ht);
	Masina m;
	m.numeSofer = "Ionescu";
	afisare(cauta(m, ht));
	dezalocare(&ht);
	af(ht);
}