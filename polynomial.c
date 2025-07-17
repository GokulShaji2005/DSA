#include<stdio.h>



int main(){

int i,j,k,t1,t2;
struct polynomial{
       int exp;
       int coeff; 
}poly1[10],poly2[10],poly3[10];

   
   printf("Enter the t1 terms:");
  scanf("%d",&t1);
   printf("Enter the t2 terms:");
scanf("%d",&t2);
   
   printf("The first polynomial:");
   printf("\n");
   for(i=0;i<t1;i++)
   {
     printf("Enter the %d coefficient:",i+1);
     scanf("%d",&poly1[i].coeff);
     
      printf("Enter the %d exponent:",i+1);
     scanf("%d",&poly1[i].exp);
   }
   printf("The second polynomial:");
    printf("\n");
     for(j=0;j<t2;j++)
   {
     printf("Enter the %d coefficient:",j+1);
     scanf("%d",&poly2[j].coeff);
     
      printf("Enter the %d exponent:",j+1);
     scanf("%d",&poly2[j].exp);
   }
   
 for(i=0;i<t1;i++){
 if(i<t1-1)
 {
 printf("%d(x)^%d +",poly1[i].coeff,poly1[i].exp);
 
 }  
 else{
 printf("%d(x)^%d",poly1[i].coeff,poly1[i].exp);
 }
   }
   
   printf("\n");
 for(j=0;j<t2;j++){
 if(j<t2-1)
 {
 printf("%d(x)^%d +",poly2[j].coeff,poly2[j].exp);
 
 }  
 else{
 printf("%d(x)^%d",poly2[j].coeff,poly2[j].exp);
 }
   }  
        printf("\n");
   i=0,j=0,k=0;
   
   while(i<t1 && j<t2){
    
    if(poly1[i].exp==poly2[j].exp){
    poly3[k].coeff=poly1[i].coeff+poly2[j].coeff;
    poly3[k].exp=poly1[i].exp;
    i++,j++,k++;
    }

else if(poly1[i].exp>poly2[j].exp){
poly3[k].coeff=poly1[i].coeff;
poly3[k].exp=poly1[i].exp;
i++,k++;
}

else if(poly1[i].exp<poly2[j].exp){
poly3[k].coeff=poly2[j].coeff;
poly3[k].exp=poly2[j].exp;
j++,k++;
}
}
  
  while(i<t1)
  {
   poly3[k].coeff=poly1[i].coeff;
     poly3[k].exp=poly1[i].exp;
     i++,k++;
  }  
   while(j<t2)
  {
   poly3[k].coeff=poly2[j].coeff;
     poly3[k].exp=poly2[j].exp;
     j++,k++;
  } 
  
   for(int l=0;l<k;l++){
   
   if(l<k-1){
   printf("%d(x)^%d +",poly3[l].coeff,poly3[l].exp);
   
   }
   
   else{
   printf("%d(x)^%d",poly3[l].coeff,poly3[l].exp);
   }
   }
   
   return 0;
}
