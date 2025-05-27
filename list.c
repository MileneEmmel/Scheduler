// FILA
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "list.h"
#include "task.h"

// Adiciona uma nova tarefa na fila
void insert(struct node **head, Task *newTask) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->task = newTask;
    newNode->next = NULL;

    if (*head == NULL) // Verifica se a fila está vazia
        *head = newNode; // Insere como primeira (e última) posição
    else {
        struct node *nav = *head; // Nó auxiliar para navegar pela fila
        while (nav->next != NULL)
            nav = nav->next; // Percorre até o último nó
        nav->next = newNode; // Insere newNode no final da fila
    }
}

// Adiciona uma nova tarefa na fila ordenada por deadline crescente (EDF)
void insert_EDF(struct node **head, Task *newTask) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->task = newTask;
    newNode->next = NULL;

    if (*head == NULL || newTask->deadline < (*head)->task->deadline) { // Se fila vazia, ou deadline menor que primeira posição
        newNode->next = *head; 
        *head = newNode;
    } else {
        struct node *nav = *head; // Nó auxiliar para navegar pela fila
        while (nav->next != NULL && nav->next->task->deadline <= newTask->deadline) { // Percorre a fila até a posição correta
            nav = nav->next;
        }
        newNode->next = nav->next;
        nav->next = newNode; // Insere newNode na fila
    }
}

// Remove o primeiro nó da fila
void delete(struct node **head) {
    if (*head == NULL) // Verifica se a fila está vazia
        return; 
    struct node *temp = *head;
    *head = (*head)->next; // Remove o primeiro nó da fila
    free(temp);
}

// Percorre e imprime todos elementos da fila
void traverse(struct node *head) {
    struct node *temp;
    temp = head;

    while (temp != NULL) {
        printf("[%s] [%d] [%d]\n",temp->task->name, temp->task->priority, temp->task->burst);
        temp = temp->next;
    }
}