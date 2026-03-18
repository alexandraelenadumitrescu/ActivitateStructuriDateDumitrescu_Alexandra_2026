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
////creare structura pentru un nod dintr-o lista simplu inlantuita
//typedef struct Nod Nod;
//
//struct Nod {
//	Masina info;
//	Nod* next;
//};
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
//void afisareListaMasini(Nod* cap) {
//	while (cap != NULL) {
//		afisareMasina(cap->info);
//		cap = cap->next;
//	}
//}
//
//void adaugaMasinaInLista(Nod** cap, Masina masinaNoua) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = masinaNoua;
//	nou->next = NULL;
//	if (*cap) {
//		Nod* aux = *cap;
//		while (aux->next) {
//			//*cap = (*cap)->next; nu asa pentru ca il pierd
//			aux = aux->next;
//		}
//		aux->next = nou;
//	}
//	else {
//		*cap = nou;
//	}
//	//adauga la final in lista primita o noua masina pe care o primim ca parametru
//}
//
//void adaugaLaInceputInLista(Nod** cap, Masina masinaNoua) {
//	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
//	nodNou->info = masinaNoua;
//	nodNou->next = *cap;
//	*cap = nodNou;
//	//adauga la inceputul listei o noua masina pe care o primim ca parametru
//}
//
//void* citireListaMasiniDinFisier(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//	Nod* cap = NULL;
//	if (f) {
//		
//		while (!feof(f)) {
//			adaugaMasinaInLista(&cap, citireMasinaDinFisier(f));
//
//		}
//
//		fclose(f);
//	}
//	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
//	//prin apelul repetat al functiei citireMasinaDinFisier()
//	//ATENTIE - la final inchidem fisierul/stream-ul
//	return cap;
//}
//
//void dezalocareListaMasini(Nod** cap) {
//	while (*cap) {
//		Nod* p = *cap;
//		*cap = p->next;
//		if (p->info.numeSofer) {
//			free(p->info.numeSofer);
//		}
//		if (p->info.model) {
//			free(p->info.model);
//		}
//		free(p);
//
//	}
//	//sunt dezalocate toate masinile si lista de elemente
//}
//
//float calculeazaPretMediu(Nod* cap) {
//	float total=0;
//	int count=0;
//	while (cap) {
//		total += cap->info.pret;
//		count++;
//		cap = cap->next;
//		if (total > 0) {
//			return total / count;
//		}
//	}
//	
//	return 0;
//}
//
//void stergeMasiniDinSeria(Nod** cap,char serieCautata) {
//	//sterge toate masinile din lista care au seria primita ca parametru.
//	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
//	//de incercat fara primul while
//		while ((*cap) && (*cap)->info.serie == serieCautata) {
//			Nod* temp = *cap;
//			(*cap) = temp->next;
//
//			if (temp->info.numeSofer) {
//				free(temp->info.numeSofer);
//			}
//			if (temp->info.model) {
//				free(temp->info.model);
//			}
//		}
//		/*if (*cap) {
//			Nod* aux = *cap;
//			while (aux) {
//				while (aux->next && aux->info.serie != serieCautata) {
//					aux = aux->next;
//				}
//			}
//
//		}*/
//		Nod* p = *cap;
//		while (p) {
//			while ((*p).next && (*p).next->info.serie != serieCautata) {
//				p = p->next;
//			}
//			Nod* temp = p->next;
//			if (p->next) {
//				p->next = temp->next;
//
//				if (temp->info.model) {
//					free(temp->info.model);
//				}
//				if (temp->info.numeSofer) {
//					free(temp->info.numeSofer);
//				}
//				free(temp);
//			}
//			else {
//				p = p->next;
//			}
//		}
//}
//
//float calculeazaPretulMasinilorUnuiSofer(/*lista masini*/ const char* numeSofer) {
//	//calculeaza pretul tuturor masinilor unui sofer.
//	return 0;
//}
//
//int main() {
//	Nod* cap = NULL;
//	cap = citireListaMasiniDinFisier("masini.txt");
//	afisareListaMasini(cap);
//
//	//printf(" % 5.2f\n", calculeazaPretMediu(cap));
//	
//	stergeMasiniDinSeria(&cap, 'A');
//	printf("lista dupa stergere\n");
//	afisareListaMasini(cap);
//	dezalocareListaMasini(&cap);
//	printf("lista dupa dezalocare\n");
//	afisareListaMasini(cap);
//
//	return 0;
//}