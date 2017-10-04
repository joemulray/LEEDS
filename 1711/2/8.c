/*
Write a program that reads a single integer number then prints the digits of this number in
reverse, for example, if the user enters 3765 the program displays 5673. Hint: Use the % operator to
extract the digits of the number from right to left.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[]){

	int number, remain;
	int reversed = 0;

    printf("Please enter an integer: ");
    scanf("%d", &number);

    int temp = number;

    while(temp != 0)
    {
        remain = temp%10;
        reversed = (reversed*10) + remain;
        temp =  temp/10;
    }

    printf("Number: %i\n", number);
    printf("Reversed: %d\n", reversed);

    return 0;

}