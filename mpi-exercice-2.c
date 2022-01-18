// REASON : realiser un reseau logique en anneau
// AUTHOR : mehdi
// CREATED DATE : 2022-01-18 19:03:47

#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int rang, valeur, nb_processus, num_proc_suivant;
    int num_proc_precedent, num_proc_suivant;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nb_processus);
    MPI_Comm_rank(MPI_COMM_WORLD, &rang);
    num_proc_precedent = mod(nb_processus + rang - 1, nb_processus);
    num_proc_suivant = mod(rang + 1, nb_processus);
    // MPI_Send(rang + 1000, 1, MPI_INT, num_proc_suivant, 99, MPI_COMM_WORLD);
    // MPI_Recv(valeur, 1, MPI_INT, num_proc_precedent, 99, MPI_COMM_WORLD, &statut);
    
    printf("Moi, le processus % d, j’ai reçu % d du processus % d \n", rang, valeur, num_proc_precedent);
    return 0;
}