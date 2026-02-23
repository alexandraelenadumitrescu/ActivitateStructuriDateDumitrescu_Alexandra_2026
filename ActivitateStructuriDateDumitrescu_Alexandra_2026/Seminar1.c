#include<stdio.h>
#include<stdlib.h>

struct Student {
	int id;
	int grupa;
	char* nume;
	float medie;
	char initiala;
};

struct Student initializare(int id, int grupa, char* nume, float medie, char initiala) {
	struct Student s;
	s.id = id;
	s.grupa = 1000;
	s.nume = (char*)malloc(sizeof(char) * strlen(nume) + 1);
	strcpy(s.nume, nume);
	s.medie = medie;
	s.initiala = initiala;
	//initializare structura 
	return s;
}

void afisare(struct Student s) {
	//afisarea tuturor atributelor.
	printf("%d. %s(%c) din grupa %d are media %5.2f ", s.id, s.nume, s.initiala, s.grupa, s.medie);
}

void modifica_Nume(struct Student* s, char* noulNume) {
	if (strlen(noulNume) > 2) {
		free(s->nume);
		(*s).nume = (char*)malloc(sizeof(char) * strlen(noulNume) + 1);
		strcpy(s->nume, noulNume);
	}

}

char* comparaStudenti(struct Student s1, struct Student s2) {
	if (s1.medie > s1.medie) {
		return s1.nume;
	}
	else {
		return s2.nume;
	}
}

void dezalocare(struct Student* s) {
	free(s->nume);
	s->nume = NULL;
}

int main() {
	struct Student s;

	printf("Dimensiune: %d ", sizeof(char*));
	printf("Dimensiune: %d ", sizeof(int*));
	printf("Dimensiune: %d ", sizeof(struct Student*));

	s = initializare(1, 1059, "Popescu", 8.3, 'G');
	afisare(s);
	modifica_Nume(&s, "hai");
	afisare(s);

	struct Student s2;
	s2 = initializare(1, 1059, "Marcel", 9.3, 'G');
	afisare(s2);
	printf("%s", comparaStudenti(s, s2));
	//dezalocare(&s);
	return 0;
}