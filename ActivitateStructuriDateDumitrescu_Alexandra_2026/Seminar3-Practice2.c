#include<string.h>
#include<stdlib.h>
#include<stdio.h>



//Define a Data Structure : Create a Device structure with these specific fields :
//
//Model Name(String)
//
//Brand(String)
//
//Stock Quantity(Integer)
//
//Unit Price(Double)
struct Device {
	char* model;
	char* brand;
	int stock;
	float price;
};

typedef struct Device Device;
//
//File Input : The program must read from a file named inventory.txt.
//

//
//Each subsequent line contains the data for one device.
//
void adauga(Device** devices, int* nr, Device dev) {
	Device* aux = (Device*)malloc(sizeof(Device) * ((*nr)+1));
	for (int i = 0;i < *nr;i++) {
		aux[i] = (*devices)[i];
	}
	aux[(*nr)] = dev;
	free(*devices);

	(*nr)++;
	*devices = aux;
}

Device citire(FILE* f) {
	Device c;
	char linie[100];
	char sep[5] = ",; \n";
	fgets(linie, 99, f);

	char* aux = strtok(linie, sep);
	c.model = (char*)malloc(sizeof(char) * strlen(aux) + 1);
	strcpy(c.model, aux);

	aux = strtok(NULL, sep);
	c.brand = (char*)malloc(sizeof(char) * strlen(aux) + 1);
	strcpy(c.brand, aux);

	c.stock = atoi(strtok(NULL, sep));
	c.price = atof(strtok(NULL, sep));
	return c;
}

Device* citireVector(const char* numeFisier, int* devicesCitite) {
	FILE* f = fopen(numeFisier, "r");
	if (!f) {
		printf("eroare");
		return;
	}
	else {
		Device* devices = NULL;
		while (!(feof(f))) {
			Device d = citire(f);
			adauga(&devices, devicesCitite, d);
		}
		return devices;
	}
}
void afisare(Device d) {
	printf("%s %s %d %5.2f\n", d.model, d.brand, d.stock, d.price);
}
void afisareVector(Device* d, int nr) {
	printf("haide");
	for (int i = 0;i < nr;i++) {

		afisare(d[i]);
	}
}

void dezalocare(Device** devices, int* nr) {
	for (int i = 0;i < *nr;i++) {
		free((*devices)[i].model);
		free((*devices)[i].brand);
	}
	free(*devices);
	*devices = NULL;
	*nr = 0;
}


//Core Logic :
//
//Inventory Report : Print a formatted table of all devices.
//
//Stock Alert : Identify and display only the devices that have fewer than
// 5 units in stock(low stock warning).
//
//Tax Calculation : Calculate the total value of the inventory, including
// a 19 % VAT tax applied to the total sum.
//
//Memory Management : If using dynamic arrays, ensure you free or 
// delete the memory at the end of the execution.
//


int main() {
	int nr = 0;
	Device* devices = citireVector("inventory.txt", &nr);
	afisareVector(devices, nr);
	printf("%d", nr);
	dezalocare(&devices, &nr);
	afisareVector(devices, nr);
	return 0;
}