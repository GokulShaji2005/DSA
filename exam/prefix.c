#include<stdio.h>
#include<ctype.h>
#include<string.h>
    char stack[30];
        int top=-1;
void push(char ch){
    stack[++top]=ch;
}

char pop(){
    return stack[top--];
}

int precedence(char ch){
    if(ch=='^')return 3;
    else if(ch=='*' || ch=='/')return 2;
    else if(ch=='+' || ch=='-')return 1;
    return 0;
    
}

int isright(char ch){
    return ch=='^';
}

void convert(char infix[],char postfix[]){
    int i=0,k=0;


    while(infix[i]!='\0'){
          char ch=infix[i];
         if(isalnum(ch)){
            postfix[k++]=ch;
        }
     
        else if(ch=='('){
            push(ch);
        }
        
        else if(ch==')'){
            while(stack[top]!='('){
                postfix[k++]=pop();
            }
            pop();
        }
        
        else{
            if( top!=-1 && precedence(stack[top])>precedence(ch) || precedence(stack[top])==precedence(ch)&& !isright ){
                postfix[k++]=pop();
            }
            push(ch);
        }
        i++;
        
    }
    
    while(top!=-1){
        postfix[k++]=pop();
    }
    postfix[k]='\0';
}
void reverse(char arr[]){
    int i,j,temp;
    j=strlen(arr)-1;
    for(int i=0;i<j;i++,j--){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}
int main(){
    char infix[30],postfix[30],reversed[30],prefix[30];
    printf("Enter the exp:");
    scanf("%s",infix);
    strcpy(reversed,infix);
    reverse(reversed);
    
    for(int i=0;reversed[i]!='\0';i++){
        if(reversed[i]=='('){
            reversed[i]=')';
        }
        
        else if(reversed[i]==')'){
            reversed[i]='(';
        }
    }
    
     top=-1;
   
    convert(reversed,postfix);
     strcpy(prefix,postfix);
     reverse(prefix);
    printf("%s",prefix);
    
    return 0;
}
