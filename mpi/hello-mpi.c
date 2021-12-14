
#include <stdio.h>
#include "mpi.h"

int main(int argc, char const *argv[])
{
    int rank, nbr_p;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nbr_p);

    if (rank == 0)
    {
        printf("The number of process is : %d\n\n", nbr_p);
        printf("Hello there, I am process %d\n\n", rank);
    }
    else
    {
        printf("Hello there, I am process %d\n\n", rank);
    }
    MPI_Finalize();
    return 0;
}
