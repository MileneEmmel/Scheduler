#include "task.h"

struct node {
    Task *task;
    struct node *next;
};

void insert(struct node **head, Task *task);
void insert_EDF(struct node **head, Task *newTask);
void delete(struct node **head);
void traverse(struct node *head);