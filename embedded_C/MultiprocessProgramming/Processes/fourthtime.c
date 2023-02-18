#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

#define CHILD_PROCESS_TOTAL 1

const char* genFileAddress(char * p_Name);

int main(int argc, char* argv[]){
    int num_of_processes = CHILD_PROCESS_TOTAL + 1;  //total num of processes is all children plus 1 main
    int pids[num_of_processes];                
    int num_of_pipes = CHILD_PROCESS_TOTAL * 2;      //2 pipes per child process each with 2 ends
    int pipes[num_of_pipes][2];                 
    
    int i;
    for(i = 0; i < num_of_pipes; i++){ // create all pipes
        if(pipe(pipes[i]) == -1){
            printf("Error creating pipes\n");
            return 1;
        }
    }
    	  
    // piping stuff

    int count = 0;

	char userData[100];
 

    while((strcmp(userData, "Done")) && (count < num_of_processes)){
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

        
        pids[count] = fork();
        if(pids[count] == -1){
            printf("Error with creating process\n");
            return 2;
        }
        
        if(pids[count] == 0){
            int j;
            for(j = 0; j < num_of_pipes; j++){
                if((j / 2 != count) || (j % 2)){
                    close(pipes[j][0]);
                    printf("Closed reading end of pipe %d in child %d\n", j, getpid());
                }
                if((j / 2 != count) || !(j % 2)){
                    close(pipes[j][1]);
                    printf("Closed writing end of pipe %d in child %d\n", j, getpid());
                }
                if(!strcmp(userData, "Done")){
                    int x = 1;
                    if(write(pipes[count * 2 + 1][1], &x, sizeof(int)) == -1){
                        printf("Error writing\n");
                        return 3;
                    }
                    printf("Wrote %d to parent\n", x);
                    int y = 1;
                    if(read(pipes[count * 2][0], &y, sizeof(int)) == -1){
                        printf("Error reading\n");
                        return 4;
                    }
                    printf("Read %d from parent\n", y);
                    if(y == 1){
                        close(pipes[count * 2][0]);
                        close(pipes[count * 2 + 1][1]);
                        printf("Successfully ended child process\n");
                        return 0;
                    }
                }
            }
                       //prevents children from going back into for loop
        } else {
            int x = 0;
            for(int h = 0; h <num_of_pipes; h++){
                if((h % 2)){
                    close(pipes[h][0]);
                    printf("Closed reading end of pipe %d in main\n", h);
                }
                if(!(h % 2)){
                    close(pipes[h][1]);
                    printf("Closed writing end of pipe %d in main\n", h);
                }
                if(h % 2){
                    if(read(pipes[h][0], &x, sizeof(int)) == -1){
                        return 5;
                    }
                    printf("Read %d from child in main\n", x);
                }
                if(x == 1){
                    if(!(h % 2)){
                        if(write(pipes[h][1], &x, sizeof(int)) == -1){
                            return 6;
                        }
                        printf("Wrote %d to child in main\n", x);
                    }
                }
                close(pipes[h][0]);
                close(pipes[h][1]);
            }
        }
        count++;
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
