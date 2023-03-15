#ifndef MATHIMATICSAPPSTACK_H
#define MATHIMATICSAPPSTACK_H

void InfixToPostfix(char infix[], char postfix[]);
int Precedent(char op1, char op2);
int IsDigit(char c);
double EvaluatePostfix(char expr[]);
double Oper(char c, double op1, double op2);

#endif