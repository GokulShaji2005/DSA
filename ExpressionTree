#include <stdio.h> 

 #include <stdlib.h> 

 #include <ctype.h> 

#define MAX 100 

struct Node { char data;  

struct Node *left, *right; }; 

struct Node* nodeStack[MAX];  

int topNode = -1; 

char opStack[MAX];  

int topOp = -1; 

struct Node* newNode(char data) {  

struct Node* node = (struct Node*)malloc(sizeof(struct Node));  

node->data = data;  

node->left = node->right = NULL;  

return node; } 

void pushNode(struct Node* node) {  

nodeStack[++topNode] = node; } 

struct Node* popNode() {  

return nodeStack[topNode--];  

} 

 

void pushOp(char op) {  

opStack[++topOp] = op; } 

char popOp() {  

return opStack[topOp--]; } 

char peekOp()  

{ return opStack[topOp]; } 

int precedence(char op) { 

 if (op == '+' || op == '-')  

return 1; 

 if (op == '*' || op == '/')  

return 2; 

 return 0; } 

void makeSubtree() {  

char op = popOp();  

struct Node* right = popNode(); 

 struct Node* left = popNode();  

struct Node* new = newNode(op);  

new->left = left; 

 new->right = right; 

 pushNode(new); } 

struct Node* buildTree(char infix[]) { 

 for (int i = 0; infix[i] != '\0'; i++) {  

char c = infix[i];  

if (isspace(c)) continue;  

if (isalnum(c))  

{ pushNode(newNode(c)); 

 } else if (c == '(') {  

pushOp(c); }  

else if (c == ')') { 

 while (topOp != -1 && peekOp() != '(')  

makeSubtree(); popOp();  

} else { 

 while (topOp != -1 && precedence(peekOp()) >= precedence(c)) 

 makeSubtree();  

pushOp(c); } } 

 while (topOp != -1)  

makeSubtree(); 

 return popNode(); } 

void postorder(struct Node* root) {  

if (root != NULL) { 

 postorder(root->left); 

 postorder(root->right);  

printf("%c", root->data); } } 

int main() {  

char infix[MAX]; 

 printf("Enter infix expression: ");  

gets(infix);  

struct Node* root = buildTree(infix); 

 printf("\nExpression Tree");  

postorder(root); 

 printf("\n");  

return 0; }
