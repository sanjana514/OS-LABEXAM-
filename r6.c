//write a prog that will create 3 user level threads.Inside one thread take 2 input of 2 numbers.inside 2nd thread make a choice(press 1 for substraction and 2 for multiplication of that 2 numbers)and inside the last thread display the result.In the main func create a child and inside the child call all these threads to perform your operations.Inside the parent method just display"All of my operation have been performed successfully!".You must ensure that main func must wait until all the child and threads execution terminated.
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<sys/wait.h>
int n1,n2,choice,result;
sem_t s;
void* fun1(void* a){
sem_wait(&s);
printf("Enter 2 number:\n");
scanf("%d %d",&n1,&n2);
sem_post(&s);
}
void* fun2(void* a){
sem_wait(&s);
printf("press 1 for substraction & 2 for multiplication\n");
scanf("%d",&choice);
sem_post(&s);
}
void* fun3(void* a){
sem_wait(&s);
if(choice==1){
result=n1-n2;
printf("Substraction is:%d\n",result);
}
else if(choice==2){
result=n1*n2;
printf("Multiplication is:%d\n",result);
}
else{
printf("invalid\n");
sem_post(&s);
}}
int main(){
sem_init(&s,0,1);
pthread_t t1,t2,t3;
pid_t pid=fork();
if(pid==0){
pthread_create(&t1,NULL,fun1,NULL);
pthread_create(&t2,NULL,fun2,NULL);
pthread_create(&t3,NULL,fun3,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t3,NULL);
}
else{
wait(NULL);
printf("All of my operation have been performed successfully!\n");
}
sem_destroy(&s);
return 0;
}


