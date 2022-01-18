// REASON : calcul matriciel parralelise
// AUTHOR : mehdi
// CREATED DATE : 2022-01-18 14:41:30

#include <stdio.h>
#include <mpi.h>
int main(int argc, char **argv)
{
    int A[3][3] = {{0, 1, 2}, {5, 1, 1}, {6, -7, -5}},
        B[3][3] = {{1, -1, 4}, {1, 0, -1}, {0, -3, 2}}, C[3][3];
    int i, j, k, n, somme;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &j);
    MPI_Comm_size(MPI_COMM_WORLD, &n);

    for (i = 0; i < n; i++)
    {
        MPI_Bcast(&A[j][i], 1, MPI_INT, 0, MPI_COMM_WORLD);
        for (k = 0; k < n; k++)
        {
            MPI_Bcast(&B[i][k], 1, MPI_INT, 0, MPI_COMM_WORLD);
        }
    }

    for (i = 0; i < n; i++)
    {
        somme = 0;
        for (k = 0; k < n; k++)
        {
            somme += A[j][k] * B[k][i];
        }
        C[j][i] = somme;
        MPI_Bcast(&C[i][j], 1, MPI_INT, j, MPI_COMM_WORLD);
    };

    if (j == 0)
    {
        for (i = 0; i < n; i++)
        {
            for (k = 0; k < n; k++)
                printf("%d\t", C[i][j]);
            printf("\n");
        }
    }
    MPI_Finalize();
    return 0;
}
