Este repositório contém um simulador de escalonamento de processos em linguagem C. Implementa quatro algoritmos diferentes de escalonamento: Round-Robin (RR), Round-Robin com Prioridade (RR_P), Prioridade com Envelhecimento (PA) e Earliest Deadline First (EDF). Cada algoritmo simula a distribuição de tempo de CPU entre tarefas definidas em um arquivo de entrada. 

Como testar cada método de escalonamento:

1- RR
make rr
./scheduler_rr rr-schedule.txt
 
2- RR_P
make rr_p
./scheduler_rr_p rr-schedule_pri.txt

3- PA
make pa
./scheduler_pa rr-schedule_pri.txt

4- EDF
make edf
./scheduler_edf edf-schedule_pri.txt

Autores: Daniel Henrique da Silva e Milene Emmel Rovedder.
