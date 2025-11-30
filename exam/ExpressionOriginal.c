#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
    int data;
    struct node* right;
    struct node* left;
};

char stack[50];
int top=-1;
void push(char ch){
stack[++top]=ch;
}

char pop(){
    return stack[top--];
}
int precedence(char op){
    if(op=='^')return 3;
    else if(op=='*' || op=='/')return 2;
    else if(op=='+' || op=='-')return 1;
    return 0;
    
    
}

int isright(char op){
    return op=='^';
}
void convert(char infix[],char postfix[]){
    int i=0,k=0;
    char ch;
    while(infix[i]!='\0'){
        ch=infix[i];
        if(ch=='('){
            push(ch);
        }
        else if(isalnum(ch)){
            postfix[k++]=ch;
        }
        
        else if(ch==')'){
            while(stack[top]!='('){
                postfix[k++]=pop();
            }
            pop();
        }
        else{
    while(top!=-1 && precedence(stack[top])>precedence(ch)||
        (precedence(stack[top])==precedence(ch) && !isright(ch))){
                
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
struct node* newNode(char ch){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ch;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
    
}
struct node* build(char postfix[]){
    int i=0;
    struct node* stackNode[100];
    int topNode=-1;
    char ch;
    while(postfix[i]!='\0'){
        ch=postfix[i];
        if(isspace(ch))continue;
       else  if(isalnum(ch)){
            stackNode[++topNode]=newNode(ch);
                
        }
        else{
            struct node* right=stackNode[topNode--];
            struct node* left=stackNode[topNode--];
            struct node* n=newNode(ch);
            n->left=left;
            n->right=right;
            stackNode[++topNode]=n;
        }
        i++;
        
    }
    return stackNode[topNode];
    
}
void postOrder(struct node* root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        printf("%c",root->data);
       
    }
}
void preOrder(struct node* root){
    if(root){
         printf("%c",root->data);
        preOrder(root->left);
        preOrder(root->right);
       
       
    }
}

int main(){
    
    char infix[50],postfix[50];
    printf("Enter the infix:");
    scanf("%s",infix);
    
    convert(infix,postfix);
    struct node* root=build(postfix);
//   printf("%s",postfix);
postOrder(root);
  preOrder(root);
    return 0;
    
    
    
}
