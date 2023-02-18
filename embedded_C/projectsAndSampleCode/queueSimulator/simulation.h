#ifndef SIMULATION_H
#define SIMULATION_H

#include <stdlib.h>
#include <stdio.h>
#include "queueFunctions.h"

extern int max_time_btwn_cust;
extern int length_of_sim;
extern int max_queue_length;

void simulation(void);
void reset_globals(void);


#endif // SIMULATION_H
