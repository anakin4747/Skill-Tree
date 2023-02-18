#include "simulation.h"

int max_queue_length;

void simulation(void){
	int time_to_next_customer;
	time_to_next_customer = (rand() % max_time_btwn_cust) + 1;

	for(int cycle = 0; cycle < length_of_sim; cycle++, time_to_next_customer--){
		printf("Current Cycle Minute: %d\n", cycle + 1);
		if(time_to_next_customer == 0){
			enqueue();
			print_new_person(cycle + 1);
			time_to_next_customer = (rand() % max_time_btwn_cust) + 1;
		}
		if(queue_count != 0){
		// If anyone is in the queue
			if((*queue_front)->time_to_wait == (*queue_front)->time_served){
			// Check if the person at the front been served
				print_served_person();
				dequeue();
				// Then remove them from the queue
			}
		}

		if(queue_count > max_queue_length){
			max_queue_length = queue_count;
		}

		print_queue();

		update_time_waited();
		update_time_served();
	}
	printf("Simulation ended with %d customers still in The Check Out Line.\n", queue_count);
	printf("The most customers in the Check Out Line at a time was %d.\n", max_queue_length);
	///////////////////////////////////////	
	// Still stuff to do here
	///////////////////////////////////////	

	reset_globals();
	dealloc_queue();
}

void reset_globals(void){
	next_free_ID = 1;
	max_queue_length = 0;
	queue_count = 0;
}


