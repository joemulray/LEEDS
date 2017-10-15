/*
 Write a program to count how many times the value 89 occurs in a series of integer numbers.
The number of the numbers is first entered by the user. The user then enters the series itself. The
program should print the value of the count. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[]){

	int number;
	printf("Please enter a number: ");
	scanf("%i", &number);


	 int temp = number;
	 int count=0;

    while(temp != 0)
    {
        int remain = temp%10;
        if(remain == 9){

        	if((temp/10)%10 == 8)
        		count++;
        }
         temp =  temp/10;
    }

    printf("%i # of Appears: %i\n", number,count);

	return 0;
}