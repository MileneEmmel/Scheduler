#define MIN_PRIORITY 1
#define MAX_PRIORITY 5

// Adiciona uma nova tarefa a fila
void add(char *name, int priority, int burst, int deadline);

// Chama o escalonador
void schedule();