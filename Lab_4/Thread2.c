#include <stdio.h>
#include <pthread.h>

void* show_square(void* value) {
    // Convert generic pointer back to integer pointer
    int val = *(int*)value;
    printf("Thread received number: %d\n", val);
    printf("Square: %d\n", val * val);
    return NULL;
}

int main() {
    pthread_t tid;
    int num = 42;

    printf("Creating thread with argument: %d\n", num);

    // Pass address of 'num' to the thread function
    pthread_create(&tid, NULL, show_square, &num);
    pthread_join(tid, NULL);

    printf("Main thread done.\n");
    return 0;
}
