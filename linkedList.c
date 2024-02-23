// Ysabel Dodson 
// Chpt4 PA 

#include <stdio.h>
#include <stdlib.h>

// struct to hold the data and pointer of a node
struct node {
	int data;
	struct node *next;
} 	node;

// pointers to the head node
struct node *head = NULL;

// Function to perform the same list operation as the pseudocode found in section 4.2.5
void listPrepend(int data){

	//create a link
	struct node *lk = (struct node*) malloc(sizeof(struct node));
	lk->data = data;

	// point it to old first node
	lk->next = head;

	//point first to new first node
	head = lk;
}

// Function to perform the same list operation as the pseudocode found in section 4.2.3
void listAppend(int data){
	if (head == NULL) { // list is empty
		listPrepend(data);
	} else {
		//create a link
		struct node *lk = (struct node*) malloc(sizeof(struct node));
		lk->data = data;
		struct node *linkedlist = head;

		// point it to old first node
		while(linkedlist->next != NULL) {
			linkedlist = linkedlist->next;
		}
   
		//point first to new first node
		linkedlist->next = lk;
	}
}

// Function to perform the same list operation as the pseudocode found in section 4.3.1
void listInsertAfter(struct node *list, int data){
	struct node *lk = (struct node*) malloc(sizeof(struct node));
	lk->data = data;
	lk->next = list->next;
	list->next = lk;
}

// Function to perform the same list operation as the pseudocode found in section 4.4.1
// Function removes the node that is passed in, not the next node
void listRemoveNode(int key){
	struct node *temp = head, *prev;
	if (temp != NULL && temp->data == key) {
		head = temp->next;
		return;
	}

	// Find the key to be deleted
	while (temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}

	// If the key is not present
	if (temp == NULL) return;

	// Remove the node
	prev->next = temp->next;
}

// Function to perform the same list operation as the pseudocode found in section 4.5.1
// Function will return a 1 if found or 0 if not found
int listSearch(int key){
	struct node *temp = head;
	while(temp != NULL) {
		if (temp->data == key) {
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}

//Function to perform the same list operation as the  pseudocode found in section 4.9.1
void listTraverse(){
	struct node *p = head;
	printf("\nThe list order is: ");

	//start from the beginning
	while(p != NULL) {
		printf("%d ",p->data);
		p = p->next;
	}
}

// Implement sumDataValues method
// structure adds up values of each node until reaches tail 
int sumDataValues(struct node* head) { 
	int sum = 0; 
	struct node* currentNode = head; 
	while (currentNode != NULL) { 
		sum += currentNode -> data; 
		currentNode = currentNode-> next; 
	} return sum; 
} 

int main(){
	
	listAppend(1);  // call function to append a node with a data value of 1 
	listAppend(2);  // call function to append a node with a data value of 2 
	listPrepend(3);  // call a function to prepend a node with a data of 3 
	struct node *temp = head; 
	while (temp-> data != 3) { 
		temp = temp-> next; 
	} 
	listInsertAfter(temp, 4);  // call function to insert node value of 4 after head 
	listAppend(5);  // call function to insert 5 after tail of list
	
	temp = head; 
	while (temp-> data != 4) { 
		temp = temp-> next; 
	} 
	listInsertAfter(temp, 6);  // call function to insert node value 6 after node 4
	
	temp = head; 
	while (temp-> data != 2) {  
		temp = temp-> next; 
	} 
	listInsertAfter(temp, 7); // call function to insert node 7 after node 2 
	
	listTraverse(); 
	
	head = head-> next; // remove the head from linked list 
	
	temp = head; 
	while (temp->data != 7) { 
		temp = temp-> next; 
	} 
	temp-> next = temp-> next-> next; 
	
	listTraverse(); // call function that displays list 
	
	// searching for nodes with data values 
	if (listSearch(5)) { 
		printf("\nNode with data value 5 was found.\n");
	} else { 
		printf("\nNode with data value 5 was not found.\n"); 
	} 
	
	if (listSearch(2)) { 
		printf("Node with data value 2 was found.\n"); 
	} else { 
		printf("Node with data value 2 was not found.\n"); 
	} 
	
	// displaying the sum of all the nodes in linked list 
	printf("The sum of the Linked List data values is %d\n", sumDataValues(head)); 
	
	
	
	return 0;
}
