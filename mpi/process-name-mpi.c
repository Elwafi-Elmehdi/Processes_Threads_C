
#include <stdio.h>
#include "mpi.h"

int main(int argc, char const *argv[])
{
    int rank;
    MPI_Init(&argc, &argv);
    int length = MPI_MAX_PROCESSOR_NAME;
    char proc_name[length];
    MPI_Get_processor_name(proc_name, &length);
    printf("Process Rank: %d | Process Name: %s \n\n", proc_name);
    MPI_Finalize();
    return 0;
}
