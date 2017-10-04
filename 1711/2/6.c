/*
Write a program that reads a single real number (x) and the value of an integer number (n) then
computes and prints the value of the following series:
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[]){

	float number;
	int exp;

	printf("Please enter a real number: ");
	scanf("%f", &number);
	
	printf("Please enter an integer: ");
	scanf("%i", &exp);
	
	float total = 0;

	for(int index=0; index < exp; index++){
		
		if(index%2 ==0)
		total += pow(number, index);
		else
		total -= pow(number, index);
		
	}	
	
	printf("Value of Series: %.2f\n", total);
	
	return 0;
}
