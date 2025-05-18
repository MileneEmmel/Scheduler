#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule_rr_p.h"
#include "list.h"
#include "cpu.h"

struct node *taskList[MIN_PRIORITIES + 1] = { NULL };

// add a task to the list 
void add(char *name, int priority, int burst){
    Task *newTask = malloc(sizeof(Task));
    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;
    insert(&taskList[priority], newTask);
}

// invoke the scheduler
void schedule(){
   struct node *nav;
   while (1) {
      int p;

      for (p = 1; p <= MIN_PRIORITIES; p++) { // encontra a fila de maior prioridade não vazia
         if (taskList[p] != NULL) 
            break;
      }

      if (p > MIN_PRIORITIES) { // todas as filas vazias → fim do escalonamento
         break;
      }

      Task *t = taskList[p]->task;
      if (t->burst > QUANTUM) {
         slice = QUANTUM;
      } else {
         slice = t->burst;
      }
      run(t, slice);
      t->burst -= slice;
      delete(&taskList[p]);// Remove first position of the queue

      if (t->burst > 0) {
         insert(&taskList[p], t); // Insert at the end of the queue
      } else {
         free(t->name);
         free(t);
      }
   }
}