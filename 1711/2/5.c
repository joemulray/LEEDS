/*
Write a program to calculate the factorial of a positive integer number. The factorial of a
number N is given by: N! = N (N-1) (N-2) (N-3) … 1
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char * argv[]){

	int number;
	int fact=1;
	printf("Please enter a number: ");
	scanf("%i", &number);
	
	while(number < 0 ){
		printf("Enter a valid number: ");
		scanf("%i", &number);
	}

	for(int index=1; index < number; index++){

		fact *= index;
	}
	printf("Factorial of %i: %i\n", number, fact);
		
	return 0;
}
