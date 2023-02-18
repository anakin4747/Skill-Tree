#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

const char* genFileAddress(char * p_Name){
		
		strcpy(p_Name, "/Users/anakinchilderhose/helloWorld/child");
		
		char pid[5] = "";
		sprintf(pid, "%d", getpid());
		strcat(p_Name, pid);
		strcat(p_Name, ".txt");
		return p_Name;

}

int main(){

	char userData[100];
	do {
		
		printf("\nEnter some text\n");
		scanf(" %[^\n]s\n", userData);
		
		char pName[255] = "";

		FILE *fptr;
   		fptr = fopen(genFileAddress(pName),"w");
		fprintf(fptr,"%s", userData);

		if(fptr == NULL) {
			printf("Error!");   
			exit(1);             
		}

		fclose(fptr);
		sleep(1);
		
	} while(strcmp(userData, "Done"));

		// int id = fork();
		// if(id == 0){
		// 	//inside child process
		// 	printf("\nInside Child Process\n");
		// } else {
		// 	printf("\nInside Main Process\n");
		// }

	// printf("\n%s", userData);


	/*
	
• Prompt the user to enter some text DONE
• After text is entered, use fork to create a new process. Make sure the child is aware of the text that
has been entered. Let’s call this string userData.

• At this point, the main routine goes back to waiting for new user input. User input of “Done” should
terminate the main process and all its children. Done

• Each child process should open a separate text file on the hard disk. The name of the file is up to you,
so long as it allows you to distinguish one process from another (tip: use getpid()). 
Once per second, the child should write the new string, userData, that is received at the fork to the file on a new line.
o Example: I typed in 2 different inputs, I should have 2 children. Each of these children has their own userData writing in their own separate files.
• Children never terminate unless terminated by the parent process or externally killed.

	
	
	*/
	return 0;
}
