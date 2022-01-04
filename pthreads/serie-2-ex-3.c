#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct job
{
    struct job *next;
    char character;
    int count;
};
struct job *job_queue;

void enqueue_job(char chart, int count)
{
    struct job *nouveau_job = (struct job *)malloc(sizeof(struct job));
    nouveau_job->count = count;
    nouveau_job->character = chart;
    nouveau_job->next = job_queue;
    job_queue = nouveau_job;
    return NULL;
}



void *thread_function(void *arg)
{
    while (job_queue != NULL)
    {
        struct job *next_job = job_queue; /* Récupère la tâche suivante.*/
        job_queue = job_queue->next;      /* Supprime cette tâche de la liste.*/
        process_job(next_job);            /* Traite la tâche.*/
        free(next_job);                   /* Libération des ressources.*/
    }
    return NULL;
}

int main(int argc, char const *argv[])
{

    return 0;
}
