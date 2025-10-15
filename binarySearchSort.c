#include<stdio.h>

void main(){

int arr[20];
int n,key,s=0,flag=0,count=3;

printf("Enter the number of terms:");
scanf("%d",&n);
count++;
printf("Enter the numbers ");
for(int i=0;i<n;i++){
scanf("%d",&arr[i]);
count++;
}

printf("Enter the number to be searched:");
scanf("%d",&key);
count++;

printf("\n");
int e=n-1,m;
while(s<=e)
{
m=(s+e)/2;
if(arr[m]==key){
printf("The number %d is in %d index",arr[m],m);
flag=1;

break;
count++;
}
if(key>arr[m])
{
s=m+1;
count++;
}

else if(key<arr[m])
{
e=m-1;
count++;
}
}
if(flag==0){
printf("The %d is not found",key);
count++;
}
printf("\n");
int space=8*4+n*4;
printf("The space complexity: %d",space);
printf("\n");
printf("Time Complexity: %d",count);

}


