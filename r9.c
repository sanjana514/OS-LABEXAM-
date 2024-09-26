/*Write a C program that creates two threads 
to print odd numbers:5 7 9 11 ..... 99 
to print even numbers:6 8 10 ...... 100 
the main function prints all numbers:5 6 7 8 9 ..... 100*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
sem_t  s;
void*th1(void*arg){
printf("Thread 1 will print:");
for(int i=5;i<=99;i+=2){
sem_wait(&s);
printf("%d ",i);
sem_post(&s);}
printf("\n");
}
void*th2(void*arg){
printf("Thread 2 will print:");
for(int i=6;i<=100;i+=2){
sem_wait(&s);
printf("%d ",i);
sem_post(&s);}
printf("\n");
}
int main(){
pthread_t t1,t2;
sem_init(&s,0,1);
pthread_create(&t1,NULL,th1,NULL);
pthread_create(&t2,NULL,th2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("Console Output:");
for(int i=5;i<=100;i++){
printf("%d ",i);}
sem_destroy(&s);
return 0;
}
