#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void* calculate(void* arg) {
    int num = *(int*)arg; 
    printf("Thread: Number = %d\n", num);
    printf("Thread: Square = %d\n", num * num);
    printf("Thread: Cube   = %d\n", num * num * num);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread; 
    printf("Name: Hafsa Amjad\n");
    printf("Reg#: 23-NTU-CS-1162\n");
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (pthread_create(&thread, NULL, calculate, &num) != 0) {
        perror("Failed to create thread");
        return 1;
    }
    pthread_join(thread, NULL);
    printf("Main thread: Work completed.\n");
    return 0;
}
