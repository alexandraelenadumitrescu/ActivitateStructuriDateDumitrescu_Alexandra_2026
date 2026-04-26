//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////trebuie sa folositi fisierul masini.txt
////sau va creati un alt fisier cu alte date
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//
////creare structura pentru un nod dintr-un arbore binar de cautare
//
//struct Nod {
//	struct Nod* stg;
//	struct Nod* drp;
//	Masina info;
//};
//typedef struct Nod Nod;
//
//Masina citireMasinaDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Masina m1;
//	aux = strtok(buffer, sep);
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret= atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	m1.model = malloc(strlen(aux) + 1);
//	strcpy_s(m1.model, strlen(aux) + 1, aux);
//
//	aux = strtok(NULL, sep);
//	m1.numeSofer = malloc(strlen(aux) + 1);
//	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//
//	m1.serie = *strtok(NULL, sep);
//	return m1;
//}
//
//void afisareMasina(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//
//void adaugaMasinaInArbore(Nod** radacina, Masina masinaNoua) {
//	//adauga o noua masina pe care o primim ca parametru in arbore,
//	//astfel incat sa respecte princiippile de arbore binar de cautare
//	//dupa o anumita cheie pe care o decideti - poate fi ID
//	if (*radacina) {
//		if ((*radacina)->info.id < masinaNoua.id) {
//			adaugaMasinaInArbore(&(*radacina)->drp, masinaNoua);
//		}
//		else {
//			adaugaMasinaInArbore(&(*radacina)->stg, masinaNoua);
//		}
//	}
//	else {
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->info = masinaNoua;
//		nou->stg = NULL;
//		nou->drp = NULL;
//		*radacina = nou;
//	}
//}
//
//Nod* citireArboreDeMasiniDinFisier(const char* numeFisier) {
//	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
//	//prin apelul repetat al functiei citireMasinaDinFisier()
//	//ATENTIE - la final inchidem fisierul/stream-ul
//	FILE* f = fopen(numeFisier, "r");
//
//	Nod* radacina = NULL;
//
//	while (!feof(f)) {
//		adaugaMasinaInArbore(&radacina, citireMasinaDinFisier(f));
//	}
//	fclose(f);
//	return radacina;
//
//}
//
//void afisareMasiniDinArbore(Nod* radacina) {
//	//afiseaza toate elemente de tip masina din arborele creat
//	//prin apelarea functiei afisareMasina()
//	//parcurgerea arborelui poate fi realizata in TREI moduri
//	//folositi toate cele TREI moduri de parcurgere
//	
//	
//	if (radacina) {
//		afisareMasina(radacina->info);
//		afisareMasiniDinArbore(radacina->stg);
//		afisareMasiniDinArbore(radacina->drp);
//	}
//
//}
//
//void dezalocareArboreDeMasini(Nod** radacina) {
//	//sunt dezalocate toate masinile si arborele de elemente
//	while (*radacina) {
//		dezalocareArboreDeMasini(&(*radacina)->stg);
//		dezalocareArboreDeMasini(&(*radacina)->drp);
//		free((*radacina)->info.model);
//		free((*radacina)->info.numeSofer);
//		free(*radacina);
//		*radacina = NULL;
//	}
//}
//
//Masina getMasinaByID(Nod* radacina,int id) {
//	Masina m;
//	if (radacina) {
//		if (radacina->info.id == id) {
//			return radacina->info;
//		}
//		if (radacina->info.id > id) {
//			return getMasinaByID(radacina->stg, id);
//		}
//		else {
//			return getMasinaByID(radacina->drp, id);
//		}
//	}
//	else {
//		m.id = -1;
//		
//	}
//	return m;
//}
//
//int determinaNumarNoduri(Nod* radacina) {
//	//calculeaza numarul total de noduri din arborele binar de cautare
//	if (radacina) {
//		return determinaNumarNoduri(radacina->stg) + determinaNumarNoduri(radacina->drp) + 1;	
//	}
//	return 0;
//}
//
//int calculeazaInaltimeArbore(Nod* radacina) {
//	//calculeaza inaltimea arborelui care este data de 
//	//lungimea maxima de la radacina pana la cel mai indepartat nod frunza
//	if (radacina) {
//		int inaltimeStanga = calculeazaInaltimeArbore(radacina->stg);
//		int inaltimeDreapta = calculeazaInaltimeArbore(radacina->drp);
//
//		return inaltimeStanga> inaltimeDreapta? inaltimeStanga + 1: inaltimeDreapta+1;
//	}
//	return 0;
//}
//
//float calculeazaPretTotal(Nod* radacina) {
//	//calculeaza pretul tuturor masinilor din arbore.
//	if (radacina) {
//		return calculeazaPretTotal(radacina->stg) + calculeazaPretTotal(radacina->drp) + radacina->info.pret;
//	}
//	return 0;
//}
//
//float calculeazaPretulMasinilorUnuiSofer(Nod* radacina, const char* numeSofer) {
//	//calculeaza pretul tuturor masinilor unui sofer.
//	float s = 0;
//	if (radacina) {
//		s+=calculeazaPretulMasinilorUnuiSofer(radacina->stg,numeSofer);
//		s+=calculeazaPretulMasinilorUnuiSofer(radacina->drp, numeSofer);
//		if (strcmp(radacina->info.numeSofer, numeSofer) == 0) {
//			s += radacina->info.pret;
//		}
//	}
//	return s;
//}
//
//int main() {
//
//	Nod* radacina = citireArboreDeMasiniDinFisier("masini.txt");
//	afisareMasiniDinArbore(radacina);
//
//	afisareMasina(getMasinaByID(radacina, 5));
//
//	printf("%5.2f\n pret total", calculeazaPretTotal(radacina));
//	printf("%5.2f\n pret total", calculeazaPretulMasinilorUnuiSofer(radacina,"Ionescu"));
//
//	dezalocareArboreDeMasini(&radacina);
//	afisareMasiniDinArbore(radacina);
//	
//
//
//
//	return 0;
//}