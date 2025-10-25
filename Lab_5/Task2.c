 #include <stdio.h>
 #include <pthread.h>
 typedef struct {
 int cgpa;
 char* name;
 } ThreadData;
 void* printData(void* arg) {
 ThreadData* data = (ThreadData*)arg;
 printf("Thread %d says: %s\n", data->cgpa, data->name);
 return NULL;
 }
 int main() {
 pthread_t t1, t2;
 ThreadData data1 = {1, "My name is Hafsa Amjad"};
 ThreadData data2 = {2, "My cgpa is 3.39"};
 pthread_create(&t1, NULL, printData, &data1);
 pthread_create(&t2, NULL, printData, &data2);
 pthread_join(t1, NULL);
 pthread_join(t2, NULL);
 printf("All threads done.\n");
 return 0;
 }