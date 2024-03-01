// Ysabel Dodson
// Chpt5 PA

#include <stdio.h> 
#include <stdlib.h>  // Library to use dynamic memory allocation (used for allocating more space in an unbound stack) 


#define INITIAL_CAPACITY 2 


// Creating the stack 

	typedef struct { 
		int *array; // Pointer for an array 
		int top; // Index to the top of the array 
		int capacity; // the initial capacity 
	} Stack; 
	
// Initializing the stack by passing in user input as the allocation size 

	void initializeStack(Stack *stack, int initialCapacity) { 
		stack->top = -1; // Inititializing top of the stack to indicate that it is empty as of right now 
		stack->capacity = initialCapacity; 
		stack->array = (int*)malloc(initialCapacity * sizeof(int)); // Allocating memory using malloc 
		
		if (stack->array == NULL) { 
			printf("Memory not allocated\n"); 
			exit(1); 
		} 
	} 
	
	void stackResize(Stack *stack) { 
		stack->capacity = stack->capacity * 2; 
		stack->array = (int*)realloc(stack->array, stack->capacity * sizeof(int)); // Reallocating size 
		if (stack->array == NULL) { 
			printf("Memory not reallocated\n"); 
			exit(1); 
		}
	} 
	 
	int push(Stack *stack, int item) { // Pushing new item at the top of the stack 
		if (stack->top == stack->capacity - 1) { 
			stackResize(stack); 
		} 
		stack->array[++stack->top] = item;
		return 1; 
	} 
	
	
	
	int pop(Stack *stack) {  // Popping item at the top of the stack 
		return stack->array[stack->top--]; 
	} 
	
	int isEmpty(Stack *stack) { 
		return (stack->top == -1); 
	} 
	
	int peek(Stack *stack) {  // Will return the top item of the stack 
		if (stack->top == -1) { 
			printf("Stack is empty!"); 
			exit(1); 
		} 
	
		return stack->array[stack->top]; 
	} 
	
	void printStack(Stack *stack) {  // Prints the stacks contents from top to bottom 
			for (int i = stack->top; i >= 0; i--) { 
				printf("%d\n", stack->array[i]); 
			} 
	} 
	
int main(void) { 

	int allocationSize; 
	int maxLength; 
	
//Prompting user for sizes 

	printf("Please enter the allocation size of the array: "); 
	scanf("%d", &allocationSize); 
	
	printf("Now, enter the maximum length: "); 
	scanf("%d", &maxLength); 
	
	Stack stack; 
	if (allocationSize > 0)  { 
		initializeStack(&stack, allocationSize); 
	} else { 
		initializeStack(&stack, INITIAL_CAPACITY); 
	} 
		
		
	printf("\nPushing item 1 to stack was%s\n", push(&stack, 1) ? " successful!" : " failed!");  // Calling push function and determing whether is returns 0 or 1, which will deteremine success of failure 
	printf("Pushing item 2 to stack was%s\n", push(&stack, 2) ? " successful!" : " failed!"); 
	printf("Now peeking stack... the item is: %d\n", peek(&stack)); // Peeking at top of list 
	printf("Pushing item 3 to stack was%s\n", push(&stack, 3) ? " successful!" : " failed!"); 
	printf("The current stack length is %d\n", stack.top + 1); 
	printf("Popping item from stack... the value is: %d\n", pop(&stack)); // Removing item at top of list 
	printf("Now peeking stack... the item is: %d\n", peek(&stack)); 
	printf("Pushing item 4 to stack was%s\n", push(&stack, 4) ? " successful!" : " failed!"); 
	
	printf("\nCurrent stack:\n"); // Displaying the stacks content 
	printStack(&stack); 
	
	printf("\nPushing item 5 to stack was%s\n", push(&stack, 5) ? " successful!" : " failed!"); 
	printf("Popping item from stack... the value is: %d\n", pop(&stack)); 
	printf("Pushing item 6 to stack was%s\n", push(&stack, 6) ? " successful!" : " failed!"); 
	
	printf("\nCurrent stack:\n"); 
	printStack(&stack); 
	
	printf("\nPopping item from stack... the value is: %d\n", pop(&stack)); 
	
	printf("\nThe stack is %s\n", isEmpty(&stack) ? " empty." : " filled."); // calling isEmpty function to determine if stack is empty 
	
	printf("\nPopping item from stack... the value is: %d\n", pop(&stack)); 
	printf("Popping item from stack... the value is: %d\n", pop(&stack)); 
	printf("Popping item from stack... the value is: %d\n", pop(&stack)); 
	
	printf("\nThe stack is %s\n", isEmpty(&stack) ? " empty." : " filled."); 
	
	return 0; 
} 
	
	
	
	
	
	
	
	