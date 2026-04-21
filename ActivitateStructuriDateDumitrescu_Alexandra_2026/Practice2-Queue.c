#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

struct Masina {
	int id;
	int nrUsi;
	float pret;
	char* numeSofer;
	char* model;
	char serie;
};
typedef struct Masina Masina;


struct Nod {
	struct Nod* next;
	struct Nod* prev;
	Masina info;
};

typedef struct Nod Nod;

struct LD {
	Nod* prim;
	Nod* ultim;
};

typedef struct LD LD;

Masina citireMasina(FILE* f) {
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

void enqueue(Masina m, LD* ld) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = m;
	nou->next = ld->ultim;
	nou->prev = NULL;
	if (ld->prim) {
		ld->ultim->prev = nou;
		
	}
	else {
		ld->prim = nou;
	}
	ld->ultim = nou;
}

Masina dequeue(LD* ld) {
	Masina m;
	m.id = -1;
	if (ld->prim) {
		m = ld->prim->info;
		Nod* aux = ld->prim;
		ld->prim = ld->prim->prev;
		free(aux->info.numeSofer);
		free(aux->info.model);
		free(aux);
	}
	return m;
}

LD citireLD(const char* numeFisier) {
	FILE* f = fopen(numeFisier, "r");
	LD ld;
	ld.prim = NULL;
	ld.ultim = NULL;
	while (!feof(f)) {
		Masina m = citireMasina(f);
		enqueue(m, &ld);
	}
	fclose(f);
	return ld;
}

void afisareMasina(Masina m) {
	printf("%d %d %f %s %s %c\n", m.id, m.nrUsi, m.pret, m.numeSofer, m.model, m.serie);
}

void afisareQueue(LD* ld) {
	Nod* temp = ld->prim;
	while (temp) {
		afisareMasina(temp->info);
		temp = temp->prev;
	}
}

void dezalocare(LD* ld) {
	while (ld->prim) {
		Nod* temp = ld->prim;
		ld->prim = ld->prim->prev;
		free(temp->info.numeSofer);
		free(temp->info.model);
		free(temp);
		
	}
}

void main() {
	LD ld = citireLD("masini.txt");
	afisareQueue(&ld);
	dezalocare(&ld);
	printf("dupa dezaloc\n");
	afisareQueue(&ld);

}