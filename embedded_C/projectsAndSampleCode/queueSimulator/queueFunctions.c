#include "queueFunctions.h"

Person **queue_front = NULL;
int queue_count;
int longest_wait_time;

void enqueue(void){
	if(queue_count == 0){
		queue_front = (Person **)malloc(sizeof(Person *));
		// If queue is empty allocate a pointer to the first person
		*queue_front = create_person();
		// And allocate the first person
		queue_count = 1;
		// Queue count is now 1
	} else {
		queue_front = (Person **)realloc(queue_front,
					sizeof(Person *) * (queue_count + 1));
		// Reallocate the array to have 1 more Person pointer
		queue_front[queue_count++] = create_person();
		// Allocate the new person and increment count in queue
	}
}

void dequeue(void){
	if(queue_count == 0){
	// Return if queue is empty
		return;
	} else if(queue_count == 1){
	// If one person is left
		if((*queue_front)->time_waited > longest_wait_time){
			longest_wait_time = (*queue_front)->time_waited;
		}
		delete_person(*queue_front);
		// Delete them
		free(queue_front);
		// Free double pointer
		queue_front = NULL;
		// Set it back to NULL
		queue_count--;
	} else {
		if((*queue_front)->time_waited > longest_wait_time){
			longest_wait_time = (*queue_front)->time_waited;
		}
		Person *temp = *queue_front;
		// Save the person at the front
		for(int i = 0; i < queue_count - 1; i++){
			queue_front[i] = queue_front[i + 1];
			// Shift all the people forward
		}
		queue_front[queue_count - 1] = temp;
		// Put him back at the end

		queue_front = (Person **)realloc(queue_front,
					sizeof(Person *) * (queue_count - 1));
					// Reallocate to truncate served person
					
		// Delete the person at the front of the queue
		//queue_front++;
		// Move pointer to next person in queue
		queue_count--;
		// Decrease queue count
	}
}

void dealloc_queue(void){
	if(queue_count == 0){
		return;
	} else if(queue_count == 1){
		delete_person(*queue_front);
		queue_front = NULL;
	} else {
		for(int i = 0; i < queue_count; i++){
			delete_person(queue_front[i]);
		}
		queue_front = NULL;
	}
}

void print_queue(void){
	if(queue_count == 0){
		printf(" - Queue:  Queue is currently empty\n");
	} else {
		printf(" - Queue: ");
		for(int i = 0; i < queue_count; i++){
			printf("%d ", queue_front[i]->id);
		}
		printf("\n");
	}
}

void update_time_waited(void){
	if(queue_count != 0){
		for(int i = 0; i < queue_count; i++){
			queue_front[i]->time_waited++;
			// Update time_waited variable for everyone in queue
		}
	}
}

void update_time_served(void){
	if(queue_count != 0){
		(*queue_front)->time_served++;
		// Update time_served variable for first person in queue
	}
}
