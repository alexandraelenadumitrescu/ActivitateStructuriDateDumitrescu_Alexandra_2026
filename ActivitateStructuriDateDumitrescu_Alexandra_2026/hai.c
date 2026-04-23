////#include<stdio.h>
////#include<stdlib.h>
////#include<malloc.h>
////#include<string.h>
////
////
////
//////Implementați o aplicație în limbajul C ce rezolvă probleme de gestionare a cărților 
////// dintr - o bibliotecă.
//////
//////Definiți structura Carte ce conține : titlu(char*), an apariție(int), pret(float).
////struct Carte {
////	char* titlu;
////	int an;
////	float pret;
////};
////typedef struct Carte Carte;
////
////struct Nod {
////	struct Nod* next;
////	Carte info;
////};
////typedef struct Nod Nod;
////
////// Definiți structurile necesare pentru lucru cu listă simplu înlănțuită. (1p)
//////Implementați funcția de inserare a unei Cărți într - o Listă simplu înlănțuită. (1p)
////void inserare(Nod** cap, Carte c) {
////	Nod* aux = *cap;
////
////	Nod* nou = (Nod*)malloc(sizeof(Nod));
////	nou->info = c;
////	nou->next = NULL;
////
////	if (*cap == NULL) {
////		*cap = nou;
////		return;
////	}
////	while (aux->next) {
////		aux = aux->next;
////	}
////	aux->next = nou;
////}
//////Creați o listă cu cel puțin 5 elemente de tip Carte, apelând funcția de inserare.
////// Informațiile pentru cele 5 obiecte de tip Carte le citiți dintr - un fișier text. (1p)
////Carte citire(FILE* f) {
////	char buffer[100];
////	char sep[4] = ",\n";
////
////	fgets(buffer, 100, f);
////
////	char* aux = strtok(buffer, sep);
////	Carte c;
////	c.titlu = (char*)malloc(strlen(aux) + 1);
////	strcpy(c.titlu, aux);
////
////	aux = strtok(NULL, sep);
////	c.an = atoi(aux);
////
////	aux = strtok(NULL, sep);
////	c.pret = atof(aux);
////
////	return c;
////}
////
////Nod* create(const char* numeFisier) {
////	FILE* f = fopen(numeFisier, "r");
////	Nod* nou=NULL;
////	while (!feof(f)) {
////		inserare(&nou, citire(f));
////	}
////	return nou;
////}
////
////void afisare(Carte c) {
////	printf("%s %d %5.2f\n", c.titlu, c.an, c.pret);
////}
////
////void af(Nod* cap) {
////	Nod* aux = cap;
////	while (aux) {
////		afisare(aux->info);
////		aux = aux->next;
////	}
////
////}
//////Implementați o funcție de traversare a structurii listă simplu înlănțuită.Vor fi afișate 
////// în consolă toate datele asociate structurii Carte. (1p)
////// 
////// 
////// DONE
//////Implementați funcția care returnează titlul cărții cu prețul maxim dintr - o listă simplu
////// înlănțuită primită ca parametru.Rezultatul apelului se validează prin apelul funcției și 
////// afișarea rezultatului în funcția principală. (2p)
////char* titluPretMaxim(Nod* cap) {
////	Nod* aux = cap;
////	char* cautat = NULL;
////	float max = aux->info.pret;
////
////	while (aux) {
////		if (aux->info.pret > max) {
////			max = aux->info.pret;
////			if (cautat != NULL) {
////				free(cautat);
////
////			}
////			cautat = (char*)malloc(strlen(aux->info.titlu));
////			strcpy(cautat, aux->info.titlu);
////
////		}
////		aux = aux->next;
////	}
////	return cautat;
////}
//////Implementați funcția care caută și returnează(deep copy) o Carte din lista simplu înlănțuită,
////// primind titlul acesteia.Dacă sunt mai multe, o va returna pe prima.Apelați funcția în main(). (2p)
////Carte deep(Carte c) {
////	Carte nou;
////	nou.pret = c.pret;
////	nou.an = c.an;
////	nou.titlu = (char*)malloc(strlen(c.titlu) + 1);
////	strcpy(nou.titlu, c.titlu);
////	return nou;
////}
////
////Carte prinTitlu(char* titlu,Nod* cap) {
////	Nod* aux = cap;
////	
////
////	while (aux) {
////		if (strcmp(aux->info.titlu, titlu) == 0) {
////			return deep(aux->info);
////		}
////		aux = aux->next;
////	}
////	Carte x;
////	x.an = 0;
////	x.titlu = NULL;
////	x.pret = 0;
////	return x;
////
////}
//////Trebuie să eliberați toată memoria alocată în HEAP.
////
////void dezalocare(Nod** cap) {
////	Nod* aux = *cap;
////	while (aux) {
////		Nod* temp = aux;
////		aux = aux->next;
////		free(temp->info.titlu);
////		free(temp);
////	}
////	*cap = NULL;
////
////}
////
////void main() {
////	Nod* cap = create("hai.txt");
////	af(cap);
////	printf("%s\n", titluPretMaxim(cap));
//	afisare(prinTitlu("carte1", cap));
//	dezalocare(&cap);
//	af(cap);
//}