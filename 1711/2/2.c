/*Write a program that reads the score (mark) of a student (on a scale of 0 -100) and prints one of
the following messages based on the value of the mark:*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

	int number;

	printf("Please enter your score: ");
	scanf("%i", &number);

	
	if(number < 101 && number > 89 ){
		printf("You are excellent\n");
	}
	else if(number > 80 && number < 90){
		printf("Very good.\n");
	}
	else if(number > 59 && number < 80){
		printf("That is good.\n");
	}
	else if(number > 49 && number < 60 ){
		printf("Ok, you are not bad.\n");
	}
	else{
		printf("Sorry, you have failed\n");
	}

	return 0;

}
