//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct BookStructure {
//    int id;
//    int pageCount;
//    float price;
//    char* title;
//    char* authorName;
//    unsigned char edition;
//};
//typedef struct BookStructure Book;
//
//struct Node {
//    struct Node* next;
//    struct Node* prev;
//    Book info;
//};
//typedef struct Node Node;
//
//struct DoublyLinkedList {
//    Node* head;
//    Node* tail;
//};
//typedef struct DoublyLinkedList DoublyLinkedList;
//
//Book readBookFromFile(FILE* file) {
//    char buffer[256];
//    char sep[] = ",\n";
//    if (fgets(buffer, 256, file) == NULL) return (Book) { 0 };
//
//    Book b;
//    char* token;
//
//    token = strtok(buffer, sep);
//    b.id = atoi(token);
//
//    token = strtok(NULL, sep);
//    b.pageCount = atoi(token);
//
//    token = strtok(NULL, sep);
//    b.price = (float)atof(token);
//
//    token = strtok(NULL, sep);
//    b.title = (char*)malloc(strlen(token) + 1);
//    strcpy(b.title, token);
//
//    token = strtok(NULL, sep);
//    b.authorName = (char*)malloc(strlen(token) + 1);
//    strcpy(b.authorName, token);
//
//    token = strtok(NULL, sep);
//    b.edition = (unsigned char)token[0];
//
//    return b;
//}
//
//void displayBook(Book b) {
//    printf("ID: %d | Pages: %d | Price: %.2f | Title: %s | Author: %s | Ed: %c\n",
//        b.id, b.pageCount, b.price, b.title, b.authorName, b.edition);
//}
//
//void displayListForward(DoublyLinkedList list) {
//    Node* aux = list.head;
//    while (aux) {
//        displayBook(aux->info);
//        aux = aux->next;
//    }
//}
//
//void addBookAtEnd(DoublyLinkedList* list, Book newBook) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    newNode->info = newBook;
//    newNode->next = NULL;
//    newNode->prev = list->tail;
//
//    if (list->tail != NULL) {
//        list->tail->next = newNode;
//    }
//    else {
//        list->head = newNode;
//    }
//    list->tail = newNode;
//}
//
//DoublyLinkedList readListFromFile(const char* fileName) {
//    FILE* f = fopen(fileName, "r");
//    DoublyLinkedList list = { NULL, NULL };
//    if (!f) return list;
//
//    while (!feof(f)) {
//        Book b = readBookFromFile(f);
//        if (b.title != NULL) { // Simple check to avoid empty lines
//            addBookAtEnd(&list, b);
//        }
//    }
//    fclose(f);
//    return list;
//}
//
//void deleteList(DoublyLinkedList* list) {
//    Node* p = list->head;
//    while (p) {
//        Node* aux = p;
//        p = p->next;
//        free(aux->info.title);
//        free(aux->info.authorName);
//        free(aux);
//    }
//    list->head = NULL;
//    list->tail = NULL;
//}
//
//float calculateAveragePrice(DoublyLinkedList list) {
//    Node* p = list.head;
//    float sum = 0;
//    int count = 0;
//    while (p) {
//        count++;
//        sum += p->info.price;
//        p = p->next;
//    }
//    return (count != 0) ? (sum / count) : 0;
//}
//
//// Completed: Logic for deleting by ID
//void deleteBookByID(DoublyLinkedList* list, int id) {
//    Node* current = list->head;
//    while (current) {
//        if (current->info.id == id) {
//            if (current->prev) {
//                current->prev->next = current->next;
//            }
//            else {
//                list->head = current->next;
//            }
//
//            if (current->next) {
//                current->next->prev = current->prev;
//            }
//            else {
//                list->tail = current->prev;
//            }
//
//            free(current->info.title);
//            free(current->info.authorName);
//            free(current);
//            return;
//        }
//        current = current->next;
//    }
//}
//
//// Completed: Find author of most expensive book
//char* getAuthorOfMostExpensiveBook(DoublyLinkedList list) {
//    if (list.head == NULL) return NULL;
//
//    Node* p = list.head;
//    Node* maxNode = p;
//    float maxPrice = p->info.price;
//
//    while (p) {
//        if (p->info.price > maxPrice) {
//            maxPrice = p->info.price;
//            maxNode = p;
//        }
//        p = p->next;
//    }
//    return maxNode->info.authorName;
//}
//
//int main() {
//    
//    DoublyLinkedList myList = readListFromFile("books.txt");
//
//    printf("--- Book List ---\n");
//    displayListForward(myList);
//
//    printf("\nAverage Price: %.2f\n", calculateAveragePrice(myList));
//
//    char* topAuthor = getAuthorOfMostExpensiveBook(myList);
//    if (topAuthor) printf("Author of most expensive book: %s\n", topAuthor);
//
//    printf("\nDeleting book with ID 10 if exists...\n");
//    deleteBookByID(&myList, 10);
//
//    deleteList(&myList);
//    printf("List cleared.\n");
//
//    return 0;
//}