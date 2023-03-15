#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include "..\Stack\stack.h"
#include "MathimaticsAppSatck.h"
void InfixToPostfix(char infix[], char postfix[])
{
    ElementType et,temp;
    int i, j;
    char c;
    Stack s;
    CreateStack(&s);
    for (i = 0, j = 0; (c = infix[i]) != '\0'; i++)
        if (IsDigit(c))
            postfix[j++] = c;
        else
        {
            if (!StackEmpty(&s))
            {
                StackTop(&et, &s);
                while (!StackEmpty(&s) && Precedent(et.info.par, c))
                {
                    Pop(&et, &s);
                    postfix[j++] = et.info.par;
                    if (!StackEmpty(&s))
                        StackTop(&et, &s);
                }
            }
            temp.info.par=c;
            Push(temp, &s);
        }
    while (!StackEmpty(&s))
    {
        Pop(&et, &s);
        postfix[j++] = et.info.par;
    }
    postfix[j] = '\0';
}
int Precedent(char op1, char op2)
{
    if (op1 == '$')
        return 1;

    if ((op1 == '*') || (op1 == '/'))
        return (op2 != '$');

    if ((op1 == '+') || (op1 == '-'))
        return ((op2 != '$') && (op2 != '*') && (op2 != '/'));

    return 0;
}
int IsDigit(char c)
{
    return (c >= '0' && c <= '9');
}
double EvaluatePostfix(char expr[]){
   int i;
   char c;
   double val;
   Stack s;
   ElementType et,op1,op2;
   CreateStack(&s);
   for(i=0; (c=expr[i])!='\0'; i++)
      if(IsDigit(c)){
        et.info.age=(double)(c-'0');
        Push(et, &s);
      }
      else{
          Pop(&op2, &s);
          Pop(&op1, &s);
          val=Oper(c, op1.info.age, op2.info.age);
          et.info.age=val;
          Push(et, &s);
      }
    Pop(&et, &s);
    return et.info.age;
}
double Oper(char c, double op1, double op2){
   switch(c){
	case '+': return(op1+op2);
	case '-': return(op1-op2);
	case '*': return(op1*op2);
	case '/': return(op1/op2);
	case '$': return(pow(op1,op2));
   }
}