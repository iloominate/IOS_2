//
// Created by aliakseiklimau on 4/25/22.
//

#ifndef IOS_2_STRUCT_DEF_H
#define IOS_2_STRUCT_DEF_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>

typedef struct process_info
{
    int n_oxygen;
    int n_hydrogen;
    int atom_time;
    int molecule_time;
} process_info_t;

typedef struct semaphore_data
{
    sem_t sem_oxQue;
    sem_t sem_hQue;
    sem_t mutex;
    sem_t sem_block;
    sem_t sem_bond;
    sem_t sem_print;
    sem_t sem_end;
    sem_t sem_created;
} semaphore_data_t;

typedef struct shm_data
{
    int ox_count;
    int h_count;
    int mol_count;
} shm_data_t;


#endif //IOS_2_STRUCT_DEF_H
