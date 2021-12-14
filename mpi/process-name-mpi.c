
#include <stdio.h>
#include "mpi.h"

int main(int argc, char const *argv[])
{
    int rank;
    int length = 10;
    MPI_Init(&argc, &argv);
    char proc_name[MPI_MAX_PROCESSOR_NAME];
    // MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Get_processor_name(proc_name, &length);
    printf("Process Rank: %d | Process Name: %s \n\n", proc_name);
    MPI_Finalize();
    return 0;
}
