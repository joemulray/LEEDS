/*
Write a program that prints the values of the function y = x2 + 1, for values of x between 0 and
3, with a step of dx = 0.2. The output of the program should look like this:
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[]){

	float total;
	printf("x \t y\n");

	for(double index = 0.0; index <= 3.2; index += .2){
		total = pow(index, 2) + 1;
		printf("%.2f \t %.2f\n", index, total);
	}

	return 0;	
}
