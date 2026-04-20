////Cerinte — Lista Dublu Inlantuita
//#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
//
//struct Masina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//
//};
//typedef struct Masina Masina;
//
//struct Nod {
//	struct Nod* prev;
//	struct Nod* next;
//	Masina info;
//};
//typedef struct Nod Nod;
////
////Foloseste structura Masina si fisierul masini.txt.
////
////-- -
////1. Structuri
////
////Defineste :
////-struct StructuraMasina — acelasi ca la LSI
////- struct Nod cu campurile : info(Masina), next(Nod*), prev(Nod*)
////- struct ListaDubla cu campurile : prim(Nod*), ultim(Nod*)
//struct ListaDubla {
//	Nod* prim;
//	Nod* ultim;
//};
//
//
//typedef struct ListaDubla ListaDubla;
////-- -
////2. Citire din fisier
////
////Masina citireMasinaDinFisier(FILE * file)
////Identic cu LSI — fgets + strtok.
//Masina citireMasinaDinFisier(FILE* f) {
//	char buffer[100];
//	char sep[4] = ",\n";
//	fgets(buffer, 100, f);
//
//	char* aux;
//	aux = strtok(buffer, sep);
//	Masina m;
//	m.id = atoi(aux);
//
//	aux = strtok(NULL, sep);
//	m.nrUsi = atoi(aux);
//
//	aux = strtok(NULL, sep);
//	m.pret = atof(aux);
//
//	aux = strtok(NULL, sep);
//	m.model = malloc(strlen(aux) + 1);
//	strcpy(m.model, aux);
//
//	aux = strtok(NULL, sep);
//	m.numeSofer = malloc(strlen(aux) + 1);
//	strcpy(m.numeSofer, aux);
//
//	return m;
//
//}
////-- -
////3. Afisare
////
////void afisareMasina(Masina masina)
//// 
//void afisareMasina(Masina m) {
//	printf("%d %d %5.2f %s %s\n", m.id, m.nrUsi, m.pret, m.model, m.numeSofer);
//}
////void afisareListaInainte(ListaDubla lista)
//void afisareListaInainte(ListaDubla lista) {
//	Nod* p = lista.prim;
//
//	while (p) {
//		afisareMasina(p->info);
//		p = p->next;
//	}
//}
////void afisareListaInapoi(ListaDubla lista)
////Prima parcurge de la prim spre ultim, a doua de la ultim spre prim.
////
////-- -
////4. Adaugare
////
////void adaugaLaSfarsit(ListaDubla * lista, Masina masinaNoua)
//void adaugaLaSfarsit(ListaDubla* lista, Masina m) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = m;
//	nou->next = NULL;
//	nou->prev = lista->ultim;
//	
//
//	if (lista->prim == NULL) {
//		lista->prim = nou;
//
//	}
//	else {
//		lista->ultim->next = nou;
//	}
//	lista->ultim = nou;
//}
////void adaugaLaInceput(ListaDubla * lista, Masina masinaNoua)
////Atentie: seteaza corect ambii pointeri next si prev, si actualizeaza si lista->prim / lista->ultim.
////
////-- -
////5. Citire lista din fisier
////
////ListaDubla citireListaDinFisier(const char* numeFisier)
////Returneaza o ListaDubla cu toate masinile din fisier.Inchide fisierul la final.
//ListaDubla citireListaDinFisier(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//	ListaDubla ld;
//	ld.prim = NULL;
//	ld.ultim = NULL;
//	while (!feof(f)) {
//		Masina m;
//		m = citireMasinaDinFisier(f);
//		adaugaLaSfarsit(&ld,m);
//	}
//	fclose(f);
//	return ld;
//}
////-- -
////6. Dezalocare
////
////void dezalocareListaDubla(ListaDubla * lista)
////Dezalocare nod cu nod inclusiv string - urile.La final seteaza lista->prim = NULL si lista->ultim = NULL.
////
////-- -
////7. Calcul pret mediu
////
////float calculeazaPretMediu(ListaDubla lista)
////Returneaza media preturilor.Daca lista e goala returneaza 0.
////
////-- -
////8. Stergere dupa ID
////
////void stergeMasinaDupaID(ListaDubla * lista, int id)
////Sterge primul nod cu id - ul dat.Atentie la toate cazurile :
////-nodul este singurul din lista
////- nodul este prim
////- nodul este ultim
////- nodul este la mijloc
////
////-- -
////9. Stergere dupa serie
////
////void stergeMasiniDinSeria(ListaDubla * lista, char serie)
////Sterge toate nodurile cu seria data.Acelasi 4 cazuri ca mai sus.
////
////-- -
////10. Cel mai scump sofer
////
////char* getNumeSoferMasinaScumpa(ListaDubla lista)
////Returneaza numele soferului masinii cu pretul cel mai mare.
////
////-- -
////11. Inserare ordonata
////
////void inserareOrdonataDupaPret(ListaDubla * lista, Masina masinaNoua)
////Insereaza masina noua astfel incat lista sa ramana sortata crescator dupa pret.
////
////-- -
////12. Numarare masini sofer
////
////int numaraMasinileUnuiSofer(ListaDubla lista, const char* numeSofer)
////Returneaza numarul de masini conduse de soferul dat.
////
////-- -
////13. Main
////
////In main :
////1. Citeste lista din fisier
////2. Afiseaza lista inainte si inapoi
////3. Afiseaza pretul mediu
////4. Sterge masina cu ID = 3
////5. Afiseaza lista dupa stergere
////6. Afiseaza numele soferului masinii celei mai scumpe
////7. Dezalocare
////
////-- -
////Diferenta cheie fata de LSI : la orice adaugare sau stergere trebuie sa actualizezi 4 pointeri in loc de 2 — nu uita de prev.
//void main() {
//
//	ListaDubla ld = citireListaDinFisier("masini.txt");
//	afisareListaInainte(ld);
//
//}