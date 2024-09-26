/*Write a C program that creates two threads 
to print odd numbers:5 7 9 11 ..... 99 
to print even numbers:6 8 10 ...... 100 
the main function prints all numbers:5 6 7 8 9 ..... 100*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#define maxNum 100
pthread_mutex_t mutex;
int shared_Arr[maxNum] = {0};
void *func1(void *arg){
 printf("Thread 1 will print: ");
 for(int i = 5; i <= 99; i = i+2){
  pthread_mutex_lock(&mutex);
  shared_Arr[i] = 1;
  printf("%d ",i);
  pthread_mutex_unlock(&mutex);
 }
 printf("\n");
 return NULL;
} 
void *func2(void *arg){
 printf("Thread 2 will print: ");
 for(int i = 6; i <= 100; i = i+2){
  pthread_mutex_lock(&mutex);
  shared_Arr[i] = 1;
  printf("%d ",i);
  pthread_mutex_unlock(&mutex);
 }
 printf("\n");
 return NULL;
}
int main(){
 pthread_t t1,t2;
 pthread_create(&t1,NULL,func1,NULL);
 pthread_create(&t2,NULL,func2,NULL);
 pthread_join(t1,NULL);
 pthread_join(t2,NULL);
 printf("Console Output: ");
 for(int i = 5; i <= 100; i++){
  if(shared_Arr[i]){
   printf("%d ",i);
  }
  else {
   printf("%d ",i);
  }
 }
 printf("\n");
 return 0;
}
