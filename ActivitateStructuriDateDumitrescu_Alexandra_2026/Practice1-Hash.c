#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct Masina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};

typedef struct Masina Masina;

struct Nod {
	Masina info;
	struct Nod* next;
};

typedef struct Nod Nod;


struct Hash {
	int dim;
	Nod** vector;
};

typedef struct Hash Hash;

Masina citireMasina(FILE* f) {
	char buffer[100];
	char sep[4] = ",\n";
	fgets(buffer, 100, f);

	char* aux;
	Masina m;

	aux = strtok(buffer, sep);
	m.id = atoi(aux);

	aux = strtok(NULL, sep);
	m.nrUsi = atoi(aux);

	aux = strtok(NULL, sep);
	m.pret = atof(aux);

	aux = strtok(NULL, sep);
	m.model = malloc(strlen(aux) + 1);
	strcpy(m.model, aux);

	aux = strtok(NULL, sep);
	m.numeSofer = malloc(strlen(aux) + 1);
	strcpy(m.numeSofer, aux);

	aux = strtok(NULL, sep);
	m.serie = aux[0];

	return m;
}
void inserareLSI(Nod** cap, Masina m) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = m;
	nou->next = NULL;
	if (*cap) {
		Nod* aux = *cap;
		while (aux->next) {
			aux = aux->next;
		}
		aux->next = nou;
	}
	else {
		*cap = nou;
	}
}

Nod* adaugaLSI(const char* numeFisier) {
	Nod* nou = NULL;
	FILE* f;
	f = fopen(numeFisier, "r");
	while (!feof(f)) {
		Masina m = citireMasina(f);
		inserareLSI(&nou, m);
		
	}
	fclose(f);
	return nou;

}



int fctHash(Masina m, int dim) {
	int s = 0;
	for (int i = 0;i < strlen(m.numeSofer);i++) {
		s += m.numeSofer[i];
	}
	return s%dim;
}

Hash initHash(int dim) {
	Hash hash;
	hash.dim = dim;
	hash.vector = (Nod**)malloc(sizeof(Nod*) * dim);
	for (int i = 0;i < dim;i++) {
		hash.vector[i] = NULL;
	}
	return hash;
}

void inserareHash(Masina m, Hash* hash) {
	int poz = fctHash(m, hash->dim);

	if (hash->vector[poz] == NULL) {
		Nod* nou = (Nod*)malloc(sizeof(Nod));
		hash->vector[poz] = nou;
		nou->info = m;
		nou->next = NULL;
	}
	else {
		inserareLSI(&(hash->vector[poz]), m);
	}
}

void afisareMasina(Masina m) {
	printf("%d %d %5.2f %s %s %c\n", m.id, m.nrUsi, m.pret, m.model, m.numeSofer, m.serie);
}

void afisareLista(Nod* cap) {
	while (cap) {
		afisareMasina(cap->info);
		cap = cap->next;
	}
}

void afisareHash(Hash* hash) {
	for (int i = 0;i < hash->dim;i++) {
		if (hash->vector[i]) {
			afisareLista(hash->vector[i]);
		}
	}
}


Hash citireHash(const char* numeFisier,int dim) {
	Hash hash = initHash(dim);
	FILE* f = fopen(numeFisier, "r");
	while (!feof(f)) {
		Masina m = citireMasina(f);
		inserareHash(m, &hash);
	}
	fclose(f);
	return hash;
}

void main(){

	Hash hash = citireHash("masini.txt", 10);
	afisareHash(&hash);

}