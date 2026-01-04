#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>


void* thread_func(void* arg) {
    
    int thread_num = *(int*)arg;
    pthread_t tid = pthread_self();
    printf("Thread %d started. Thread ID: %lu\n", thread_num, tid);

    int sleep_time = rand() % 3 + 1;
    sleep(sleep_time);

   
    printf("Thread %d (ID: %lu) completed after %d seconds.\n",
           thread_num, tid, sleep_time);

    pthread_exit(NULL);  
}

int main() {
    pthread_t threads[5];    
    int thread_nums[5];      
    srand(time(NULL));       
    printf("Name: Hafsa Amjad\n");
    printf("Reg#: 23-NTU-CS-1162\n\n");
    for (int i = 0; i < 5; i++) {
        thread_nums[i] = i + 1; 
        if (pthread_create(&threads[i], NULL, thread_func, &thread_nums[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("\nAll threads have completed execution.\n");
    return 0;
}
