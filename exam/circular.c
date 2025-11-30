#include<stdio.h>
int f=-1,r=-1,arr[50];

void enqueue(int max){
    if(f==-1 && r==-1){
        f=0;
        r=0;
        printf("Enter the number:");
        scanf("%d",&arr[r]);
    }
 
    else if(((r+1)%max)==f){
        printf("Overflow");
    
    }
    
  else{
        r=(r+1)%max;
        printf("Enter the number:");
        scanf("%d",&arr[r]);
    }
}

void dequeue(int max){
    if(f==-1 && r==-1){
        printf("Underflow");
        
    }
    
    else if(f==r){
           printf("Deletd element:%d",arr[f]);
        f=-1,r=-1;
    }
    else{
        printf("Deletd element:%d",arr[f]);
        f=(f+1)%max;
    }
}

void print(int max){
    if(f==-1){
        printf("Queue is empty");
        
    }
    
    int i=f;
    while(1){
        printf("%d",arr[i]);
        if(i==r){
            break;
        }
        i=(i+1)%max;
    }
}
int main(){
    int t;
    printf("Enter the terms:");
    scanf("%d",&t);
    
    int c;
    while(1){
        printf("\n");
        printf("Choice:");
        scanf("%d",&c);
        if(c==1){
            enqueue(t);
            //  printf("\n");
            print(t);
        }
        else if(c==2){
            dequeue(t);
            printf("\n");
               print(t);
        }
        else if(c==3){
            printf("Exit");
            break;
        }
        else{
            continue;
        }
    }
    
    return 0;
}
