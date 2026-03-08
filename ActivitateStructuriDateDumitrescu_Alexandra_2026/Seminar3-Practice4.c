#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//Define a Data Structure : Create a SecurityIncident structure with these fields :
//
//Incident ID(String - e.g., "LOG-001")
//
//Threat Level(String - e.g., "Critical", "High", "Medium")
//
//Risk Score(Integer - between 1 and 100)
//
//Remediation Cost(Double - in USD)
struct SecurityIncident {
	char* id;
	char* level;
	int risk;
	float cost;
};
typedef struct SecurityIncident SecurityIncident;

SecurityIncident citire(FILE* f) {
	SecurityIncident m;
	char linie[100];
	char sep[5] = ",; \n";
	fgets(linie, 99, f);

	char* aux = strtok(linie, sep);
	m.id = (char*)malloc(sizeof(char) * strlen(aux) + 1);
	strcpy(m.id, aux);

	aux = strtok(NULL, sep);
	m.level = (char*)malloc(sizeof(char) * strlen(aux) + 1);
	strcpy(m.level, aux);

	m.risk = atoi(strtok(NULL, sep));

	m.cost = atof(strtok(NULL, sep));

	return m;
}

void adaugare(SecurityIncident** incidents, int* nr, SecurityIncident incident) {
	SecurityIncident* aux= (SecurityIncident*)malloc(sizeof(SecurityIncident) * ((*nr) + 1));
	for (int i = 0;i < (*nr);i++) {
		aux[i] = (*incidents)[i];
	}
	aux[*nr] = incident;
	free(*incidents);
	(*nr)++;
	*incidents = aux;

}

SecurityIncident* citireVector(const char* numeFisier, int* nr) {
	FILE* f = fopen(numeFisier, "r");
	if (!f) {
		printf("error");
		return;
	}
	else {
		SecurityIncident* incidents = NULL;
		while (!feof(f)) {
			SecurityIncident s = citire(f);
			adaugare(&incidents, nr, s);
		}
		return incidents;
	}
}
void afisare(SecurityIncident i) {
	printf("%s %s %d %5.2f\n", i.id, i.level, i.risk, i.cost);
}
void afisareVector(SecurityIncident* incidents, int nr) {
	for (int i = 0;i < nr;i++) {
		afisare(incidents[i]);
	}
}

void dezalocare(SecurityIncident** incidents, int* nr) {
	for (int i = 0;i < *nr;i++) {
		free((*incidents)[i].id);
		free((*incidents)[i].level);
	}
	free(*incidents);
	*incidents = NULL;
	*nr = 0;

}
//File Input : Read from a file named security_logs.txt.
//
//Line 1 : The total number of incidents in the file.
//
//Lines 2 + : The data for each incident, separated by spaces or tabs.
//
//Core Logic :
//
//Incident Dashboard : Display a formatted list of all recorded incidents.
//
//Priority Filter : Filter and display only the incidents with a Risk Score 
// greater than 75.
//
//Financial Impact : Calculate the Average Remediation Cost for all incidents.
//
//Critical Count : Count and display how many incidents are labeled as "Critical".
//
//Memory Management : *Ensure you dynamically allocate memory for the Incident ID 
// and Threat Level strings.
int main() {
	int nr = 0;
	SecurityIncident* incidents = citireVector("security_logs.txt", &nr);
	afisareVector(incidents, nr);
	dezalocare(&incidents, &nr);
	afisareVector(incidents, nr);
	return 0;
}