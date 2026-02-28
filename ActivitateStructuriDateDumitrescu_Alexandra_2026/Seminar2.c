#include<stdio.h>
#include<malloc.h>

struct Telefon {
	int id;
	int RAM;
	char* producator;
	float pret;
	char serie;
};
struct Telefon initializare(int id, int RAM, char* producator, float pret, char serie) {
	struct Telefon s;
	s.id = id;
	s.RAM = RAM;
	s.producator = (char*)malloc(sizeof(char) * strlen(producator) + 1);
	strcpy(s.producator, producator);
	s.pret = pret;
	s.serie = serie;
	
	return s;
}

struct Telefon copiaza(struct Telefon t) {
	struct Telefon telefon= initializare(t.id, t.RAM, t.producator, t.pret, t.serie);
	return telefon;
}

void afisare(struct Telefon s) {
	printf("%d %d %s %5.2f %c\n", s.id, s.RAM, s.producator, s.pret, s.serie);
}

void afisareVector(struct Telefon* vector, int nrElemente) {
	for (int i = 0;i < nrElemente;i++) {
		afisare(vector[i]);
	}
}

struct Telefon* copiazaPrimeleNElemente(struct Telefon* vector, int nrElemente, int nrElementeCopiate) {
	//copiem intr-un vector nou pe care il vom returna primele nrElementeCopiate
	struct Telefon* vectorNou=(struct Telefon*)malloc(sizeof(struct Telefon)*nrElementeCopiate);
	for (int i = 0;i < nrElementeCopiate;i++) {
		vectorNou[i] = copiaza(vector[i]);
	}
	return vectorNou;
}

void dezalocare(struct Telefon** vector, int* nrElemente) {
	for (int i = 0;i < *nrElemente;i++) {
		free((*vector)[i].producator);
		(*vector)[i].producator = NULL;
	}
	free(*vector);
	*vector = NULL;
	//dezalocam elementele din vector si vectorul
}

void copiazaAnumiteElemente(struct Telefon* vector, char nrElemente, float prag, struct Telefon** vectorNou, int* dimensiune) {
	//parametrul prag poate fi modificat in functie de 
	// tipul atributului ales pentru a indeplini o conditie
	//este creat un nou vector cu elementele care indeplinesc acea conditie
	int count = 0;
	for (int i = 0;i < nrElemente;i++) {
		if (prag > vector[i].pret) {
			count++;
		}
	}
	(*vectorNou) = (struct Telefon*)malloc(sizeof(struct Telefon) * count);
	int j = 0;
	for (int i = 0;i < nrElemente;i++) {
		if (prag > (*vectorNou)[i].pret) {
			(*vectorNou)[j] = copiaza(vector[i]);
			j++;
		}
	}
	*dimensiune = j;
	
}

struct Telefon getPrimulElementConditionat(struct Telefon* vector, int nrElemente, const char* conditie) {
	//trebuie cautat elementul care indeplineste o conditie
	//dupa atributul de tip char*. Acesta este returnat.
	struct Telefon s;
	s.id = 1;

	return s;
}
	


int main() {
	struct Telefon t1 = initializare(10, 10, "samsung", 100, 's');
	afisare(t1);
	int size = 3;
	struct Telefon* telefoane = (struct Telefon*)malloc(sizeof(struct Telefon) * size);
	telefoane[0] = t1;
	telefoane[1] = initializare(10, 10, "samsung", 300, 's');
	telefoane[2] = initializare(10, 10, "samsung", 200, 's');
	afisareVector(telefoane, size);



	return 0;
}