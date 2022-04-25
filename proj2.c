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



int main(int argc, char *argv[]) {

    // variables init
    int NO;
    int NH;
    int TI;
    int TB;
    char* endptr = NULL;

    // arguments parsing
    NO = strtol(argv[1], &endptr, 10);
    NH = strtol(argv[2], &endptr, 10);
    TI = strtol(argv[3], &endptr, 10);
    TB = strtol(argv[4], &endptr, 10);

    // arguments check
    if (argc > 5)
    {
        fprintf(stderr, "Too many arguments \n");
        return 1;
    }

    if (*endptr || NO < 1 || NH < 1 || TI < 1 || TB < 1)
    {
        fprintf(stderr, "At least one argument is invalid \n");
        return 1;
    }












    printf("%d%d%d%d\n", NO, NH, TI, TB);
    return 0;
}
