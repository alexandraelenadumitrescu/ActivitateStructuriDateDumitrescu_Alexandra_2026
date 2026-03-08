//#include<stdlib.h>
//#include<string.h>
//#include<stdio.h>
//
//
//
////Define a Data Structure : Create a Mission structure with these fields :
////
////Mission Name(String)
////
////Target Destination(String - e.g., Mars, Moon, Jupiter)
////
////Launch Year(Integer)
////
////Budget(Double - in millions of dollars)
//// 
//struct Mission {
//	char* name;
//	char* destination;
//	int launch;
//	float budget;
//};
//typedef struct Mission Mission;
//
//Mission citire(FILE* f) {
//	Mission m;
//	char linie[100];
//	char sep[5] = ",; \n";
//	fgets(linie, 99, f);
//
//	char* aux = strtok(linie, sep);
//	m.name = (char*)malloc(strlen(aux) * sizeof(char) + 1);
//	strcpy(m.name, aux);
//
//	aux = strtok(NULL, sep);
//	m.destination = (char*)malloc(strlen(aux) * sizeof(char) + 1);
//	strcpy(m.destination, aux);
//
//	m.launch = atoi(strtok(NULL, sep));
//	m.budget = atof(strtok(NULL, sep));
//
//	return m;
//}
//
//void adauga(Mission** missions, int* nr, Mission nou) {
//	Mission* aux = (Mission*)malloc(sizeof(Mission) * ((*nr) + 1));
//	for (int i = 0;i < (*nr);i++) {
//		aux[i] = (*missions)[i];
//	}
//	aux[*nr] = nou;
//	free(*missions);
//	(*nr)++;
//	*missions = aux;
//	
//}
//
//Mission* citireVector(const char* numeFisier, int* nr) {
//	FILE* f = fopen(numeFisier, "r");
//	if (!f) {
//		printf("eroare");
//		return;
//	}
//	else {
//		Mission* missions = NULL;
//		while (!(feof(f))) {
//			Mission d = citire(f);
//			adauga(&missions, nr, d);
//		}
//		return missions;
//	}
//}
//
//void afisare(Mission m) {
//	printf("%s %s %d %5.2f\n", m.name, m.destination, m.launch, m.budget);
//}
//void afisareVector(Mission* m, int nr) {
//	for (int i = 0;i < nr;i++) {
//		afisare(m[i]);
//	}
//}
////
////File Input : The program must read from missions.txt.
////
////First line : An integer representing the total count of missions.
////
////Following lines : Each line contains the data for one mission.
////
////Core Logic :
////
////Full Registry : Display a list of all missions.
////
////Destination Filter : Ask the user to input a destination(e.g., "Mars") 
//// and display only the missions heading there.
////
////Average Budget : Calculate and display the average budget of all missions in the file.
////
////Memory Management : Ensure you free the dynamically allocated strings
//// (Model and Brand / Destination) and the array itself.
//
//void dezalocare(Mission** missions, int* nr) {
//	for (int i = 0;i < (*nr);i++) {
//		free((*missions)[i].name);
//		free((*missions)[i].destination);
//	}
//	free(*missions);
//	*nr = 0;
//	*missions = NULL;
//	
//}
//int main() {
//	int nr = 0;
//	Mission* missions = citireVector("missions.txt", &nr);
//	afisareVector(missions, nr);
//	
//	dezalocare(&missions, &nr);
//	afisareVector(missions, nr);
//
//	return 0;
//}