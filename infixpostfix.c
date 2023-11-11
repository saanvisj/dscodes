
#include <stdio.h>
#include <ctype.h>
#include <math.h>
int stack[50], top=-1;
void push(int elem)
{
stack[++top]=elem;
}
void main()
{
char postfix[50],ch;
int i=0,op1,op2;
printf("Enter a Suffix expression with single digit operands and operators:");
scanf("%s",postfix);
while((ch=postfix[i++])!='\0')
{
if(isalpha(ch))
{
printf("Invalid expression\n");
return;
}
else if(isdigit(ch))
push(ch-48);
else
{
op2=stack[top--];
if(top<=-1)
{
printf("Invalid Expression\n");
return;
}
op1=stack[top--];
switch(ch)
{
case '+': push(op1+op2);
 break;
case '-': push(op1-op2);
 break;
case '*': push(op1*op2);
 break;
case '/': push(op1/op2);
 break;
case '%': push(op1%op2);
 break;
case '^': push(pow(op1,op2));
 break;
default: printf("Invalid operator\n");
 return;
}
}
}
if(top!=0)
printf("invalid expression\n");
else
printf("Result = %d\n",stack[top]);
}