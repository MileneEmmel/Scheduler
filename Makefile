# makefile for scheduling program
#
# make rr     - for classic round-robin scheduling
# make rr_p   - for round-robin with priority scheduling
# make pa     - for priority scheduling with aging
# make edf    - for earliest deadline first scheduling

CC=gcc
CFLAGS=-Wall -pthread

all: rr rr_p pa edf

clean:
	rm -rf *.o
	rm -rf rr
	rm -rf rr_p
	rm -rf pa
	rm -rf edf

rr: driver.o list.o cpu.o timer.o schedule_rr.o
	$(CC) $(CFLAGS) -o rr driver.o schedule_rr.o list.o cpu.o timer.o

rr_p: driver.o list.o cpu.o timer.o schedule_rr_p.o
	$(CC) $(CFLAGS) -o rr_p driver.o schedule_rr_p.o list.o cpu.o timer.o

pa: driver.o list.o cpu.o timer.o schedule_pa.o
	$(CC) $(CFLAGS) -o pa driver.o schedule_pa.o list.o cpu.o timer.o

edf: driver.o list.o cpu.o timer.o schedule_edf.o
	$(CC) $(CFLAGS) -o edf driver.o schedule_edf.o list.o cpu.o timer.o

driver.o: driver.c
	$(CC) $(CFLAGS) -c driver.c

schedule_rr.o: schedule_rr.c
	$(CC) $(CFLAGS) -c schedule_rr.c

schedule_rr_p.o: schedule_rr_p.c
	$(CC) $(CFLAGS) -c schedule_rr_p.c

schedule_pa.o: schedule_pa.c
	$(CC) $(CFLAGS) -c schedule_pa.c

schedule_edf.o: schedule_edf.c
	$(CC) $(CFLAGS) -c schedule_edf.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

cpu.o: cpu.c cpu.h
	$(CC) $(CFLAGS) -c cpu.c

timer.o: timer.c timer.h
	$(CC) $(CFLAGS) -c timer.c
