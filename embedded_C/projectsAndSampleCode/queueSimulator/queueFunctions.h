#ifndef QUEUEFUNCTIONS_H
#define QUEUEFUNCTIONS_H

#include "personFunctions.h"
#include <stdlib.h>
#include <stdio.h>

// Queue function prototypes
void enqueue(void);
void dequeue(void);
void print_queue(void);
void update_time_waited(void);
void update_time_served(void);
void dealloc_queue(void);

extern Person **queue_front;
extern int queue_count;
extern int longest_wait_time;
extern int max_queue_length;


#endif // QUEUEFUNCTIONS_H
