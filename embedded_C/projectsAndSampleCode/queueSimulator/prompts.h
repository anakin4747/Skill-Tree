#ifndef PROMPTS_H
#define PROMPTS_H

extern int max_time_btwn_cust;
	// Max time between customers (x)
extern int max_wait_time;
	// Max time for customers to be served (y)
extern int length_of_sim;
	// Length of simulation (z)

void initial_prompt(void);
int continue_sim_prompt(void);

#endif // PROMPTS_H
