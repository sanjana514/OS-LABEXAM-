//write a code that prints "I am happy to be the student of the Department of CSE EWU".Your code should have 5 threads.Thread1 will print "I am happy",thread2 will print "to be the student",thread3 will print"of the Department of" thread4 will print"CSE EWU" and thread5 will print all necessary spaces.[you may use semaphore for proper synchronization].
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
sem_t s;
void* fun1(void* a){
sem_wait(&s);
printf("I am happy");
sem_post(&s);
}
void* fun2(void* a){
sem_wait(&s);
printf(" to be the student");
sem_post(&s);
}
void* fun3(void* a){
sem_wait(&s);
printf(" of the Department of");
sem_post(&s);
}
void* fun4(void* a){
sem_wait(&s);
printf(" CSE EWU");
sem_post(&s);
}
void* fun5(void* a){
sem_wait(&s);
printf(" ");
sem_post(&s);
}
int main(){
sem_init(&s,0,1);
pthread_t t1,t2,t3,t4,t5;
pthread_create(&t1,NULL,fun1,NULL);
pthread_create(&t2,NULL,fun2,NULL);
pthread_create(&t3,NULL,fun3,NULL);
pthread_create(&t4,NULL,fun4,NULL);
pthread_create(&t5,NULL,fun5,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t3,NULL);
pthread_join(t4,NULL);
pthread_join(t5,NULL);
sem_destroy(&s);
return 0;
}

