#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void* factorial(void* arg) {
    int n = *(int*)arg;        
    unsigned long long* result = malloc(sizeof(unsigned long long)); 
    *result = 1;

    for (int i = 1; i <= n; i++) {
        *result *= i;
    }

    pthread_exit(result); 
}

int main() {
    pthread_t thread;
    int num;
    unsigned long long* fact_result;
    printf("Name: Hafsa Amjad\n");
    printf("Reg#: 23-NTU-CS-1162\n");

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }
    if (pthread_create(&thread, NULL, factorial, &num) != 0) {
        perror("Failed to create thread");
        return 1;
    }
    pthread_join(thread, (void**)&fact_result);

    printf("Factorial of %d = %llu\n", num, *fact_result);


    free(fact_result);

    printf("Main thread: Work completed.\n");
    return 0;
}