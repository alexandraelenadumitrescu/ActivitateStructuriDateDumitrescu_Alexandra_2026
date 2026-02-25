#include<stdio.h>
#include<stdlib.h>




//1. The Structure
//Define a struct named Gadget with the following attributes :
//
//int serialNumber
//
//char* modelName(dynamically allocated)
//
//float batteryLife
//
//char condition('N' for New, 'U' for Used, 'B' for Broken)
struct Gadget {
	int serialNumber;
	char* modelName;
	float batteryLife;
	char condition;
};
//
//2. Initialization & The "String" Trap
//Write a function createGadget that takes parameters for all attributes and returns a Gadget by value.
//
//The Trap : Before allocating memory for the modelName, you must write an if statement to check that the length of the string is strictly greater than 3.
//
//The Goal : Prove you remember exactly where to place the parentheses for strlen, and remember to add the correct #include at the very top of your file to make string functions work!

struct Gadget init(int serialNumber, char* modelName, float batteryLife, char condition) {
	if (strlen(modelName) > 3) {
		struct Gadget g;
		g.serialNumber = serialNumber;
		g.modelName = (char*)malloc(sizeof(char) * strlen(modelName) + 1);
		strcpy(g.modelName, modelName);
		g.batteryLife = batteryLife;
		g.condition = condition;
		return g;
	}

}


//3. The "Pointer Value" Trap(Counting)
//Write a function countUsableGadgets that takes an array of Gadget structures, its size, and an int* usableCount.
//
//The Trap : Loop through the array.If the condition is 'N' or 'U', increment the variable pointed to by usableCount.
//
//The Goal : Prove you know how to increment the actual integer value inside the memory address, rather than accidentally shifting the pointer itself to a new address.
void countUsableGadgets(struct Gadget* gadgets,int size, int* usableCount) {
	int count = 0;
	for (int i = 0;i < size;i++) {
		if (gadgets[i].condition == 'N' || gadgets[i].condition == 'U') {
			count++;
		}
	}
	*usableCount = size;

}
//4. The qsort Float Trap
//Write a function sortGadgetsByBattery that sorts an array of Gadgets in ascending order based on their batteryLife.
//
//The Trap : batteryLife is a float.qsort requires a comparator that takes const void* parameters and returns an int.
//
//The Goal : Successfully cast the void pointers back to Gadget pointers, and use if / else statements to explicitly return -1, 1, or 0 so the decimal values do not get rounded to zero and break the sort.
int comparator(const struct Gadget* a, const struct Gadget* b) {
	return a->batteryLife - b->batteryLife;
}
void sortGadgetsByBattery(struct Gadget* gadgets, int size) {
	qsort(gadgets, size, sizeof(struct Gadget), comparator);

}
//5. The "Double Pointer" Cleanup Trap
//Write a function wipeGadgetArray that takes a double pointer to the array(struct Gadget** arr) and a pointer to its size(int* size).
//
//The Trap : You need to loop through the array to free each modelName string before freeing the array container.
//
//The Goal : Prove you know the exact syntax to dereference the double pointer to access the array, and how to pass the address of a specific element[i] to free().Finally, set the array to NULL and the size to 0.
void dezalocareVector(struct Gadget** arr, int* size) {
	
	for (int i = 0;i < *size;i++) {
		free(*(arr)[i]->modelName);
		
		*(arr)[i]->modelName = NULL;
	}
	free(*arr);
	*arr = NULL;
	*size = 0;
}
int main() {
	struct Gadget* gadgets = (struct Gadget*)malloc(sizeof(struct Gadget) * 2);
	gadgets[0] = init(10, "haide", 10, 'U');
	gadgets[1] = init(5, "haid", 2, 'N');
	for (int i = 0;i < 2;i++) {
		printf("%5.2f", gadgets[i].batteryLife);
	}
	sortGadgetsByBattery(gadgets, 2);
	for (int i = 0;i < 2;i++) {
		printf("%5.2f", gadgets[i].batteryLife);
	}

	return 0;
}