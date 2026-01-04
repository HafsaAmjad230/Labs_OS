#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct {
    int student_id;
    char name[50];
    float gpa;
} Student;

pthread_mutex_t print_mutex; // mutex to serialize printing


void* check_deans_list(void* arg) {
    Student* s = (Student*)arg;

    int* eligible = malloc(sizeof(int)); // allocate memory to return result
    if (s->gpa >= 3.5)
        *eligible = 1;
    else
        *eligible = 0;


    pthread_mutex_lock(&print_mutex);

    printf("Student ID: %d\n", s->student_id);
    printf("Name: %s\n", s->name);
    printf("GPA: %.2f\n", s->gpa);
    if (*eligible)
        printf("Status: Eligible for Dean's List\n\n");
    else
        printf("Status: Not eligible for Dean's List\n\n");

    pthread_mutex_unlock(&print_mutex);

    pthread_exit(eligible);
}

int main() {
    #define N 3  
 printf("Name: Hafsa Amjad\n");
    printf("Reg#: 23-NTU-CS-1162\n");
    pthread_t threads[N];
    Student students[N] = {
        {101, "Hafsa", 3.8},
        {102, "Hadia", 3.4},
        {103, "Khizra", 3.9}
    };

    int dean_count = 0;

    pthread_mutex_init(&print_mutex, NULL);


    for (int i = 0; i < N; i++) {
        if (pthread_create(&threads[i], NULL, check_deans_list, &students[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }
    for (int i = 0; i < N; i++) {
        int* eligible;
        pthread_join(threads[i], (void**)&eligible);
        dean_count += *eligible;
        free(eligible);
    }

    pthread_mutex_destroy(&print_mutex);

    printf("Total students on Dean's List: %d\n", dean_count);
    printf("Main thread: Work completed.\n");

    return 0;
}