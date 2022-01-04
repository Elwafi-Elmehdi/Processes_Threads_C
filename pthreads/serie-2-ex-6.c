// REASON : proteger l'indicateur par un var de condition
// AUTHOR : mehdi
// CREATED DATE : 2022-01-04 12:34:53

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <pthread.h>

int thread_flag;
pthread_mutex_t thread_flag_mutex;


void initialize_flag()
{
    pthread_mutex_init(&thread_flag_mutex, NULL);
    thread_flag = 0;
}
/* Appelle do_work de façon répétée tant que l'indicateur est actif ;
sinon, tourne dans la boucle. */
void *thread_function(void *thread_arg)
{
    while (1)
    {
        int flag_is_set;
        /* Protège l'indicateur avec un mutex. */
        pthread_mutex_lock(&thread_flag_mutex);
        flag_is_set = thread_flag;
        pthread_mutex_unlock(&thread_flag_mutex);
        if (flag_is_set)
            do_work();
        /* Rien à faire sinon, à part boucler. */
    }
    return NULL;
}
/* Positionne la valeur de l'indicateur de thread à FLAG_VALUE. */
void set_thread_flag(int flag_value)
{
    /* Protège l'indicateur avec un verrouillage de mutex. */
    pthread_mutex_lock(&thread_flag_mutex);
    thread_flag = flag_value;
    pthread_mutex_unlock(&thread_flag_mutex);
}

int main(int argc, char const *argv[])
{

    return 0;
}
