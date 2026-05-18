//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct StructuraCarte {
//	int id;
//	int anPublicare;
//	float pret;
//	char* titlu;
//	char* numeAutor;
//	unsigned char editie;
//};
//typedef struct StructuraCarte Carte;
//typedef struct Nod Nod;
//struct Nod {
//	Carte info;
//	Nod* st;
//	Nod* dr;
//};
//
//Carte citireCarteDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Carte c1;
//	aux = strtok(buffer, sep);
//	c1.id = atoi(aux);
//	c1.anPublicare = atoi(strtok(NULL, sep));
//	c1.pret = atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	c1.titlu = malloc(strlen(aux) + 1);
//	strcpy_s(c1.titlu, strlen(aux) + 1, aux);
//
//	aux = strtok(NULL, sep);
//	c1.numeAutor = malloc(strlen(aux) + 1);
//	strcpy_s(c1.numeAutor, strlen(aux) + 1, aux);
//
//	c1.editie = *strtok(NULL, sep);
//	return c1;
//}
//
//void afisareCarte(Carte carte) {
//	printf("Id: %d\n", carte.id);
//	printf("An publicare : %d\n", carte.anPublicare);
//	printf("Pret: %.2f\n", carte.pret);
//	printf("Titlu: %s\n", carte.titlu);
//	printf("Nume autor: %s\n", carte.numeAutor);
//	printf("Editie: %c\n\n", carte.editie);
//}
//
//int calculeazaInaltimeArbore(Nod* radacina) {
//	if (radacina != NULL) {
//		int inaltimeSt = calculeazaInaltimeArbore(radacina->st);
//		int inaltimeDr = calculeazaInaltimeArbore(radacina->dr);
//
//		return 1 + (inaltimeSt > inaltimeDr ? inaltimeSt : inaltimeDr);
//	}
//	else {
//		return 0;
//	}
//}
//
//void rotireStanga(Nod** radacina) {
//	Nod* nod;
//
//	nod = (*radacina)->dr;
//	(*radacina)->dr = nod->st;
//	nod->st = *radacina;
//	*radacina = nod;
//}
//
//void rotireDreapta(Nod** radacina) {
//	Nod* aux;
//	aux = (*radacina)->st;
//	(*radacina)->st = aux->dr;
//	aux->dr = (*radacina);
//	*radacina = aux;
//}
//
//int gradEchilibru(Nod* radacina) {
//	if (radacina != NULL) {
//		return(calculeazaInaltimeArbore(radacina->st) - calculeazaInaltimeArbore(radacina->dr));
//	}
//	else {
//		return 0;
//	}
//}
//
//void adaugaCarteInArboreEchilibrat(Nod** radacina, Carte carteNoua) {
//	if ((*radacina) != NULL) {
//		if ((*radacina)->info.id > carteNoua.id) {
//			adaugaCarteInArboreEchilibrat(&((*radacina)->st), carteNoua);
//		}
//		else {
//			adaugaCarteInArboreEchilibrat(&((*radacina)->dr), carteNoua);
//		}
//		int grad = gradEchilibru((*radacina));
//		if (grad == 2) {
//			if (gradEchilibru((*radacina)->st) == 1) {
//				rotireDreapta(radacina);
//			}
//			else {
//				rotireStanga(&((*radacina)->st));
//				rotireDreapta(radacina);
//			}
//		}
//		else if (grad == -2) {
//			if (gradEchilibru((*radacina)->dr) == 1) {
//				rotireDreapta(&((*radacina)->dr));
//			}
//			rotireStanga(radacina);
//		}
//	}
//	else {
//		Nod* nod = (Nod*)malloc(sizeof(Nod));
//		nod->info = carteNoua;
//		nod->dr = NULL;
//		nod->st = NULL;
//		(*radacina) = nod;
//	}
//}
//
//Nod* citireArboreDeCartiDinFisier(const char* numeFisier) {
//	FILE* file = fopen(numeFisier, "r");
//	Nod* radacina = NULL;
//	while (!feof(file)) {
//		Carte c = citireCarteDinFisier(file);
//		adaugaCarteInArboreEchilibrat(&radacina, c);
//	}
//	fclose(file);
//	return radacina;
//}
//
//void afisareArborePreOrdine(Nod* radacina) {
//	if (radacina != NULL) {
//		afisareCarte(radacina->info);
//		afisareArborePreOrdine(radacina->st);
//		afisareArborePreOrdine(radacina->dr);
//	}
//}
//
//void dezalocareArboreDeCarti(Nod** radacina) {
//	if ((*radacina) != NULL) {
//		dezalocareArboreDeCarti(&((*radacina)->st));
//		dezalocareArboreDeCarti(&((*radacina)->dr));
//		free((*radacina)->info.titlu);
//		free((*radacina)->info.numeAutor);
//		free(*radacina);
//		*radacina = NULL;
//	}
//}
//
//Carte getCarteByID(Nod* radacina, int id) {
//	Carte c;
//	c.id = -1;
//	if (id > radacina->info.id) {
//		return getCarteByID(radacina->dr, id);
//	}
//	else if (id < radacina->info.id) {
//		return getCarteByID(radacina->st, id);
//	}
//	else {
//		c = radacina->info;
//		c.numeAutor = (char*)malloc(strlen(radacina->info.numeAutor) + 1);
//		strcpy(c.numeAutor, radacina->info.numeAutor);
//
//		c.titlu = (char*)malloc(strlen(radacina->info.titlu) + 1);
//		strcpy(c.titlu, radacina->info.titlu);
//		return c;
//	}
//	return c;
//}
//
//int determinaNumarNoduri(Nod* radacina) {
//	if (radacina != NULL) {
//		return 1 + determinaNumarNoduri(radacina->st) + determinaNumarNoduri(radacina->dr);
//	}
//	else {
//		return 0;
//	}
//}
//
//float calculeazaPretTotal(Nod* radacina) {
//	if (radacina != NULL) {
//		float pretSubarboreStang = calculeazaPretTotal(radacina->st);
//		float pretSubarboreDrept = calculeazaPretTotal(radacina->dr);
//		float pretTotal = pretSubarboreStang + pretSubarboreDrept + radacina->info.pret;
//		return pretTotal;
//	}
//	else {
//		return 0;
//	}
//}
//
//int main() {
//	Nod* arbore = citireArboreDeCartiDinFisier("books_trees.txt");
//	afisareArborePreOrdine(arbore);
//	printf("Pretul total al cartilor: %.2f", calculeazaPretTotal(arbore));
//	return 0;
//}