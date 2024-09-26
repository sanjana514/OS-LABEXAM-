//write a prog that will create 3 user level threads.Inside one thread take 3 input of 3 numbers.inside 2nd thread make a choice(press 1 for addition and 2 for multiplication of that 3 numbers)and inside the last thread display the result.In the main func create a child and inside the child call all these threads to perform your operations.Inside the parent method just display"I have completed my operations perfectly!".You must ensure that main func must wait until all the child and threads execution terminated.
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<pthread.h>
#include<semaphore.h>
int n1,n2,n3,choice,result;
pthread_mutex_t l;
void* fun1(void* arg){
pthread_mutex_lock(&l);
printf("enter num1:\n");
scanf("%d",&n1);
printf("enter num2:\n");
scanf("%d",&n2);
printf("enter num3:\n");
scanf("%d",&n3);
pthread_mutex_unlock(&l);
return NULL;
}
void* fun2(void* a){
pthread_mutex_lock(&l);
printf("Press 1 for addition Or Press 2 for multiplication:\n");
scanf("%d",&choice);
pthread_mutex_unlock(&l);
return NULL;
}
void* fun3(void* a){
pthread_mutex_lock(&l);
if(choice==1){
result=(n1+n2+n3);
printf("Addition is:%d\n",result);
}
else if(choice==2){
result=(n1*n2*n3);
printf("Multiplication is:%d\n",result);
}
else{
printf("invalid choice\n");
}
pthread_mutex_unlock(&l);
return NULL;
}
int main(){
pthread_t t1,t2,t3;
pthread_mutex_init(&l,NULL);
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
printf("I have completed my operations perfectly!\n");
}
pthread_mutex_destroy(&l);
return 0;
}
