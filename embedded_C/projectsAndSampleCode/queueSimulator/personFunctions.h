#ifndef PERSONFUNCTIONS_H
#define PERSONFUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>

extern int next_free_ID;
extern int max_wait_time;
extern int queue_count;

typedef struct Person{
	int id;
	int time_to_wait;
		// A time between 1 and y that the
		// person will need to wait once served
	int time_served;
		// A count between 0 and time_to_wait
		// to keep track of their time being serviced
		// in the queue
		// Increments for each cycle they were at the front
	int time_waited;
		// Total time waited
		// Increments every cycle
} Person;

void assign_ID(Person *person_in_queue);
Person *create_person(void);
void delete_person(Person *served_person);
void print_new_person(int current_cycle);
void print_served_person(void);

extern Person **queue_front;

#endif // PERSONFUNCTIONS_H
