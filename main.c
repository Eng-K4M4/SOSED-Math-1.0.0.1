/*
 *This program was created by Eng. K4M4
 *The propuse of this project is to create a simple program like Matlab or gnu Octave
 *This project won't be so powerful as Matlab or gnu Octave, but will be enough for  simple calcs
 *The program was created using gnu gcc 5.2.1 and can be compiled using the most used comlipers
 */

/*to compile this program open the terminal and type the make command
 *to compile this program without using the Makefile type gcc main.c -o name_of_program/
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#define NUM_ATTEMPTS 3
#define NUM_ATTEMPTS_MINUS_1 NUM_ATTEMPTS-1

int main(int argc,char **argv){
	//Declaration of variables
	FILE *fp=NULL;	//It is used only if you define an extern file passed in prompt or terminal
	const char *userName="tux", *password="linux";
	char buffer1[100], buffer2[100];
	int attempts=0;
	
	system("clear");
	
	/*if you type the name of the progam followed the command --version
	 *it'll print the version of this program
	 */
	if(argc>1){
		if(strcmp(argv[1],"--version")==0){
			printf("SOSED Math VERSION 1.0.0.1\n");
			return 0;
		}
	}
	
	
	if(argc>2){
		//Used to link an extern file for the program*******************
		if(strcmp(argv[1],"-f")==0)
			fp=fopen(argv[2],"r");
		if(fp==NULL){
			printf("the programm Can not open the file %s ",argv[2]);
			return 0;
		}
		//**************************************************************
	}
	
	
	while(attempts<NUM_ATTEMPTS){
	
		printf("Plese enter the User Name:");
		scanf("%s",buffer1);
		printf("\nPlease enter de password:");
		scanf("%s",buffer2);
		
		if(strcmp(buffer1,userName)==0 && strcmp(buffer2,password)==0){
			printf("\nLogin Successful!\n\n");
			break;
		}
		else{
			printf("Error\n");
			attempts++;
		}
		
		switch(attempts){
			case NUM_ATTEMPTS:
				break;
			case NUM_ATTEMPTS_MINUS_1:
				printf("You have %d more attempt\n",NUM_ATTEMPTS-attempts);
				break;
			default:
				printf("You have %d more attempts\n",NUM_ATTEMPTS-attempts);
				break;
		}
		
	}
	
	if(attempts>=3){
		printf("\nSystem locked!\n"
			   "Please Contact your admin\n");
		return 0;
	}
	
	if(fp==NULL){
		do{
			printf("Math >");
			scanf("%s",buffer1);
		}while(strcmp(buffer1,"exit()"));
	}
	
	else{
		do{
			printf("Math >");
			fscanf(fp,"%s",buffer1);
			printf("%s\n",buffer1);
		}while(strcmp(buffer1,"exit()"));
	}
	
	return 0;
}
