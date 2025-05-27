// Driver.c
// Schedule is in the format [name] [priority] [CPU burst]
// gcc -pthread driver.c list.c cpu.c timer.c schedule_rr.c -o scheduler_rr
// ./scheduler_rr rr-schedule.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "task.h"
#include "list.h"
#include "timer.h"

 #include "schedule_rr.h"
//#include "schedule_pa.h"
// #include "schedule_rr_p.h"
// #include "schedule_edf.h"

#define SIZE 100

int main(int argc, char *argv[]) {
    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    //int priority;
    int burst;
    //int deadline;

    in = fopen(argv[1],"r");
    
    timer_start();
    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
       // priority = atoi(strsep(&temp,",")); // RR_P, PA, EDF
        burst = atoi(strsep(&temp,","));
        //deadline = atoi(strsep(&temp, ",")); // EDF

        add(name, burst); // RR
         //add(name, priority, burst); //RR_P, PA
        // add(name, priority, burst, deadline); // EDF

        free(temp);
    }

    fclose(in);
    // timer_get_time()
    schedule();
    return 0;
}