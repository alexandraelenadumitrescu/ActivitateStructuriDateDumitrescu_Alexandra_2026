#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

struct Nod {
	struct Nod* next;
	struct Nod* prev;
	Masina info;
};
typedef struct Nod Nod;

//creare structura pentru Lista Dubla 
struct ListaDubla {
	Nod* prim;
	Nod* ultim;
};

typedef struct ListaDubla ListaDubla;


Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	Masina m1;
	aux = strtok(buffer, sep);
	m1.id = atoi(aux);
	m1.nrUsi = atoi(strtok(NULL, sep));
	m1.pret = atof(strtok(NULL, sep));
	aux = strtok(NULL, sep);
	m1.model = malloc(strlen(aux) + 1);
	strcpy_s(m1.model, strlen(aux) + 1, aux);

	aux = strtok(NULL, sep);
	m1.numeSofer = malloc(strlen(aux) + 1);
	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);

	m1.serie = *strtok(NULL, sep);
	return m1;
}

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);
}

void afisareListaMasini(ListaDubla listaDubla) {
	
	Nod* aux = listaDubla.prim;
	while (aux) {
		afisareMasina(aux->info);
		aux = aux->next;
	}

}

void afisareListaMasiniInvers(ListaDubla listaDubla) {

	Nod* aux = listaDubla.ultim;
	while (aux) {
		afisareMasina(aux->info);
		aux = aux->prev;
	}

}


void adaugaMasinaInLista(ListaDubla* listaDubla,Masina masinaNoua) {
	//adauga la final in lista primita o noua masina pe care o primim ca parametru
	Nod* nou = (Nod*)malloc(sizeof(Nod));

	nou->info = masinaNoua;
	nou->next = NULL;
	nou->prev = listaDubla->ultim;

	if (listaDubla->ultim != NULL) {
		listaDubla->ultim->next = nou;
	}
	else {
		listaDubla->prim = nou;
	}

	listaDubla->ultim = nou;
	}

void adaugaLaInceputInLista(ListaDubla* listaDubla,Masina masinaNoua) {
	//adauga la inceputul listei dublu inlantuite o noua masina pe care o primim ca parametru
	Nod* nou = (Nod*)malloc(sizeof(Nod));

	nou->info = masinaNoua;
	nou->next = listaDubla->prim;
	nou->prev = NULL;


	if (listaDubla->ultim != NULL) {
		listaDubla->ultim->next = nou;
	}
	else {
		listaDubla->prim = nou;
	}

	listaDubla->ultim = nou;
}

ListaDubla citireLDMasiniDinFisier(const char* numeFisier) {
	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
	//prin apelul repetat al functiei citireMasinaDinFisier()
	//ATENTIE - la final inchidem fisierul/stream-ul
	FILE* f = fopen(numeFisier, "r");
	ListaDubla listaDubla;
	listaDubla.prim = NULL;
	listaDubla.ultim = NULL;
	while (!feof(f)) {
		adaugaMasinaInLista(&listaDubla, citireMasinaDinFisier(f));//datorita sc nu trebuie dezalocat
	}
	fclose(f);
	return listaDubla;
}

void dezalocareLDMasini(ListaDubla* lista) {
	//sunt dezalocate toate masinile si lista dublu inlantuita de elemente
	Nod* p = lista->prim;
	while (p) {
		Nod* aux = p;
		p = p->next;
		if (aux->info.model) {
			free(aux->info.model);
		}
		if (aux->info.numeSofer) {
			free(aux->info.numeSofer);
		}
		free(aux);
	}
	lista->prim = NULL;
	lista->ultim = NULL;
	
}

float calculeazaPretMediu(ListaDubla listaDubla) {
	Nod* p = listaDubla.prim;
	float suma = 0;
	int nr = 0;
	while (p) {
		nr++;
		suma += p->info.pret;
		p = p->next;
	}
	if (nr != 0) {
		return suma / nr;
	}
	return 0;
	
}

void stergeMasinaDupaID(/*lista masini*/ int id) {
	//sterge masina cu id-ul primit.
	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
}

char* getNumeSoferMasinaScumpa(/*lista dublu inlantuita*/) {
	//cauta masina cea mai scumpa si 
	//returneaza numele soferului acestei maasini.
	return NULL;
}

int main() {
	ListaDubla listaDubla = citireLDMasiniDinFisier("masini.txt");
	afisareListaMasini(listaDubla);
	dezalocareLDMasini(&listaDubla);
	printf("afisare lista dubla de masini dupa dezalocare\n");
	afisareListaMasini(listaDubla);
	return 0;
}