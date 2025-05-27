// Driver.c
// Schedule is in the format:
// RR:           [name],[CPU burst]
// RR_P / PA:    [name],[priority],[CPU burst]
// EDF:          [name],[priority],[CPU burst],[deadline]
//
// Compile com:
// gcc -pthread driver.c list.c cpu.c timer.c schedule_rr.c -o scheduler_rr
// gcc -pthread driver.c list.c cpu.c timer.c schedule_rr_p.c -o scheduler_rr_p
// gcc -pthread driver.c list.c cpu.c timer.c schedule_pa.c -o scheduler_pa
// gcc -pthread driver.c list.c cpu.c timer.c schedule_edf.c -o scheduler_edf
//
// Execute com:
// ./scheduler_rr rr-schedule.txt
// ./scheduler_rr_p rr-schedule_pri.txt
// ./scheduler_pa rr-schedule_pri.txt
// ./scheduler_edf edf-schedule_pri.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "task.h"
#include "list.h"
#include "timer.h"

#include "schedule_rr.h"
// #include "schedule_rr_p.h"
 //#include "schedule_pa.h"
// #include "schedule_edf.h"

#define SIZE 100

int main(int argc, char *argv[]) {
    FILE *in;
    char task[SIZE];

    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo-de-entrada>\n", argv[0]);
        return 1;
    }

    in = fopen(argv[1], "r");
    if (!in) {
        perror("fopen");
        return 1;
    }

    while (fgets(task, SIZE, in) != NULL) {
        task[strcspn(task, "\n")] = '\0';  // Remove newline

        char *orig = strdup(task);
        if (!orig) {
            perror("strdup");
            exit(1);
        }

        char *temp = orig;

        // separa nome
        char *name = strsep(&temp, ",");
        if (!name) {
            fprintf(stderr, "Formato inválido (nome) na linha: %s\n", task);
            exit(1);
        }
        if (temp && temp[0] == ' ') temp++; // remove espaço após vírgula, se houver

        // Round-Robin (RR)
         int burst = atoi(temp);
        add(name, burst);

        // Round-Robin com Prioridade (RR_P)
       /*
       {
            // separa prioridade
            char *pri_str = strsep(&temp, ",");
            if (!pri_str) {
                fprintf(stderr, "Formato inválido (prioridade) na linha: %s\n", task);
                exit(1);
            }
            // separa burst
            char *burst_str = strsep(&temp, ",");
            if (!burst_str) {
                fprintf(stderr, "Formato inválido (burst) na linha: %s\n", task);
                exit(1);
            }
            int priority = atoi(pri_str);
            int burst    = atoi(burst_str);
            add(name, priority, burst);
        }

       */ 
       
      
       /*
         // Prioridade com Aging (PA)
        {
             char *pri_str = strsep(&temp, ",");
             char *burst_str = strsep(&temp, ",");
             add(name, atoi(pri_str), atoi(burst_str));
         }
       */
       
         /*
          // EDF (Earliest Deadline First)
         {
             char *pri_str = strsep(&temp, ",");
             char *burst_str = strsep(&temp, ",");
             char *dead_str = strsep(&temp, ",");
             add(name, atoi(pri_str), atoi(burst_str), atoi(dead_str));
         }
         */

        free(orig);
    }

    fclose(in);
    schedule();
    return 0;
}
