#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//trebuie sa folositi fisierul masini.txt
//sau va creati un alt fisier cu alte date

struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

void afisareMasina(Masina masina) {
	
	printf("id %d nr usi %d  pret %5.2f  model %s numeSofer %s serie %c\n",masina.id,masina.nrUsi,masina.pret,masina.model,masina.numeSofer,masina.serie);
}

void afisareVectorMasini(Masina* masini, int nrMasini) {
	if (nrMasini == 0) {
		printf("vectorul este gol");
		return;
	}
	for (int i = 0;i < nrMasini;i++) {
		afisareMasina(masini[i]);
	}
}

void adaugaMasinaInVector(Masina** masini, int * nrMasini, Masina masinaNoua) {
	
	Masina* temp = (Masina*)malloc(sizeof(Masina) * ((*nrMasini) + 1));
	for (int i = 0;i < *nrMasini;i++) {
		temp[i] = (*masini)[i];
	}
	temp[*nrMasini] = masinaNoua;
	//(*nrMasini)++;
	//(*masini) = temp;
	//o sa sterg doar zona de memorie in care aveam vectorul, dar nu voi sterge pointerii
	free(*masini);
	(*masini) = temp;//nu mai aloc e deja in heap alocata pentru temp
	(*nrMasini)++;

}

Masina citireMasinaFisier(FILE* file) {
	//functia citeste o masina dintr-un strceam deja deschis
	//masina citita este returnata;
	Masina m;
	
	char linie[100];
	char sep[4] = ",;\n";
	fgets(linie, 99, file);
	m.id = atoi(strtok(linie, sep));
	
	
	m.nrUsi= atoi(strtok(NULL, sep));
	
	m.pret = atof(strtok(NULL, sep));


	
	

	char* aux = (strtok(NULL, sep));
	m.model = (char*)malloc(sizeof(char) * strlen(aux) + 1);
	strcpy(m.model, aux);

	free(aux);

	aux = (strtok(NULL, sep));
	m.numeSofer = (char*)malloc(sizeof(char) * strlen(aux) + 1);
	strcpy(m.numeSofer, aux);
	m.serie = strtok(NULL, sep)[0];

	return m;
}

Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) {
	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
	//prin apelul repetat al functiei citireMasinaFisier()
	//numarul de masini este determinat prin numarul de citiri din fisier
	//ATENTIE - la final inchidem fisierul/stream-ul
	FILE* file = fopen("numeFisier", "r");
	if (!file) {
		printf("eroare la deschidere");
		return;
	}
	else {
		Masina* vectorMasini = NULL;
		while (!feof(file)) {
			Masina masina=citireMasinaFisier(file);
			(*nrMasiniCitite)++;
			adaugaMasinaInVector(&vectorMasini, nrMasiniCitite,masina);
		}
		return vectorMasini;
	}


}

void dezalocareVectorMasini(Masina** vector, int* nrMasini) {
	//este dezalocat intreg vectorul de masini

}

int main() {
	int nrMasini = 0;
	Masina* masini=citireVectorMasiniFisier("masins.txt",&nrMasini);
	afisareVectorMasini(masini, nrMasini);


	return 0;
}