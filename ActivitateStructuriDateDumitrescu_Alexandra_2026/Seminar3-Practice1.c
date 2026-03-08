#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//The Project Requirements
//Write a program that manages a collection of Books using data
// loaded from an external text file.
struct Carte {
	char* titlu;
	char* autor;
	int an;
	float pret;
};
typedef struct Carte Carte;
//
//Define a Data Structure : Create a Book structure(or class) 
// with the following attributes :
//
//Title(String)
//
//Author(String)
//
//Year of Publication(Integer)
//
//Price(Double / Float)
//
//File Input : Read the book data from a file named library_data.txt.
// The first line of the file contains the total number of books.
Carte citireCarteDinFisier(FILE* f) {
	Carte c;
	char linie[100];
	char sep[5] = ",; \n";
	fgets(linie, 99, f);

	char* aux = strtok(linie, sep);
	c.autor = (char*)malloc(sizeof(char) * strlen(aux) + 1);
	strcpy(c.autor, aux);

	aux = strtok(NULL, sep);
	c.titlu = (char*)malloc(sizeof(char) * strlen(aux) + 1);
	strcpy(c.titlu, aux);

	c.an = atoi(strtok(NULL, sep));

	c.pret = atof(strtok(NULL, sep));

	return c;


}
void adauga(Carte c, Carte** vector, int* nrCarti) {
	Carte* aux = (Carte*)malloc(sizeof(Carte) * ((*nrCarti) + 1));
	for (int i = 0;i < (*nrCarti);i++) {
		aux[i] = (*vector)[i];
	}
	aux[*nrCarti] = c;
	free(*vector);
	(*nrCarti)++;
	(*vector) = aux;
}
Carte* citireVector(const char* caleFisier,int* nrCartiCitite) {
	FILE* f= fopen(caleFisier, "r");
	if (!f) {
		printf("eroare");
		return;
	}
	else {
		Carte* mi = NULL;
		while (!feof(f)) {
			Carte c = citireCarteDinFisier(f);
			adauga(c, &mi, nrCartiCitite);

		}
		return mi;
	}
	fclose(f);
}


void afisare(Carte c) {
	
	printf("%s %s %d %5.2f\n", c.titlu, c.autor, c.an, c.pret);
}
void afisareVector(Carte* carti, int size) {
	for (int i = 0;i < size;i++) {
		afisare(carti[i]);
	}
}
//Data Storage : Store these objects in a dynamically allocated array or a list.
//
//Processing Logic :
//
//Display all books currently in the system.
//
//Calculate and display the total value of the entire library inventory.
//
//Find and display the oldest book in the collection.
//
//Memory Management : Ensure all allocated memory is properly 
// freed before the program exits.
void dezalocare(Carte** vector, int* nr) {
	for (int i = 0;i < (*nr);i++) {
		free((*vector)[i].titlu);
		free((*vector)[i].autor);
	}
	free(*vector);
	*vector = NULL;
	*nr = 0;
}

int main() {
	int nr = 0;
	Carte* carti = citireVector("library_data.txt", &nr);
	afisareVector(carti, nr);
	dezalocare(&carti, &nr);


	return 0;
}