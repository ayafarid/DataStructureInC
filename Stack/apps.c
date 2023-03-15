#include "stack.h"
void MoveDisks(int count, int start, int finish, int temp)
{

    if (count > 0)
    {
        MoveDisks(count - 1, start, temp, finish);

        printf("Move disk %d from %d to %d\n", count, start, finish);

        MoveDisks(count - 1, temp, finish, start);
    }
}
int Fibonacci(int n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (Fibonacci(n - 1) + Fibonacci(n - 2));
}
int Fibonacci(int n)
{
    int i;
    int twoback; // second previous number, F_i-2
    int oneback; // previous number, F_i-1
    int current; // current number, F_i
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
    { // n>=2
        twoback = 0;
        oneback = 1;
        for (i = 2; i <= n; i++)
        {
            current = twoback + oneback;
            twoback = oneback;
            oneback = current;
        }
        return current;
    }
}
void MoveDisks(int count, int start, int finish, int temp)
{
    if (count > 0)
    {
        Move(count - 1, start, temp, finish);
        printf("Move disk %d from %d to %d\n", count, start, finish);
        Move(count - 1, temp, finish, start);
    }
}

void MoveDisks(int count, int start, int finish, int temp)
{
    int swap;
    while (count > 0)
    { // instead of if condition
        MoveDisks(count - 1, start, temp, finish);
        printf("Move disk %d from %d to %d\n", count, start, finish);
        count--;
        swap = start;
        start = temp;
        temp = swap;
    }
}
void InfixToPostfix(char infix[], char postfix[])
{
    int i, j;
    char op, c;
    stack s;
    CreateStack(&s);
    for (i = 0, j = 0; (c = infix[i]) != '\0'; i++)
        if (IsDigit(c))
            postfix[j++] = c;
        else
        {
            if (!StackEmpty(&s))
            {
                StackTop(&op, &s);
                while (!StackEmpty(&s) && Precedent(op, c))
                {
                    Pop(&op, &s);
                    postfix[j++] = op;
                    if (!StackEmpty(&s))
                        StackTop(&op, &s);
                }
            }
            Push(c, &s);
        }
    while (!StackEmpty(&s))
    {
        Pop(&op, &s);
        postfix[j++] = op;
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
// void main(){
//    char infix[]="1+2*3$4/5+6";
//    char postfix[80];
//    InfixToPostfix(infix, postfix);
//    printf("\n %s", postfix);
//    getch();
// }
double EvaluatePostfix(char expr[]){
   int i;
   char c;
   double op1, op2, val;
   stack s;
	
   CreateStack(&s);
   for(i=0; (c=expr[i])!='\0'; i++)
      if(IsDigit(c))
         Push((double)(c-'0'), &s);
      else{
          Pop(&op2, &s);
          Pop(&op1, &s);
          val=Oper(c, op1, op2);
          Push(val, &s);
      }
    Pop(&val, &s);
    return val;
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



