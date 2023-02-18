#include "prompts.h"

int max_time_btwn_cust;
int max_wait_time;
int length_of_sim;

void initial_prompt(void){
	// Write intital prompt to collect x, y, and z
	max_time_btwn_cust = 2;
	max_wait_time = 3;
	length_of_sim = 10;
}

int continue_sim_prompt(void){
	// Write prompt to ask user if they wish to continue
	// Return true if they wish to continue
	return 0;
}
