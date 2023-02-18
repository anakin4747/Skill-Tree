#include <stdio.h>

#define ALLOCSIZE 10000

char *alloc(int);
void afree(char *);

int main(){

	char *str, *str1, *str2, *str3;
	str = alloc(5);
	str1 = alloc(5);
	str2 = alloc(5);
	
	afree(str2);
	afree(str1);
	afree(str);
	// In this example the buffer is a stack so you have 
	// to free them in the opposite order you allocated them

	str3 = alloc(5);
	
	return 0;
}



static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
// Defined as static because they are global but only to this file

char *alloc(int size){
	if(allocbuf + ALLOCSIZE - allocp >= size){ 
	// At address allocbuf add the size to get to the end of the buffer
	// then subtract the address of the next free slot to get the remaining
	// free space
		printf("%d ", allocbuf + ALLOCSIZE - allocp);
		// Added this line to show the printed memory
		allocp += size;
		return allocp - size;
	} else
		return 0;
}

void afree(char *p){
	if(p >= allocbuf && p < allocbuf + ALLOCSIZE) // If the pointer is between the beginning and end of the buffer
		allocp = p;	// Set p to be the next free pointer
		// This doesn't delete the object it points to, it just allows it to be overwritten
}
