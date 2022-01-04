#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

struct job
{
    struct job *next;
    char character;
    int count;
};
struct job *job_queue;
sem_t job_queue_count;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// La fonction qui permet de initialiser la file des taches et initialiser la semaphore en 0
void initialize_job_queue()
{
    job_queue = NULL;
    sem_init(&job_queue_count, 0, 0);
}

// La definition de la fonction enqueue_job
void enqueue_job(char chart, int count)
{
    struct job *nouveau_job = (struct job *)malloc(sizeof(struct job));
    nouveau_job->count = count;
    nouveau_job->character = chart;
    nouveau_job->next = job_queue;
    job_queue = nouveau_job;
    sem_post(&job_queue_count);
}

// La definition de la fonction process_job
void process_job(struct job *joba)
{
    for (int i = 0; i < (*joba).count; i++)
    {
        printf("%c\n", (*joba).character);
    }
}

void *thread_function(void *arg)
{
    while (job_queue != NULL)
    {
        sem_wait(&job_queue_count);
        pthread_mutex_lock(&mutex);
        struct job *next_job = job_queue; /* Récupère la tâche suivante.*/
        job_queue = job_queue->next;      /* Supprime cette tâche de la liste.*/
        process_job(next_job);            /* Traite la tâche.*/
        // sleep(2);                         // Le programme se plante car sleep() met le thread executant en attente pendant les secondes specifiees dans sleep.
        free(next_job); /* Libération des ressources.*/
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t t1, t2;
    enqueue_job('M', 5);
    enqueue_job('S', 6);
    enqueue_job('O', 9);
    enqueue_job('R', 7);
    pthread_create(&t1, NULL, thread_function, NULL);
    pthread_create(&t2, NULL, thread_function, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&job_queue_count);
    return 0;
}
