#include <stdio.h> 
#include <math.h> 

int power(int base, int exponent) { 
	if (exponent == 0) { 
		return 1; 
	} else { 
		return base * power(base, exponent -1); 
	} 
} 
	
int main() { 
	
	int base; 
	int exponent; 
	int answer; 
	
	printf("Enter base: "); 
	scanf("%d", &base); 
	
	printf("Enter exponent: "); 
	scanf("%d", &exponent); 
	
	answer = power(base, exponent); 
	
	printf("Value is %d\n", answer); 
	
	return 0; 
} 