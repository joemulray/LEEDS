/*
Write a program that prints the powers of two from 20
to 210, i.e. the output of the program
should look like this:
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char * argv[]){

	for(int index=1; index<=10; index++){
	
		int value = pow(2, index);		
		printf("2^%i = %i\n", index, value);
	}

	return 0;
}
