#include <stdio.h>

char *month_name(int n);

int main(){
	
	printf("%s\n", month_name(4));
	return 0;
}

char *month_name(int n){
	static char *name[] = {
		"Illegal month",
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "Septemeber",
		"October", "Novemeber", "December"
	};
	
	return (n < 1 || n > 12) ? name[0] : name[n];
}