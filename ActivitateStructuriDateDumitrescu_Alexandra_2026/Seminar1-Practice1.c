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



//
//1. Deep Copy Cloning
//Write a function struct Product copyProduct(struct Product original) that creates a completely independent clone.
//
//It must allocate new memory for the brand and copy the contents.
//
//Modifying the brand of the clone should not affect the brand of the original.
//
//Why ? This prevents "Shallow Copy" bugs where two structs point to the same memory address.
// 
struct Product copyProduct(struct Product original) {
	struct Product product;
	product.modelCode = original.modelCode;
	product.brand = (char*)malloc(sizeof(char) * strlen(original.brand) + 1);
	strcpy(product.brand, original.brand);
	product.price = original.price;
	product.stock = original.stock;
	product.energyClass = original.energyClass;
	return product;
}


//2. Inventory Value Calculation
//Write a function float calculateTotalStockValue(struct Product* inventory, int size) that :
//
//	Takes an array of Products.
//
//	Returns the sum of(Price × Stock) for all items.
//
//	Use a loop to traverse the pointer / array.
//
// 
// 
float calculateTotalStockValue(struct Product* inventory, int size) {
	float total = 0;
	for (int i = 0;i < size;i++) {
		total += inventory[i].price * inventory[i].stock;
		
	}
	return total;
}




//	3. "Filter" by Energy Class(Sub - Arrays)
//	Write a function struct Product* getProductsByClass(struct Product* inventory, int size, char targetClass, int* resultSize) that :
//
//	Finds all products with a specific energyClass(e.g., 'A').
//
//	Dynamically allocates a new array of the correct size to hold only those products.
//
//	Uses the resultSize pointer to tell the caller how many items were found.
//
//	Challenge: Each product in this new array must be a Deep Copy of the original.

struct Product* getProductsByClass(struct Product* inventory, int size, char targetClass, int* resultSize) {
	int newSize = 0;
	for (int i = 0;i < size;i++) {
		if (inventory[i].energyClass == targetClass) {
			newSize++;
		}
	}
	struct Product* products = NULL;
	products = (struct Product*)malloc(sizeof(struct Product) * newSize);

	int it=0;
	for (int i = 0;i < size;i++) {
		
		if (inventory[i].energyClass == targetClass) {
			products[it] = copyProduct(inventory[i]);
			it++;
		}
	}

	
	*resultSize = newSize;
	return products;

}

void afisareVector(struct Product* products, int size) {
	for (int i = 0;i < size;i++) {
		afisare(products[i]);
	}
}



//
//	4. Sorting the Catalog
//	Write a function void sortProductsByPrice(struct Product* inventory, int size) :
//
//	Sort the array in ascending order of price.
//
//	You can use a simple Bubble Sort or qsort from <stdlib.h>.
//
//	Remember that when you swap two structs, the pointers to the brand names swap too!
// 
int myComparisonFunction(const void* x, const void* y) {
	return (*(int*)x - *(int*)y);
}

int comparatorPret(const struct Product* x, const struct Product* y) {
	//return (*(int*)x - *(int*)y);
	return x->price - y->price;
}

void sortVector() {
	int v[3] = { 10,9,11 };

	qsort(v,3,sizeof(int),myComparisonFunction);

	printf("%d", v[0]);
}
void sortProductsByPrice(struct Product* inventory, int size) {
	

	qsort(inventory, size, sizeof(struct Product), comparatorPret);

	
}




//	5. Bulk Deallocation
//	Write a function void destroyInventory(struct Product** inventory, int* size) :
//
//	It should loop through the array, call your dezalocare function for each element, and then free the array itself.
//
//	Set the array pointer to NULL and size to 0 at the end.


void destroyInventory(struct Product** inventory, int* size) {
	for (int i = 0;i < *size;i++) {
		free((*inventory)[i].brand);
		(*inventory)[i].brand = NULL;
		
	}
	free(*inventory);
	*inventory = NULL;
	*size = 0;
}







int main() {
	struct Product p;
	p = initializare(100, "Samsung", 10, 1, 'A');
	afisare(p);
	updateBrandName(&p, "Apple");
	afisare(p);
	struct Product p1;
	struct Product p2;
	p1 = initializare(100, "Produs 1 marca", 999.99, 46, 'A');
	p2 = initializare(100, "Produs 2 marca", 999.99, 46, 'A');
	printf("%s\n", getCheaperProduct(p1,p2));
	struct Product copie;
	struct Product shallow = p;
	printf("%p adresa shallow copy\n", shallow.brand);
	printf("%p adresa struct principala\n", p.brand);
	copie = copyProduct(p);
	printf("%p adresa deep copy\n", copie.brand);
	printf("%p adresa struct principala\n", p.brand);
	struct Product p3;
	p3 = initializare(100, "Samsung", 10, 1, 'A');
	struct Product* inventory = NULL;
	inventory=(struct Product*)malloc(sizeof(struct Product) * 4);
	inventory[0] = initializare(100, "Samsung", 1000, 1, 'A');
	inventory[1] = initializare(100, "Samsung", 50, 1, 'B');
	inventory[2] = initializare(100, "Samsung", 20, 1, 'C');
	inventory[3] = initializare(100, "Samsung", 120, 1, 'A');
	printf("total price of inventory: %5.2f\n", calculateTotalStockValue(inventory, 3));
	afisareVector(inventory, 4);
	int size;
	struct Product* doarA = NULL;
	
	doarA = getProductsByClass(inventory, 4, 'A', &size);
	afisareVector(doarA, size);
	printf("--------------\n");
	sortProductsByPrice(inventory, 4);
	afisareVector(inventory, 4);
	int a = 4;
	destroyInventory(&inventory, &a);
	
	
	
	/*dezalocare(&p);
	dezalocare(&p1);
	dezalocare(&p2);*/


	return 0;
}