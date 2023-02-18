#include "prompts.h"
#include "simulation.h"
#include "time.h"

int main(void){
	srand(time(NULL));

	int cont;

	do {
		initial_prompt();
		// Collect x, y, and z from user
		simulation();
		// Simulation of queue
		cont = continue_sim_prompt();
		// Ask user if they wish to continue

	} while(cont);

	return 0;
}
