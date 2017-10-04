/*Write a program that prompts the user to enter two integer numbers, n and m, then prints all
odd numbers between n and m. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

	int num1, num2;

	printf("Please enter a number: ");
	scanf("%i", &num1);

	printf("Please enter another number: ");
	scanf("%i", &num2);


	for(int index=num1; index < num2; index++){
		
		if(index%2 != 0){
			printf("%i\n", index);
		}
	}



	return 0;
}
