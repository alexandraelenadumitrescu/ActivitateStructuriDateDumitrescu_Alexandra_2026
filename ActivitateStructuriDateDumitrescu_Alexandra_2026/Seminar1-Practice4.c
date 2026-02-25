#include<stdio.h>
#include<stdlib.h>







//Requirements(Problem Statement)Data Structure : Define a Laptop structure containing : 
//a unique ID(int), RAM capacity(int), brand name(char* -dynamically allocated), weight(float), 
//and energy efficiency class (char).Initialization : Implement a function to initialize a Laptop object, 
//ensuring memory is correctly allocated for the brand name.Output : Create functions to display a single 
//Laptop and an entire array of laptops.Subset 
struct Laptop {
	int id;
	int RAM;
	char* brand;
	float weight;
	char energyEfficiency;

};
struct Laptop init(int id, int RAM, char* brand, float weight, char energyEfficiency) {
	struct Laptop l;
	l.id = id;
	l.RAM = RAM;
	l.brand = (char*)malloc(sizeof(char) * strlen(brand) + 1);
	strcpy(l.brand, brand);
	l.weight = weight;
	l.energyEfficiency = energyEfficiency;
	return l;
}

void afisare(struct Laptop l) {
	printf("%d %d %s %5.2f %c\n", l.id, l.RAM, l.brand, l.weight, l.energyEfficiency);
}
void afisareVector(struct Laptop* laptops, int size) {
	for (int i = 0;i < size;i++) {
		afisare(laptops[i]);
	}
}
//Selection: Write a function that creates a new array by copying
//the first $n$ elements from an existing array(deep copy).
// 
// 
struct Laptop* primeleN(struct Laptop* laptops, int n) {
	struct Laptop* primele = (struct Laptop*)malloc(sizeof(struct Laptop) * n);
	for (int i = 0;i < n;i++) {
		
		primele[i].id = laptops[i].id;
		primele[i].RAM = laptops[i].RAM;
		primele[i].brand = (char*)malloc(sizeof(char) * strlen(laptops[i].brand) + 1);
		strcpy(primele[i].brand, laptops[i].brand);
		primele[i].weight = laptops[i].weight;
		primele[i].energyEfficiency = laptops[i].energyEfficiency;
		
	}
	return primele;
}
// Conditional Filtering : Implement a function that filters
//laptops based on their weight(e.g., all laptops heavier than a specific threshold) and returns them in a newly allocated array.Search :
//	Create a function that searches for the first laptop matching a specific brand and returns a copy of it.Memory Management : 
//Implement a cleanup function to release all dynamically allocated memory for the arrays and the strings within the structures.











int main() {
	struct Laptop l1 = init(10, 16, "ThinkPad", 2, 'A');
	afisare(l1);
	struct Laptop* laptops = (struct Laptop*)malloc(3 * sizeof(struct Laptop));
	printf("=================\n");
	laptops[0]= init(10, 16, "ThinkPad", 2, 'A');
	laptops[1]= init(11, 8, "Asus", 3, 'B');
	afisareVector(laptops, 2);
	struct Laptop* hai = primeleN(laptops, 1);
	afisareVector(hai, 1);
	return  0;
}