// Ysabel Dodson 
// Chpt6 PA

#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

#define hashSize 16 // hash table's size 16 
#define emptyStart -1  // empty-since-start bucket 
#define emptyRemoval -2 // empty-after-removal bucket 
#define notFound -9 

int quadraticProbing(int index, int loopCounter) { 
	int c1 = 1; 
	int c2 = 1; 
	
	return (index + c1 + loopCounter + c2 * loopCounter * loopCounter) % hashSize; 
} 


int hash(int key) { 
	return key % hashSize; 
} 

bool hashInsert(int *hashTable, int item) {  // this function inserts an item into the hash table if possible, returns true if successful and false if unsuccessful 
	int index = hash(item);
	int loopCounter = 0;  // this LCV allows for the probing to find an empty slot

	while (hashTable[index] != emptyRemoval && hashTable[index] != emptyStart) { 
		loopCounter = loopCounter + 1; 
		index = quadraticProbing(index, loopCounter); 
		if (loopCounter >= hashSize) { 
			return false; 
		} 
	}
		
		hashTable[index] = item; 
		return true; 
	} 

	
bool hashRemove(int* hashTable, int item) { 
	int index = hash(item); 
	int loopCounter = 0; 
	
		while (hashTable[index] != emptyStart) { 
			if (hashTable[index] == item) { 
			hashTable[index] = emptyRemoval; 
			return true; // item was found 
		} 
		
		loopCounter = loopCounter + 1; 
		index = quadraticProbing(index, loopCounter);  // recursive call do quadratic probing 
	} 
	
	return false; // item was not found 
} 

int hashSearch(int* hashTable, int item) { // searches for an item in the hash table and returns the bucket number 
																// in the hash table if found and -9 if not found 
	int index = hash(item); 
	int loopCounter = 0; 
	
	while (hashTable[index] != emptyStart) { 
		if (hashTable[index] == item) { 
			return index; 
		} 
		
		loopCounter = loopCounter + 1; 
		index = quadraticProbing(index, loopCounter); 
	} 
	
	return notFound; // item was not found 
} 

void displayHashTable(int* hashTable) { 
	for (int i = 0; i < hashSize; i++) { 
		if (hashTable[i] != emptyStart && hashTable[i] != emptyRemoval) { 
		printf("HashTable[%d] is %d\n", i, hashTable[i]); 
		} 
	} 
	printf("\n"); 
}
	
int main(void) { 
	int hashTable[hashSize]; 
	bool isInserted; 
	bool isRemoved; 
	bool isFound; 
	
	for (int i = 0; i < hashSize; i++) { 
		hashTable[i] = emptyStart; 
	} 
	
	// inserting items into hash table 
	
	isInserted = hashInsert(hashTable, 32); 
	printf("Item 32 was inserted %s\n", isInserted ? "successfully" : "failed"); 
	
	isInserted = hashInsert(hashTable, 63);
	printf("Item 63 was inserted %s\n", isInserted ? "successfully" : "failed"); 
	
	isInserted = hashInsert(hashTable, 16); 
	printf("Item 16 was inserted %s\n", isInserted ? "successfully" : "failed");
	
	isInserted = hashInsert(hashTable, 3);
	printf("Item 3 was inserted %s\n", isInserted ? "successfully" : "failed");
	
	isInserted = hashInsert(hashTable, 23);
	printf("Item 23 was inserted %s\n", isInserted ? "successfully" : "failed");
	
	isInserted = hashInsert(hashTable, 11); 
	printf("Item 11 was inserted %s\n", isInserted ? "successfully" : "failed");
	
	isInserted = hashInsert(hashTable, 64); 
	printf("Item 64 was inserted %s\n", isInserted ? "successfully" : "failed");
	
	isInserted = hashInsert(hashTable, 99); 
	printf("Item 99 was inserted %s\n", isInserted ? "successfully" : "failed");
	
	isInserted = hashInsert(hashTable, 42); 
	printf("Item 42 was inserted %s\n", isInserted ? "successfully" : "failed");
	
	isInserted = hashInsert(hashTable, 49); 
	printf("Item 49 was inserted %s\n", isInserted ? "successfully" : "failed");
	
	isInserted = hashInsert(hashTable, 48); 
	printf("Item 48 was inserted %s\n", isInserted ? "successfully" : "failed");
	
	isInserted = hashInsert(hashTable, 21); 
	printf("Item 21 was inserted %s\n", isInserted ? "successfully" : "failed");
	
	printf("\nThe hash table contents are:\n"); 
	displayHashTable(hashTable); 
	
	isRemoved = hashRemove(hashTable, 32); 
	printf("Item 32 was removed %s\n", isRemoved ? "successfully" : "failed"); 
	
	isRemoved = hashRemove(hashTable, 11); 
	printf("Item 11 was removed %s\n", isRemoved ? "successfully" : "failed"); 
	
	int bucket = hashSearch(hashTable, 64); 
		if (bucket != -1) { 
			printf("Item 64 was found in bucket %d\n", bucket); 
		} else { 
			printf("Item 64 was not found.\n"); 
		} 
		
	isInserted = hashInsert(hashTable, 9); 
	printf("Item 9 was inserted %s\n", isInserted ? "successfully" : "failed");

	bucket = hashSearch(hashTable, 48); 
		if (bucket != -1) { 
			printf("Item 48 was found in bucket %d\n", bucket); 
		} else { 
			printf("Item 48 was not found.\n"); 
		} 
		
		bucket = hashSearch(hashTable, 32); 
		if (bucket != -1) { 
			printf("Item 32 was found in bucket %d\n", bucket); 
		} else { 
			printf("Item 32 was not found.\n"); 
		} 
	
	isRemoved = hashRemove(hashTable, 64); 
	printf("Item 64 was removed %s\n", isRemoved ? "successfully" : "failed"); 
	
	isRemoved = hashRemove(hashTable, 99); 
	printf("Item 99 was removed %s\n", isRemoved ? "successfully" : "failed"); 
	
	printf("\nThe hash table contents are:\n"); 
	displayHashTable(hashTable); 
	
	return 0; 
}
