/*Write a program to find out if a number is odd or even. The program reads an integer number,
then prints “The number is odd” if the number is odd, or prints “The number is even” if the number
is even.*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	int number;

	printf("Please enter a number: ");
	scanf("%i", &number);

	if(number % 2 == 0){
		printf("Number: %i is positive\n", number);	
	}	
	else
		printf("Number: %i  is negative\n", number);



	return 0;
}
