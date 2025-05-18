#include "schedule_rr.h"
#include "list.h"

struct node *taskList = NULL;

// Add a task to the list 
void add(char *name, int burst){
    Task *newTask = malloc(sizeof(Task));
    newTask->name = name;
    newTask->burst = burst;
    insert(&taskList, newTask);
}

// invoke the scheduler
void schedule(){
    struct node *nav;
    while (taskList != NULL) { // While queue is not empty
        Task *t = taskList->task;
        int slice;
        if (t->burst > QUANTUM) {
            slice = QUANTUM;
        } else {
            slice = t->burst;
        }
        
        run(t, slice);
        t->burst -= slice;
        delete(&taskList); // Remove first position of the queue
        if (t->burst > 0) {
            insert(&taskList, t); // Insert at the end of the queue
        } else {
            free(t->name);
            free(t);
        }
    }
}