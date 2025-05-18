#define MIN_PRIORITY 5
#define MAX_PRIORITY 1

// add a task to the list 
void add(char *name, int priority, int burst);

// invoke the scheduler
void schedule();