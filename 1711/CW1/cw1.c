#include <stdio.h>
#include <stdlib.h>


//prototype definitions
int welcome_message();
void statistics();
void compute_bill();
float water_consumption(int amount);
float waste_water(int consumption, float rate);

//global variables for statistics and sums
int totalconsumption=0, totaldomconsuption=0, numdomestic=0;
float domtotalrev=0, maxdom=0, revenue = 0;


int main(int argc, char * argv[]){
/*main function calls welcome message
and continues until user quits application*/

	//get initial response from user
	int choice = welcome_message();

	//while user does not choose option 3
	while(choice !=3){

		//compare choices and call function
		if(choice == 1)
			compute_bill();
		else
			statistics();

			//recall welcome message, cycle through
			//until user selects exit option
			choice = welcome_message();
	}

	return 0;
}



int welcome_message(){
/*function to display welcome message 
and get input from user about selected options*/

	//display opening message 
	printf("1. Compute and Print the Bill for a Customer \
	\n2. Show Sums and Statistics \
	\n3. Quit the program\n");


	//get input from user on choice of selection
	printf("\nPlease enter your choice (1, 2, or 3): ");
	int number;
	scanf("%d", &number);

	//validate input from user make sure value is one of the options
	while(number!=1 && (number!=2) && (number!=3)){
		printf("Please enter your choice (1, 2, or 3): ");
		scanf("%d", &number);
	}
	 	
	return number;
}


void statistics(){
/*function to display sums and statistics 
about water system*/
	
	//display statistics and sum options 
	printf("\nTotal Fresh Water Consumption: %i\n", totalconsumption);
	printf("Total Fresh Water Consumption (Residential): %i\n", totaldomconsuption);
	printf("Total Revenue: £ %.2f\n", revenue);
	printf("Total Cost: £ %.2d\n", totalconsumption);
	printf("Profit: £ %.2f\n", (revenue - totalconsumption));
	printf("Income tax: £ %.2f\n", (.25 * (revenue - totalconsumption)));
	printf("Maximum Domestic Bill: £ %.2f\n", maxdom);
	printf("Average Domestic Bill: £ %.2f\n\n", (domtotalrev / numdomestic));

}


void compute_bill(){
/*function to compute the bill of a customer
and get total values needed for statistics*/


	//variable declaration
	int amount, customer;
	float consumption, waste, fees, vat, total;

	//display menu options for user
	printf("\nPlease enter customer type, [1] Domestic or [2] Commercial: ");
	scanf("%i", &customer);

	printf("Please enter the total amount of quarterly water consumption: ");
	scanf("%d", &amount);

	//verify amount inputed by user, invalid just get another value
	while(amount < 0){
		printf("\nPlease enter the total amount of quarterly water consumption: ");
		scanf("%d", &amount);
	}

	totalconsumption +=amount;
	
	if(customer==1)
	{
		//customer is residential use residential rates
		consumption = water_consumption(amount);
		waste = waste_water(amount, .25);
		fees = (10 + (91*.1));
		total = (consumption + waste + fees);

		//display menu for domestic customers
		printf("\nCustomer: Domestic\n");
		printf("Water Consumption: £ %.2f\n", consumption);
		printf("Waste: £ %.2f\n", waste);
		printf("Fees: £ %.2f\n", fees);
		printf("Total: £ %.2f\n\n", total);

		//statement to check for maximum domestic bill
		if(total > maxdom)
			maxdom = total;

		//calculating total domestic revenue and total revenue
		totaldomconsuption +=amount;
		revenue += total;			//stored in global variables
		numdomestic++;
		domtotalrev+=total;

	}
	else{
		//else customer is commercial 

	
		//calculate fees and consumption
		consumption = 2.5 * amount;
		waste = waste_water(amount, 2.0);
		fees = (50 + (91 * 1.3));
		vat = .2 *(consumption + waste + fees);

		//display menu for commercial customer
		printf("\nCustomer: Commercial\n");
		printf("Water Consumption: £ %.2f\n", consumption);
		printf("Waste: £ %.2f\n", waste);
		printf("Fees: £ %.2f\n", fees);
		printf("VAT (20%%): £ %.2f\n", vat);
		printf("Total: £ %.2f\n\n", (vat + fees + waste + consumption));

		//use for calculating total revenue in statistics
		revenue += (consumption + waste + fees);

	}

}


float water_consumption(int amount){
/*function to calculate the bill for a domestic customer's
bill, takes in amount of water consumed*/

	//total variable for domestic water consumption
	float total=0;

	//check if valid number of not
	if(amount < 0)
		compute_bill(); 

	//cycle down list of band numbers
	if(amount>40){
		total += (amount - 40) * 2.5;
		amount=40;
	}
	if (amount>=26){
		total += (amount - 25) * .75;
		amount=25;
	}
	if(amount>=13){
		total += (amount - 12) * .5;
		amount =12;
	}
	if(amount>=6){
		total += (amount - 5) * .35;
		amount=5;
	}
	if(amount>=1){
		total += amount * .2;;
	}

	//return total amount
	return total;
}


float waste_water(int consumption, float rate){
/*function to calculate waste water amount,
takes amount of water consumed and rate */

	return((.95 * consumption) * rate);
}



