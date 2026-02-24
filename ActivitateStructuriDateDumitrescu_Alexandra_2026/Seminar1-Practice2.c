#include<stdio.h>
#include<stdlib.h>
//1. The Data Structure
//Define a struct named Book that includes the following attributes :
//
//int id : A unique numeric identifier for the book.
//
//char* title : A dynamically allocated string representing the book's title (must use malloc).
//
//float price : The cost of the book.
//
//int pages : The total number of pages in the book.
//
//char category : A single character representing the genre(e.g., 'F' for Fiction, 'N' for Non - fiction, 'S' for Sci - Fi).
//
// 
//typedef struct Book Book;
struct Book {
	int id;
	char* title;
	float price;
	int pages;
	char category;
};
//2. Deep Copy Initialization
//Write a function initializeBook that :
//
//Takes parameters for all the attributes mentioned above.
//
//Allocates exactly the right amount of memory for the title string(including the null terminator).
//
//Copies the string data into the newly allocated memory.
//
//Returns the initialized Book structure by value.
struct Book init(int id, char* title, float price, int pages, char category) {
	struct Book b;
	b.id = id;
	b.title = (char*)malloc(sizeof(char) * strlen(title) + 1);
	strcpy(b.title, title);
	b.price = price;
	b.pages = pages;
	b.category = category;
	return b;
}
//3. Formatted Output
//Write two functions for displaying data :
//
//printBook: Takes a Book structure by value and prints its details in a clean, one - line format.Example : [ID:101] Title : Dune | Category : S | Price : 15.99 | Pages : 412
//
//printBookArray : Takes a pointer to an array of Book structures and its size, iterating through the array to print each book using printBook.
void printBook(struct Book b) {
	printf(" [ID:%d] Title : %s | Category : %c | Price : %5.2f | Pages : %d\n", b.id, b.title, b.category, b.price, b.pages);
}
void printBookArray(struct Book* books, int size) {
	for (int i = 0;i < size;i++) {
		printBook(books[i]);
	}
}
//4. Logic & Memory Update
//Write a function updateBookTitle that :
//
//Takes a pointer to a Book and a new title string(char*).
//
//Checks if the new title is valid(e.g., length is strictly greater than 2).
//
//Crucial : Frees the old memory allocated for the title before allocating new memory to prevent memory leaks, then copies the new title.

void updateBookTitle(struct Book* b, char* title) {
	if (strlen(title)>2) {
		free(b->title);
		b->title = (char*)malloc(sizeof(char) * strlen(title) + 1);
		strcpy(b->title, title);

	}
}
//5. Conditional Logic(Comparison)
//Write a function getLongerBook that :
//
//Accepts two Book structures by value.
//
//Returns the title(char*) of the book that has the higher number of pages.
//
//Edge case: If the number of pages is equal, return the title of the first book.
char* getLongerBook(struct Book b1, struct Book b2) {
	if (b1.pages < b2.pages) {
		return b2.title;
	}
	return b1.title;
}
//	6. Single Memory Cleanup
//	Write a function deallocateBook that :
//
//Takes a pointer to a single Book.
//
//Frees the dynamically allocated memory for the title.
//
//Sets the title pointer to NULL to avoid dangling pointers.
void deallocateBook(struct Book* b) {
	free(b->title);
	b->title = NULL;
}
//7. Deep Copy Cloning
//Write a function copyBook that :
//
//Takes a Book structure(the original) and creates a completely independent clone.
//
//Allocates new memory for the clone's title and copies the text over.
//
//Returns the cloned Book by value.
struct Book copyBook(struct Book o) {
	struct Book f;
	f.id = o.id;
	f.title = (char*)malloc(sizeof(char) * strlen(o.title) + 1);
	strcpy(f.title, o.title);
	f.price = o.price;
	f.pages = o.pages;
	f.category = o.category;

	return f;
}
//8. Aggregation Calculation
//Write a function calculateTotalInventoryValue that :
//
//Takes an array of Book structures(a pointer) and its size.
//
//Returns a float representing the total value of the books(sum of all price attributes).
//
//Uses a loop to traverse the array.
//
float calculateTotalInventoryValue(struct Book* books, int size) {
	float total = 0;
	for (int i = 0;i < size;i++) {
		total += books[i].price;
	}
	return total;
}
//9. Filtering by Category(Sub - Arrays)
//Write a function getBooksByCategory that :
//
//Takes an array of Book structures, its size, a char targetCategory, and an int* resultSize(to pass back the size of the new array).
//
//Finds all books matching the targetCategory.
//
//Dynamically allocates a new array of the exact size needed to hold only those matching books.
//
//Populates this new array using the copyBook function so that every element in the new array is a deep copy of the original.
//
//Returns the new dynamically allocated array.
struct Book* getBooksByCategory(struct Book* books, int size, char categ, int* resultSize) {
	struct Book* booksInTheCategory = NULL;
	*resultSize = 0;
	for (int i = 0;i < size;i++) {
		if (books[i].category == categ) {
			(*resultSize)++;
		}
	}
	booksInTheCategory = (struct Book*)malloc((*resultSize) * sizeof(struct Book));
	int it = 0;
	for (int i = 0;i < size;i++) {
		if (books[i].category == categ) {
			booksInTheCategory[it] = copyBook(books[i]);
				it++;
		}
	}
	

	return booksInTheCategory;

}
//10. Sorting the Catalog
//Write a function sortBooksByPrice that :
//
//Takes an array of Book structures and its size.
//
//Sorts the array in ascending order based on the price attribute.
//
//You must implement a custom comparator function and use the standard qsort from <stdlib.h>.

int comparator(const struct Book* b1, const struct Book* b2) {
	return b1->price - b2->price;
}

void sortBooksByPrice(struct Book* books, int size) {
	qsort(books, size, sizeof(struct Book), comparator);
}


//11. Bulk Deallocation
//Write a function destroyBookArray that :
//
//Takes a double pointer to an array of Book structures(struct Book**) and a pointer to its size(int* size).
//
//Loops through the array, freeing the title of each individual book.
//
//Frees the array itself.
//
//Sets the array pointer to NULL and the size to 0 to safely reset the state.

void destroyBookArray(struct Book** books, int* size) {
	for (int i = 0;i < *size;i++) {
		deallocateBook((&(*books)[i]));
	}
	*size = 0;
}





int main() {
	struct Book b1 = init(101, "Wuthering Heights", 59.99, 230, 'R');
	printBook(b1);
	struct Book b2 = init(211, "Normal People", 79.99, 120, 'R');

	struct Book* books = (struct Book*)malloc(sizeof(struct Book)*3);
	books[0] = init(211, "Normal People", 79.99, 120, 'R');
	books[1] = init(101, "Wuthering Heights", 59.99, 230, 'R');
	books[2] = init(111, "Conversations with friends", 79.99, 120, 'T');
	printBookArray(books, 2);
	updateBookTitle(&b2, "Normal People - Signed Edition");
	printBook(b2);
	printf("The longer book is : %s\n", getLongerBook(b1, b2));
	printf("%5.2f\n",calculateTotalInventoryValue(books, 2));
	struct Book b3 = init(111, "Conversations with friends", 79.99, 120, 'T');
	
	int size=0;
	
	struct Book* categR = getBooksByCategory(books, 3, 'R', &size);
	printBookArray(categR, size);
	sortBooksByPrice(categR, size);
	printBookArray(categR, size);
	destroyBookArray(&categR, &size);
	return 0;
}