#include "personFunctions.h"

int next_free_ID = 1;

void assign_ID(Person *person){
	person->id = next_free_ID++;
	// Set the id of the person to
	// the next_free_ID and increment
}

Person *create_person(void){
	Person *new_person = (Person *)malloc(sizeof(Person));
	assign_ID(new_person); 
	new_person->time_to_wait = (rand() % max_wait_time) + 1;
	// Set the time they would have to wait between 1 and y
	new_person->time_served = 0;
	// Set the time they have waited to 0;
	return new_person;
}

void delete_person(Person *served_person){
	free(served_person);
}

void print_new_person(int cycle){
	int total_wait_time = 0;

	if(queue_count == 1){
		total_wait_time = (*queue_front)->time_to_wait;
		// If theres only one person their wait time is 
		// just time_to_wait minutes long
	} else {
		total_wait_time += (*queue_front)->time_to_wait - (*queue_front)->time_served;
		// If there are more people you need to calculate
		// how long the first person has left to be served
		for(int i = 1; i < queue_count; i++){
			total_wait_time += queue_front[i]->time_to_wait;
			// And add the time_to_wait of the rest of the queue
		}
	}
	
	printf(" ++++ New customer: %d "
		   "added at: %d "
		   "- Service Time: %d "
		   "and will be done at minute: %d "
		   "Total Wait Time: %d\n",
		   queue_front[queue_count - 1]->id,
		   cycle,
		   queue_front[queue_count - 1]->time_to_wait,
		   total_wait_time + cycle, 
		   total_wait_time);
}

void print_served_person(void){
	printf(" ---- Customer number: %d "
		   "has been serviced and left the store\n",
		   (*queue_front)->id);
}
