/********************************************************************
I declare that the following program was written by me and that I have NOT copied any part of this code from any other source.
Name: Joseph Mulray
Email: sc17jam@leeds.ac.uk
Date: 12/11/17
	
README:
** PIN NUMBER IS 1234 **

I did not know if this was to be set to a specific value did not see
it in the testing data. Once enter in do not have to enter again unless
terminate program.

*********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 20 	//define size of room and queue
#define NUMROOMS 10	

void enqueue (int number); // append n to the queue
void dequeue (); // remove the first item in the queue, and return its value
int first(); // get the first item without removing it
int last (); // get the last item without removing it
void clear (); // clear (initialize) the queue
bool IsEmpty (); // returns true if the queue is empty
bool IsFull (); // returns true if the queue is full
void print(); // print the entire queue
void position (int value); // returns the position of n in the queue, or  if n is not in the queue
void removenum (int value); // remove n from the queue
void evaulate(char *input); //evaluates user input
void insert(int position); //insert value into queue
void addroom(int room); //adds availability for doctor of selected room 
void doctorlocation(); //displays number of doctors currently available after surgery 
int availabledoctors(); //returns an available doctor
void roomstatus(); //used for testing to display status of rooms
void patient_checkout(int value); //checkouts a patient by id number
void removeroom(int roomnumber); //removes a room checkout for doctors availability 
void help(); //help function display commands
void verify_pin();	
void patient_checkin(int value);

/*variable declarations*/
int queue[SIZE];
int usedrooms[SIZE];
char input[SIZE]; 
int front=-1, rear = -1;
int pin = 1234;
bool verified = false; 


int main(int argc, char* argv[]){
	/*main function runs stdin until user exits or terminates*/
	while(true){
	printf(">>>");
	fgets(input, SIZE, stdin);
	evaulate(input);
	}
}


void evaulate(char *input){
	/*evaluate function takes users input and parses
	into command and number*/

	//declare variables for storing input
	char val = input[0];
	char digits[3];

	//copy over the values
	for(int x=0; x<3; x++){
		digits[x] = input[x+2];
	}

	//convert characters into integers 
	int value =atoi(digits);

	//switch statement to compare command
	switch(val){
		case 'i':
			patient_checkin(value);
		break;
		case 'p':
			position(value);
		break;
		case 'q':
			removenum(value);
		break;
		case 'd':
			doctorlocation();
		break;
		case 'h':
			help();
		break;
		case 'o':
			if(verified)		//needed for administration commands
			patient_checkout(value);
			else{
				verify_pin();	//once user logins once wont have to reenter passwd again
				if(verified)
					patient_checkout(value);

				return;
			}
		break;
		case 'r':
			if(verified)
			addroom(value);
		else{
			verify_pin();
			if(verified)
				addroom(value);

			return;
			}
		break;
		case 'a':	
			if(verified)
			removeroom(value);
			else{
				verify_pin();
				if(verified)
					removeroom(value);

				return;
			}
		break;
		case 'w':
			if(verified)
			print();
			else{
				verify_pin();
				if(verified)
					print();
				return;
			}
		break;
		case 'x':
			printf("Exiting\n");
			exit(0);
		break;
		case 't':
			roomstatus();
			break;
		default:
			return;
	}

}


void enqueue(int value){
	/*function to enqueue an id number into the queue*/

	//check if user already exists in queue
	for(int i = front; i!=rear; i=(i+1)%SIZE) {
		if (value == queue[i]){
			printf("You already checked in.\n");
			position(value);
			return;
		}
	}

	//check rear position of queue
	if(queue[rear] == value){
		printf("You already checked in.\n");
		position(value);
		return;
	}

	//check rooms see if number is already with a doctor
	for (int r =0; r < NUMROOMS; r++){
		if(usedrooms[r] == value){
			printf("Patient %i is already in Room %i\n", value, r+1);
			return;
		}
	}

	//check if queue is full or empty front and rear position change
	//depending on status
	if (IsFull()){
		printf("Queue is full!\n");
		return;
	}
	else if (IsEmpty()){
		front=0, rear = 0;
	}
	else{
		rear = (rear+1) % SIZE; 
	}

	printf("All doctors are busy right now\n");
	printf("Please relax in the waiting area.\n");
	queue[rear] = value;
	position(value);
}

/*functions to get the first last values from queue*/
int first(){ return queue[front];}
int last(){ return queue[rear]; }



void dequeue(){
	/*function to remove top value from queue
	repositions queue*/
	if(IsEmpty())
		return;
	else if(front == rear)
		front=-1, rear=-1;
	else
		front = (front+1) % SIZE; //change front position allocate for circulating queue
}



bool IsFull(){
	/*function to see if queue is full
	returns boolean value*/

	if((rear+1)% SIZE == front)
		return true;
	else
		return false;
}

bool IsEmpty (){ 
	/*function to see if queue is empty based on
	front and rear positions returns boolean*/

	if (front == -1 && rear == -1)
		return true;
	else
		return false;
}

void print(){
	/*function to print contents of queue*/

	if(IsEmpty()){
		printf("There is no one in the queue.\n");
		return;
	}

	//print the queue based on order of patients
	printf("The following patients are still waiting to be seen by a doctor: \n");

	 for(int x = front; x != rear; x=(x+1) % SIZE) {
            printf("%i ", queue[x]);
        }
        printf("%i \n", queue[rear]);

}

void position(int value){
	/*function to display position and number in the queue*/

	int count=0;
	//cycle through queue in order based on front and rear positions
	for(int i = front; i!=rear+1; i= (i+1) % SIZE) {
            count++;
            if(queue[i] == value){
            	printf("You are number %i in the queue\n", count);
            	return;
            }

    	}

    printf("You are not in the Queue.\n");
}

void removenum (int value){
	/*removes the value from the queue used in 
	the q command for a patient*/

	int count=0;	//declaring variables
	bool isremoved=false; //used to see if was in queue and removed


	for(int i = front; i!=rear; i=(i+1)%SIZE) {
   
            if(queue[i] == value){
            	for(int x = count; x<SIZE-1 ;x++){
            		queue[x] = queue[x+1];
            	}

            	isremoved=true;
            	rear--;
            }
        count++;

    	}

    if(queue[rear] == value){
    	rear--;
    	isremoved=true;
    }

    if(!isremoved)
    	printf("%i not in Queue.\n", value);
    else
    	printf("You have been removed from the queue!\n Thank you for your visit.\n");
}


void addroom(int room){
	/*function to add a doctor to a room
	handled invalid rooms and rooms with patients already*/


	//check if room number is valid
	if(room < 0 || room > 10){
		printf("Wrong room number. We have 10 rooms.\n");
		return;
	}

	//check if patient is in room already
	if(usedrooms[room-1] !=1 && usedrooms[room-1]!=0){
		printf("Is patient %i still in the room?\n", usedrooms[room-1]);
		printf("Check this patient out before calling another one\n");
		return;
	}

	if(!IsEmpty()){
		usedrooms[room-1] = first();
		printf("Patient %i, please go to room %i\n", first(), room);
		dequeue();
	}
	else{
	usedrooms[room-1] = 1; 	 //set doctor to available
	}

}


void doctorlocation(){
	/*function to display doctor information
	what rooms are taken by doctors*/
	
	int doctors = 0;

	//cycle through rooms array
	for(int r = 0; r < NUMROOMS; r++){

		if(usedrooms[r] != 0){
			printf("%i\n", usedrooms[r] );
			doctors++;
		}
	}

	//handle no doctors or print the contents
	if(doctors==0){
		printf("There are no doctors in surgery\n");
	}
	else{
		printf("There are %i doctor(s) in the surgery.\n", doctors);
		printf("They are in room(s):");

		for(int i=0; i < NUMROOMS; i++){
			if(usedrooms[i] != 0){
				printf(" %d ", i+1);
			}
		}
			printf("\n");
	}
}

int availabledoctors(){
	/*returns an available doctor room other wise
	just return -1*/

	for(int x=0; x < NUMROOMS; x++){
		if(usedrooms[x] == 1){
			return x;
		}
	}

	return -1;
}

void removeroom(int roomnumber){
	/*removes room that was in use by doctor*/


	//check for bad rooms and used rooms
	if(roomnumber <= 0 || roomnumber > 10){
		printf("Wrong room number. We have 10 rooms.\n");
		return;
	}

	//check for doctors in there currently
	if(usedrooms[roomnumber-1] == 0){
		printf("There are no doctors in that room.\n");
		return;
	}
	
	//check if patient still in room
	if(usedrooms[roomnumber-1]!=1){
		printf("Patient %i is still in that room!\n", usedrooms[roomnumber-1]);
		printf("Discharge that patient first.\n");
		return;
	}
	else{
		usedrooms[roomnumber-1] = 0;	//reset room to vacant
	}

}


void roomstatus(){
	/*displays testing information */

	//cycle through rooms print status
	for(int x = 0; x < NUMROOMS; x++){
		switch(usedrooms[x]){
			case 0:
				printf("Room %i: Vacant\n", x+1);
				break;
			case 1:
				printf("Room %i: Doctor Free\n", x+1);
				break;
			case -1:
				printf("Room %i: Doctor in, not ready\n", x+1);
				break;
			default:
				printf("Room %i: Doctor in with Patient %i\n", x+1, usedrooms[x]);
				break;
		}
	}
}

void patient_checkout(int value){
	/*function to discharge a patient*/

	//cycle through rooms
	for(int x = 0; x < NUMROOMS; x++){
		if(usedrooms[x] == value){
			usedrooms[x] = -1;			//set doctors status to not ready
			printf("Patient %i has been successfully discharged.\n", value);
			return;
		}
	}

	printf("Patient %i is not in any room!\n", value);
}

void help(){
	/*display commands and description*/

	printf("-------------------\n");
	printf("Commands:\n");
	printf("i [id #]\n");
	printf("\tDescription: must be used by patients to check ");
	printf("\tin on arrival to the surgery\n");
	printf("p [id #]\n");
	printf("\tDescription: command can be used at any time if a patient\n");
	printf("\t wants to know his or her position in the waiting queue.\n");
	printf("q [id #]\n");
	printf("\tDescription: this command can be used if a patient decides to leave\n");
	printf("\t after checking in, and before seeing a doctor\n");
	printf("d \n");
	printf("\tDescription: displays the number of doctors who currently available\n");
	printf("\t number of doctors currently available at the surgery.\n");
	printf("h\n");
	printf("\tDescription: displays list of all available commands and a brief\n");
	printf("\t description of each one of them\n");
	printf("\n-------------------\n");
	printf("Admin Commands:\n");
	printf("o [id #]\n");
	printf("\tDescription: command used by doctors to check out or discharge patient\n");
	printf("r [room #]\n");
	printf("\tDescription: command must be used by a doctor when they arrive at their room\n");
	printf("\t and they are ready to see patients");
	printf("a [room #]\n");
	printf("\tDescription: command used when a doctor leaves his room\n");
	printf("w\n");
	printf("\tDescription: displays the entire waiting queue\n");
	printf("x\n");
	printf("\tDescription: command used to terminate the program\n");
}


void clear(){
	/*clear contents of the queue*/

	for(int x=0; x < SIZE; x++){
		queue[x] = 0;
	}
}


void verify_pin(){
	/*function to verify admin using CLI*/

	//declare variables
	int input_pin;
	char temp[4];
	printf("Please enter the administrative password: ");
	fgets(temp, 5, stdin);

	input_pin= atoi(temp);

	//compare with set pin number 1234
	if(input_pin == pin){
		verified = true;
		printf("Logged in\n");
	}
	
}

void patient_checkin(int value){
	/*patient checkin function 
	checks available doctors and calls enqueue if not*/

	//if queue is empty and there are available doctors send to room
	if(IsEmpty()){
		int roomNumber = availabledoctors();

		//handle already in the room
		for(int x = 0; x < NUMROOMS; x++){
			if(usedrooms[x] == value){
				printf("Patient %i is already in Room %i\n", value, x+1);
				return;
			}
		}

		//open room is available send patient in
		if(roomNumber != -1){
			printf("Please proceed to room %i\n" , roomNumber +1);
			usedrooms[roomNumber] = value;
		}
		else{
			enqueue(value);	//add to queue if not
		}
	}
	else{
		enqueue(value);
	}
}