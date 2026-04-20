//Cerinte — Lista Simplu Inlantuita
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include <string.h>

struct Masina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;

};
typedef struct Masina Masina;

struct Nod {
	Masina info;
	struct Nod* next;
};



typedef struct Nod Nod;


//Foloseste structura Masina si fisierul masini.txt din proiect.                                                                                                                                                                                                                                                                                          -- - 1. Structuri
//
//Defineste :
//-struct StructuraMasina cu campurile : id(int), nrUsi(int), pret(float), model(char*), numeSofer(char*), serie(unsigned char)
//- struct Nod cu campurile : info(Masina), next(Nod*)
//
// 
//-- -
//2. Citire din fisier
//
//Masina citireMasinaDinFisier(FILE * file)
//Citeste o singura masina dintr - o linie din fisier folosind fgets si strtok.
//
Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100,file);
	char* aux;
	Masina m;
	aux = strtok(buffer, sep);
	m.id = atoi(aux);
	m.nrUsi = atoi(strtok(NULL, sep));
	m.pret = atof(strtok(NULL, sep));

	aux = strtok(NULL, sep);
	m.model = malloc(strlen(aux) + 1);
	strcpy(m.model, aux);

	aux = strtok(NULL, sep);
	m.numeSofer = malloc(strlen(aux) + 1);
	strcpy(m.numeSofer, aux);

	return m;
}
//-- -
//3. Afisare
//
//void afisareMasina(Masina masina)
// 
void afisareMasina(Masina m) {
	printf("%d %d %5.2f %s %s \n", m.id, m.nrUsi, m.pret, m.model, m.numeSofer);
}
//void afisareListaMasini(Nod * cap)
//
void afisareListaMasini(Nod* cap) {
	
	while (cap) {
		afisareMasina(cap->info);
		cap = cap->next;
	}
	
}
//-- -
//4. Adaugare
//
//void adaugaLaSfarsit(Nod * *cap, Masina masinaNoua)
void adaugaLaSfarsit(Nod** cap, Masina noua) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = noua;
	nou->next = NULL;
	if (*cap) {
		Nod* temp = *cap;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = nou;
	}
	else {
		*cap = nou;
	}
}
//void adaugaLaInceput(Nod * *cap, Masina masinaNoua)
//
void adaugaLaInceput(Nod** cap, Masina nou) {
	Nod* hai = (Nod*)malloc(sizeof(Nod));
	hai->info = nou;
	hai->next = *cap;
	*cap = hai;

}
//-- -
//5. Citire lista din fisier
//
//Nod * citireListaMasiniDinFisier(const char* numeFisier)
//Deschide fisierul, citeste toate masinile prin apeluri repetate ale functiei de la punctul 2 si le adauga in lista.Inchide fisierul la final.
//
Nod* citireListaMasiniDinFisier(const char* numeFisier) {
	FILE* f = fopen(numeFisier, "r");
	Nod* cap = NULL;
	while (!feof(f)) {
		Masina m = citireMasinaDinFisier(f);
		adaugaLaSfarsit(&cap,m);
	}
	fclose(f);
	return cap;
}
Nod* citireListaMasiniDinFisier2(const char* numeFisier) {
	FILE* f = fopen(numeFisier, "r");
	Nod* cap = NULL;
	while (!feof(f)) {
		Masina m = citireMasinaDinFisier(f);
		adaugaLaInceput(&cap, m);
	}
	fclose(f);
	return cap;
}
//-- -
//6. Dezalocare
//
//void dezalocareListaMasini(Nod * *cap)
//Dezalocare nod cu nod(inclusiv string - urile din fiecare Masina).La final pune * cap = NULL.
//
//-- -
//7. Calcul pret mediu
//
//float calculeazaPretMediu(Nod * cap)
//Returneaza media preturilor tuturor masinilor din lista.Daca lista e goala returneaza 0.
//
//-- -
//8. Stergere dupa serie
//
//void stergeMasiniDinSeria(Nod * *cap, char serieCautata)
//Sterge din lista toate nodurile care au seria egala cu serieCautata.Atentie la cazul in care nodul de sters este chiar capul listei.
//
//-- -
//9. Calcul pret sofer
//
//float calculeazaPretulMasinilorUnuiSofer(Nod * cap, const char* numeSofer)
//Returneaza suma preturilor tuturor masinilor conduse de soferul cu numele dat.
//
//-- -
//10. Cautare dupa ID
//
//Masina * getMasinaDupaId(Nod * cap, int id)
//Returneaza un pointer catre masina cu id - ul dat, sau NULL daca nu exista.
//
//-- -
//11. Numarare
//
//int numaraMasiniCuPretPeste(Nod * cap, float prag)
//Returneaza numarul de masini cu pretul strict mai mare decat prag.
//
//-- -
//12. Main
//
//In main :
//1. Citeste lista din fisier
//2. Afiseaza lista
//3. Afiseaza pretul mediu
//4. Sterge masinile din seria 'B'
//5. Afiseaza lista dupa stergere
//6. Dezalocare
//
//-- -
//Ordinea recomandata de implementare : 1 → 2 → 3 → 4 → 5 → 6 → 12 (testezi), apoi 7 → 8 → 9 → 10 → 11.

void main() {

	Nod* cap = citireListaMasiniDinFisier("masini.txt");
	afisareListaMasini(cap);

	Nod* cap2 = citireListaMasiniDinFisier2("masini.txt");
	afisareListaMasini(cap2);






}