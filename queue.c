#include <stdio.h>
int front=-1,rear=-1;
int array[30];
void enqueue(int limit)
{


if(front==-1 && rear==-1)
{
front=0,rear=0;

printf("Enter the number you want to insert");
scanf("%d",&array[rear]);


}
 else if(rear==limit-1){
 printf("overflow");
 }
 
 else{
 rear++;
 printf("Enter the number you want to insert:");
 scanf("%d",&array[rear]);

 }
 }
 
 void dequeue(){
 if(front==-1 && rear==-1)
 {
   printf("Underflow");
 }
 else if(front<=rear)
 {
  printf("Deleted element :%d",array[front]);
  front++;
  
 }
 
 else{
 front=-1;rear=-1;
 printf("Underflow");
 }

 }
 
int main()
{
int limit;

printf("Enter the limit:");
scanf("%d",&limit);
int next;
for(int i=0;i<limit;i++)
{
 printf("Enter 1 for enqueue and 2 for dequeue:");
 scanf("%d",&next);
 if(next==1)
 {
 enqueue(limit);
 if(rear<limit-1){
 for(int i=0;i<=rear;i++){
 printf("%d",array[i]);
  printf("\n");
 }
 printf("\n");
 
 }   
 }
 if(next==2)
{
dequeue();
printf("\n");
for(int i=front;i<=rear;i++){
printf("%d",array[i]);
  printf("\n");
}
}
}
}


