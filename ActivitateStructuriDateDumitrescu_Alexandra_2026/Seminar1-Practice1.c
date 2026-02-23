//1. The Data Structure
//Define a struct Product that includes :
//
//int modelCode : A unique numeric identifier.
//
//char* brand : A dynamically allocated string(must use malloc).
//
//float price : The current market price.
//
//int stock : The number of units available.
//
//char energyClass : A single character(e.g., 'A', 'B', 'C').
//

#include<stdio.h>
#include<stdlib.h>

struct Product {
	int modelCode;
	char* brand;
	float price;
	int stock;
	char energyClass;
};





//2. Deep Copy Initialization
//Write a function createProduct that :
//
//Takes parameters for all attributes.
//
//Allocates exactly the right amount of memory for the brand string.
//
//Returns the initialized structure by value.
//
struct Product initializare(int modelCode,char* brand,float price,int stock,char energyClass) {
	struct Product p;
	p.modelCode = modelCode;
	p.brand = (char*)malloc(sizeof(char)*strlen(brand) + 1);
	strcpy(p.brand, brand);
	p.price = price;
	p.stock = stock;
	p.energyClass = energyClass;
	return p;
}
//3. Formatted Output
//Write a function displayProduct that prints the product details in a clean, one - line format.
//
//Example: [Code 101] Brand : Samsung | Class : A | Price : 999.99 | Stock : 15
//
void afisare(struct Product p) {
	printf("[Code %d] Brand : %s | Class:%c | Price %5.2f | Stock : %d\n", p.modelCode, p.brand, p.energyClass, p.price, p.stock);
}
//4. Logic & Memory Update
//Write a function updateBrandName that :
//
//Takes a pointer to the product and a new brand string.
//
//Checks if the new brand name is valid(e.g., length > 1).
//
//Crucial : Frees the old memory before allocating the new memory to prevent leaks.
//
void updateBrandName(struct Product* product,char* brand) {
	if (strlen(brand) > 2) {
		free(product->brand);
		product->brand = (char*)malloc(sizeof(char) * strlen(brand) + 1);
		strcpy(product->brand, brand);
	}
}
//5. Conditional Logic(Comparison)
//Write a function getCheaperProduct that :
//
//Accepts two Product structures.
//
//Returns the brand name of the product with the lower price.
//
//Edge case: If prices are equal, return the name of the first one.
char* getCheaperProduct(struct Product p1, struct Product p2) {
	if (p1.price <= p2.price) {
		return p1.brand;
	}
	return p2.brand;
}
//	6. Memory Cleanup
//	Write a function destroyProduct that :
//
//Takes a pointer to a product.
//
//Frees the brand memory and sets the pointer to NULL to avoid "dangling pointers."
void dezalocare(struct Product* product) {
	free(product->brand);
	product->brand = NULL;
}


int main() {
	struct Product p;
	p = initializare(100, "Samsung", 999.99, 46, 'A');
	afisare(p);
	updateBrandName(&p, "Apple");
	afisare(p);
	struct Product p1;
	struct Product p2;
	p1 = initializare(100, "Produs 1 marca", 999.99, 46, 'A');
	p2 = initializare(100, "Produs 2 marca", 999.99, 46, 'A');
	printf("%s", getCheaperProduct(p1,p2));
	dezalocare(&p);
	dezalocare(&p1);
	dezalocare(&p2);

	return 0;
}