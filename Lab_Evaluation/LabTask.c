//Write a C program that finds the maximum value in an array using threads:
//1.  Create an array of 20 integers with values: {45, 23, 67, 89, 12, 34, 78, 90, 56, 21, 38, 72,
//44, 91, 15, 83, 29, 66, 54, 88}
//2.Create 4 threads, each finding maximum in 5 elements:   Thread 1: elements 0-
//Thread 2: elements 5-9
//Thread 3: elements 10-14
//Thread 4: elements 15-19
//3.Pass the starting index and count to each thread using a structure
//4.Each thread:
//Finds maximum in its portion
//Prints the maximum value it found   Returns the maximum value
//5.Main thread collects all return values and finds overall maximum
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
typedef struct{
  int start;
  int count;
}ThreadData;
int arr[20]={45,23,67,89,12,34,78,90,56,21,38,72,44,91,15,83,29,66,54,88};
void* FindMax(void* arg){
  ThreadData* data = (ThreadData*) arg;
  int start=data->start;
  int count=data->count;
  int max=arr[start];
  for(int i=start+1; i<start+count; i++){
    if(arr[i]>max){ //check if the number is greater than max then swap the number with arr[i]
      max=arr[i];
    }
  }
  printf("Thread Handling elements %d to %d found max=%d\n",start,start+count-1,max);
  int* result=(int*) malloc(sizeof(int));
  *result=max;
  pthread_exit(result);
}
  int main(){
    pthread_t threads[4];
    ThreadData data[4];
    int* thread_result;
    int overall_max=0;
    printf("Name:Hafsa Amjad\n");
    printf("Reg# : 23-NsTU-CS-1162\n");
    printf("BSSE-A(5th)\n");
    // creating 4 threads for four portions
    for(int i=0;i<4;i++){
      data[i].start=i*5; //starting index
      data[i].count=5;  //5 elements per thread
      if(pthread_create(&threads[i],NULL,FindMax,&data[i]) !=0){
        perror("Failed to create Thread");
      }
    }
    for(int i=0;i<4;i++){
      pthread_join(threads[i],(void**)&thread_result);
      if(i==0 || *thread_result>overall_max){
        overall_max=*thread_result;
        free(thread_result);
      }
    }
  printf("\n overall maxmum value in the array =%d\n",overall_max);
  return 0;
  } 
