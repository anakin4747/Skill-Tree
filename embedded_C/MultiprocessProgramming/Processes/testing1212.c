#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

const char* genFileAddress(char * p_Name);

int main(int argc, char* argv[]){
	int fd[2];
    //fd[0] - read
    //fd[1] - write    
    if(pipe(fd) == -1){
        printf("An error ocurred with opening the pipe\n");
        return 1;
    }
	int count = 1;

	char userData[100];
	printf("\nID: %d\nEnter some text\n", getpid());
    scanf(" %[^\n]s\n", userData);

	int id;

	while((strcmp(userData, "Done")) && (count < 6)){
		char pName[255] = "";

		FILE *fptr;
   		fptr = fopen(genFileAddress(pName),"a");
		fprintf(fptr,"%s\nProcess ID: %d\n", userData, getpid());

		if(fptr == NULL) {
			printf("Error!");
			exit(1);
		}
		fclose(fptr);

		sleep(1);
		printf("\nID: %d\nEnter some text\n", getpid());
		scanf(" %[^\n]s\n", userData);
		id = fork();
		count++;
		if((id == 0) && (strcmp(userData, "Done"))){
			close(fd[0]);
			int x = 1;
			if(write(fd[1], &x, sizeof(int)) == -1){
				printf("An error ocurred with writing to the pipe in process: %d\n", getpid());
				return 3;
			}
			close(fd[1]);
			return 0;
		}
		close(fd[1]);
        int y;
        if(read(fd[0], &y, sizeof(int)) == -1){
            printf("An error ocurred with reading from the pipe in process: %d\n", getpid());
            return 4;
        }
        close(fd[0]);
        if(y == 1 && id == 0){
			return 0;
		}
	}
	while(wait(NULL) != -1 || errno != ECHILD);
	return 0;
}

const char* genFileAddress(char * p_Name){
    // Fills in the process name string with a file location to create new files for each process
		strcpy(p_Name, "/Users/anakinchilderhose/helloWorld/child");
		char pid[5] = "";
		sprintf(pid, "%d", getpid());
		strcat(p_Name, pid);
		strcat(p_Name, ".txt");
		return p_Name;
}
		


	/*
	
• Prompt the user to enter some text - DONE
• After text is entered, use fork to create a new process. Make sure the child is aware of the text that
has been entered. Let’s call this string userData. - DONE

• At this point, the main routine goes back to waiting for new user input. User input of “Done” should
terminate the main process and all its children. - DONE

• Each child process should open a separate text file on the hard disk. The name of the file is up to you,
so long as it allows you to distinguish one process from another (tip: use getpid()). 

Once per second, the child should write the new string, userData, 
that is received at the fork to the file on a new line.
o Example: I typed in 2 different inputs, I should have 2 children. 
Each of these children has their own userData writing in their own separate files.
• Children never terminate unless terminated by the parent process or externally killed.

	
	
	*/
