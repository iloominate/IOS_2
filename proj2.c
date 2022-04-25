#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include "struct_def.h"



int main(int argc, char *argv[]) {

    // variables init
    FILE* mout;
    char* endptr = NULL;
    bool main_proc_end = false;
    process_info_t *process_info = malloc(sizeof(process_info_t));

    // arguments parsing
    process_info->n_oxygen = strtol(argv[1], &endptr, 10);
    process_info->n_hydrogen = strtol(argv[2], &endptr, 10);
    process_info->atom_time = strtol(argv[3], &endptr, 10);
    process_info->molecule_time = strtol(argv[4], &endptr, 10);

    // arguments check
    if (argc > 5)
    {
        fprintf(stderr, "Too many arguments \n");
        return 1;
    }

    if (*endptr || process_info->n_hydrogen < 1 || process_info->n_oxygen < 1 ||
    process_info->atom_time < 1 || process_info->molecule_time < 1)
    {
        fprintf(stderr, "At least one argument is invalid \n");
        return 1;
    }

    mout = fopen("proj2.out", "w");
    if (mout == NULL)
    {
        fprintf(stderr, "Couldn't open proj2.out\n");
        return 1;
    }







    return 0;
}

void init()
{
    sem_hQue = mmap(NULL, sizeof(sem_t),  PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, 0, 0);
    sem_oxQue = mmap(NULL, sizeof(sem_t),  PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, 0, 0);
    sem_block = mmap(NULL, sizeof(sem_t),  PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, 0, 0);
    sem_bond = mmap(NULL, sizeof(sem_t),  PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, 0, 0);
    sem_print = mmap(NULL, sizeof(sem_t),  PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, 0, 0);
    sem_end = mmap(NULL, sizeof(sem_t),  PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, 0, 0);
    sem_created = mmap(NULL, sizeof(sem_t),  PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, 0, 0);
    mutex = mmap(NULL, sizeof(sem_t),  PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, 0, 0);
}

void clean(process_info_t * processInfo)
{
    munmap(sem_hQue, sizeof(sem_t));
    munmap(sem_oxQue, sizeof(sem_t));
    munmap(sem_block, sizeof(sem_t));
    munmap(sem_bond, sizeof(sem_t));
    munmap(sem_print, sizeof(sem_t));
    munmap(sem_end, sizeof(sem_t));
    munmap(sem_created, sizeof(sem_t));
    munmap(mutex, sizeof(sem_t));

    free(processInfo);
}

