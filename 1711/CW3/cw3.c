/********************************************************************
I declare that the following program was written by me and that I have NOT copied any part of this code from any other source.
Name: Joseph Mulray
Email: sc17jam@leeds.ac.uk
Date: 8/12/17
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define SIZE 25
#define MAX 10000
#define MAXSIZE 50

/*Prototype definitions*/
void evaluate(char *command);
void bang();
void list();
void name();
void pairs();
void draws();
void show();
void save();
void load();
void quit();

// pair structurestruct
struct pair{
	int pairID;
	float distance;
	int pserial;
};

//star structure
struct star{
	int serial;
	char name[SIZE];
	double x,y;
	struct pair pstar;
};


static const struct star clear;
struct star universe[30][60];
char framebuffer[30][60];

int ID = 1;	
int PID=1;
int currentstars;


void PrintFrame();	//display the frame buffer
float distance(struct star star1, struct star star2); //calculate the distance between two stars
void Plot (int x, int y, char c); // store c in row y and column x of the frame buffer 
void Clear ();   // clear (erase) the whole frame buffer by filling it with white space (ASCII 32)  
void WriteAt (int x, int y, char str[]); // copy the string str to the frame buffer starting at position x,y  
void Refresh();   //clear the terminal and print the entire frame buffer  To clear the terminal you can call the Linux clear command from within your C program, using the system function, like this: system (“clear”);  
// this will clear the terminal and send the cursor to the top left of the screen 



int main(int argc, char* argv[]){

	char command[SIZE];
	while(true){
	printf(">>>");
	fgets(command, SIZE, stdin);
	evaluate(command);
	}

	return 0;
}

void evaluate(char *command){

	if(strncmp(command, "list", 4) == 0)
		list();
	else if(strncmp(command, "name", 4) == 0)
		name();
	else if(strncmp(command, "pairs", 5) == 0)
		pairs();
	else if(strncmp(command, "draws", 5) == 0)
		draws();
	else if(strncmp(command, "show", 4) == 0)
		show();
	else if (strncmp(command, "save", 4) == 0)
		save();
	else if(strncmp(command, "load", 4) == 0)
		load();
	else if(strncmp(command, "quit", 4) == 0)
		quit();
	else if(strncmp(command, "bang", 4) == 0)
		bang();
	else if(strncmp(command, "refresh", 7) == 0)
		Refresh();
	else
		return;
}

void bang(char *command){
	// This command creates a hypothetical universe comprised of stars only. 
	// The stars should be randomly scattered across the universe. 

	// get the number of stars to generate
	int numstars = atoi(command+5);
	
	//seed random number generator
	srand(time(NULL));

	//reset universe
	for(int x=0; x< 30; x++){
		for(int y=0; y<60; y++){
			universe[x][y] = clear;
		}
	}
	
	//reset incase already created
	ID=1;
	currentstars=0;
	PID= 1;

	for(int index=0; index < numstars; index++){

		//generate two random positions for each star
		int x = rand() % 30;
		int y = rand() % 60;

		while(universe[x][y].serial != 0){

			//position is already taken get new values
			x = rand() % 30;
			y = rand() % 60;
		}

		struct star* bigbang =  malloc(sizeof(struct star));
		bigbang->serial = ID;
		bigbang->x = x;
		bigbang->y = y;
		bigbang->pstar.pairID=0;
		ID++;

		universe[x][y] = *bigbang;
		free(bigbang);
	}
	//add number of stars created to current in universe
	currentstars += numstars;

}

void list(){
	//This command simply prints the list of all stars in the universe.
	int count = 1;
	struct star** stars = malloc(currentstars * sizeof(struct star));

	//cycle through universe
	for(int x=0; x< 30; x++){
		for(int y=0; y< 60; y++){
			//get all stars
			if(universe[x][y].serial!=0){
				//get serial number add to array at that position
				int position = universe[x][y].serial;
				stars[position-1] = &universe[x][y];
			}
		}
	}

	//cycle through the list of stars
	for(int index=0; index < currentstars; index++){

		//print star serial coords and name if there is one
		printf("star %i\n", stars[index]->serial);
		printf("coords: (%.3f, %.3f)\n", stars[index]->x, stars[index]->y);
		if(stars[index]->name[0] != '\0')
			printf("name: %s", stars[index]->name);
	}

	free(stars);
}

void name(){
	// This command is used to find the closest pair of stars that has not been named yet

	//max possibility stars created is amount of currentstars
	struct star** unnamed = malloc(currentstars * sizeof(struct star));

	int index=0;

	//cycle through universe
	for(int x=0; x< 30; x++){
		for(int y=0; y<60; y++){

			//get all stars have been created and not named
			if(universe[x][y].serial!=0 && universe[x][y].name[0] == '\0'){
				//get serial number add to array at that position
				unnamed[index] = &universe[x][y];
				index++;	
			}
		}
	}

	//if there are no pairs or odd value left return
	if(index == 0 || index == 1){
		printf("Sorry no pairs were found!\n");
		printf("Wish you better luck in the next universe\n");
		return;
	}

	//set minimum to max value;
	float minimum = MAX;
	struct star *pair1, *pair2; //variables to point to two values if minimum

	//cycle through comparing each item
	for(int i=0; i < index; i++){
		for(int j=i+1; j < index; j++){

			struct star *star1= unnamed[i];
			struct star *star2= unnamed[j];

			//if distance between two stars less then minimum set new value keep track of pointers
			if (distance(*star1, *star2) < minimum){
				minimum = distance(*star1,*star2);
				pair1=star1;
				pair2=star2;
			}

		}
	}

	char input;
	int character;

	printf("The closest pair of stars are %i and %i\n", pair1->serial, pair2->serial);
	printf("They are %.3f light years apart\n", minimum);
	printf("Would you like to name this pair (y/n)? ");
	scanf("%s", &input);

    //Removing \n character from input stream
    while ((character = getchar()) != '\n' && character != EOF );

	if(input == 'y'){
		printf("Enter your full name: ");
		fgets(pair1->name, SIZE, stdin);
		printf("Enter your spouse full name: ");
		fgets(pair2->name, SIZE, stdin);

		//set pair information
		pair1->pstar.pairID = PID;
		pair1->pstar.distance = minimum;
		pair1->pstar.pserial = pair2->serial;

		pair2->pstar.pairID = PID;
		pair2->pstar.distance = minimum;
		pair2->pstar.pserial = pair1->serial;

		//increase number of pairs
		PID++;
		printf("Congratulations a pair of stars has been named after you and your spouse\n");
	}

	free(unnamed);

}

float distance(struct star star1, struct star star2){
	//return the distance between the two stars

	return (sqrt(pow((star2.x - star1.x),2) + pow((star2.y - star1.y), 2)));

}



void pairs(){
	// This command prints the list of all pairs of stars that have been named so far.


	//if no pairs were created just return
	if(PID == 1){
		printf("Sorry no pairs were found!\n");
		printf("Wish you better luck in the next universe\n");
		return;
	}

	//two star arrays to store pointers of each star
	struct star** pair1 = malloc( (PID-1) * sizeof(struct star));
	struct star** pair2 = malloc( (PID-1) * sizeof(struct star));

	//initialize pointers to null
	for(int z=0; z< PID-1; z++){
		pair1[z] = NULL;
		pair2[z] = NULL;
	}


	//cycle through universe
	for(int x=0; x< 30; x++){
		for(int y=0; y<60; y++){

			//if pair is found 
			if(universe[x][y].pstar.pairID != 0){

				//get pair id number
				int tempid = universe[x][y].pstar.pairID;

				//check if value is in pair1 already if not add to pair1
				if(pair1[tempid-1] == NULL){

					pair1[tempid-1] = &universe[x][y];	//does not exists add to pair1
				}
				else{

					//add to pair 2, first pair already exists
					pair2[tempid-1] = &universe[x][y];
				}
			}
		}
	}


	//for each pair print the contents of each
	for(int index=0; index < PID-1 ; index++){
		printf("Pair %i:\n", index+1);
		printf("distance: %.3f\n", pair1[index]->pstar.distance);
		printf("star %i\n", pair1[index]->serial);
		printf("name: %s", pair1[index]->name);
		printf("coords: (%.3f, %.3f)\n", pair1[index]->x, pair1[index]->y);

		printf("star %i\n", pair2[index]->serial);
		printf("name: %s", pair2[index]->name);
		printf("coords: (%.3f, %.3f)\n", pair2[index]->x, pair2[index]->y);
		printf("**********************\n");
	}

	free(pair1);
	free(pair2);

}

void draws(){
	// This command is used to draw the universe. Named stars appear as asterisks (*)
	Clear();

	for(int x=0; x< 30; x++){
		for(int y=0; y<60; y++){

			//if is current star in universe
			if(universe[x][y].serial!=0){

				//check if star has pair or not
				if(universe[x][y].pstar.pserial != 0){	
					//it is pair plot asterisk
					Plot(x, y, '*');
				}
				else{
					//not a pair plot dot
					Plot(x,y, '.');
				}

			}
		}
	}

	PrintFrame();	//print the frame buffer

}

void PrintFrame(){

	//print the framebuffer
	for(int i=0; i< 30; i++){
		for(int j=0; j<60; j++){
			printf("%c", framebuffer[i][j]);
		}
		printf("\n");
	}

}



void Plot (int x, int y, char c){
	//plot point x,y and set value c
	framebuffer[x][y] = c;
}

void Clear(){

	//set all elements in buffer to blank space
	for(int x=0; x< 30; x++){
		for(int y=0; y<60; y++){
			framebuffer[x][y] = ' ';
		}
	}

}

void WriteAt (int x, int y, char str[]){
	//use this later for showing name on screen

	for(int index= 0; str[index] != '\0'; ++index) {

		//print frame below
    	framebuffer[x+1][y+index] = str[index];
	}

	PrintFrame();	//print the frame buffer
}

void Refresh(){
	system("clear");  // this will clear the terminal and send the cursor to the top left o
}


void show(){

	char name[SIZE];
	// This command is used to display the names of the couple who own a pair of stars. 
	printf("Enter your full name: ");
	fgets(name, SIZE, stdin);

	//clear in case was already populated 
	Clear();

	int x1= -1, y1=-1;
	struct star *pair;

	//cycle through contents
	for(int x=0; x< 30; x++){
		for(int y=0; y<60; y++){

			if(universe[x][y].serial!=0){

			//if name of value matches name trying to find
			if(strcmp(universe[x][y].name, name) == 0){

				//note the coordinates of star matching name
					x1= x;
					y1=y;
				}

				//check if star has pair or not
				if(universe[x][y].pstar.pserial != 0)	
					Plot(x, y, '*');	//it is pair plot asterisk
				else
					Plot(x,y, '.');	//not a pair plot dot
			}
		}
	}

	//no pairs were found
	if(x1 == -1){
		printf("Sorry no pairs were found!\n");
		printf("Wish you better luck in the next universe\n");
		return;
	}

	//find the matching pair from serial number
	for(int x=0; x< 30; x++){
		for(int y=0; y<60; y++){

			if(universe[x][y].serial == universe[x1][y1].pstar.pserial){
				//create pointer to star
				pair = &universe[x][y];
			}

		}
	}

	//store concatinated string
	char combined[MAXSIZE];

	//copy first name
	strcpy(combined,universe[x1][y1].name);
	combined[strcspn(combined,"\n")] = 0; //strip newline from fgets
	strcat(combined, " & ");
	strcat(combined, pair->name);	//add other name
	combined[strcspn(combined,"\n")] = 0;

	//find the farthest pair in x column
	if(x1 > pair->x)
		WriteAt(x1, y1, combined);
	else
		WriteAt(pair->x, pair->y, combined);

}

void save(){
	// The save command This command is used to save the universe.
	FILE * output = fopen ("universe.bin", "wb");


	//handle opening file
	if(output == NULL){
		printf("Error, could not open file\n");
		return;
	}

	for(int x=0; x< 30; x++){
		for(int y=0; y<60; y++){
				//write struct to output file
				fwrite(&universe[x][y], sizeof(struct star), 1, output);
			}

	}

	//close file
	fclose(output);
	printf("Thanks, you have saved the universe!\n");

}

void load(){
	// This command is used to load (read) saved data from the universe.bin file.
	//reset universe
	
	for(int x=0; x< 30; x++){
		for(int y=0; y<60; y++){
			universe[x][y] = clear;
		}
	}
	
	FILE * input = fopen ("universe.bin", "rb");

	if(input == NULL){
		printf("Error, could not open file\n");
		return;
	}


	//reset in case already created
	ID=1;
	currentstars=0;
	PID= 1;
	int numpairs=0;
	struct star read;	


	for(int x=0; x< 30; x++){
		for(int y=0; y<60; y++){
		if(fread(&read,sizeof(struct star),1,input)){
				universe[x][y] = read;

				//need to keep track if number of pairs

				if(universe[x][y].serial != 0){

				//increase amount of stars
				currentstars++;

				//check if loaded stars have pairs
				if(universe[x][y].pstar.pairID != 0){
					// printf("pairID: %d\n", universe[x][y].pstar.pairID);
					numpairs++;
					}
				}
			}
		}
	}

	PID += (numpairs/2);
	fclose(input);
	printf("Congratulations, your universe was restored!\n");
}

void quit(){
	// This command is used to terminate the program.
	exit(0);
}
