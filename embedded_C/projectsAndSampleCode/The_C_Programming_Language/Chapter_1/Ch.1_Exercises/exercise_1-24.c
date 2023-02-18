#include <stdio.h>

int *update_bracket_count(char c, int count[]);
int in_quote();

int main(int argc, char *argv[]){
	int count[4];

	for(int i = 0; i < 4; i++)
		count[i] = 0;
	char quotes[] = "\"\'";

	FILE * ptr1;
		
	if((ptr1 = fopen(argv[1],"r")) == NULL){
		printf("Error opening file\n");
		return 1;
	}
	
	int c;
	while((c = fgetc(ptr1)) != EOF){
		update_bracket_count(c, count);
	}
	for(int i = 0; i < 4; i++)
		if(count[i] != 0)
			printf("Syntax error detected\n");
	printf("No syntax errors detected\n");

	fclose(ptr1);
	
	return 0;
}

int *update_bracket_count(char c, int count[]){
	char opening[] = "({[<";
	char closing[] = ")}]>";
	
	int i;
	for(i = 0; opening[i] != '\0'; i++){
		if(c == opening[i]){
			count[i]++;
			return count;
		}
		if(c == closing[i]){
			count[i]--;
			return count;			
		}
	}
	return count;
}

int in_quote(){


}
