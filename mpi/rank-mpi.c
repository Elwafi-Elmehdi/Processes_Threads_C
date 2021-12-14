#include <stdio.h>
#include "mpi.h"

int main(int argc, char const *argv[])
{
    int rank, nbr_p;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nbr_p);
    printf("Hello from process %d out of %d!\n", rank, nbr_p);
    MPI_Finalize();
    return 0;
}
