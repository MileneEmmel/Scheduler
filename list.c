// QUEUE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "task.h"

// Add a new task to the queue of tasks
void insert(struct node **head, Task *newTask) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->task = newTask;
    newNode->next = NULL;

    if (*head == NULL) // Check if queue is empty
        *head = newNode; // Insert as first (and last) position
    else {
        struct node *nav = *head; // Create auxiliar pointer to navigate the queue
        while (nav->next != NULL)
            nav = nav->next; // Navigate to the last node in the queue
        nav->next = newNode; // Insert newNode at the end of the queue
    }
}

// Delete first node of the queue
void delete(struct node **head) {
    if (*head == NULL) // Queue already empty
        return; 
    struct node *temp = *head;
    *head = (*head)->next; // Delete first node of the queue
    free(temp);
}

// Traverse the list
void traverse(struct node *head) {
    struct node *temp;
    temp = head;

    while (temp != NULL) {
        printf("[%s] [%d] [%d]\n",temp->task->name, temp->task->priority, temp->task->burst);
        temp = temp->next;
    }
}