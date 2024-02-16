// Ysabel Dodson 
// Chpt2 PA 

#include <stdio.h> 

void swap(int *first, int *second) { // comparing the first two elements to swap 
	int temp = *first; 
	*first = *second; 
	*second = temp; 
} 

void BubbleSort( int Array[], int n) { // struct that does bubble sort 
	for (int i = 0; i < n -1; ++i) { 
		for (int j = 0; j < n - 1; ++j) {  
			if (Array[j] > Array[j + 1]) { // comparing value in elements and switching 
				swap(&Array[j], &Array[j+1]); 
			} 
		} 
	} 
} 
	

int main(void) { 
	int Array[] = {93, 52, 72, 42, 3, 63, 100, 19, 61, 44, 21, 98 , 6, 41, 78, 5, 51, 60, 67, 11};
	int n = sizeof(Array) / sizeof(Array[0]); 
	
	BubbleSort(Array, n); 
	printf("The sorted array is: "); 
	for (int i = 0; i < n; ++i)  { 
		printf("%d ", Array[i]); 
	} 
	
	printf("\n"); 
	
	return 0; 
} 
	