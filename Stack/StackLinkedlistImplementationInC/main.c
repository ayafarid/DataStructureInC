#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "stack.h"
void Display(StackEntry e){
    printf("Element valeo: %d\n",e);
}
int main(){
    stack s;
    CreateStack(&s);
    StackEntry e=1;
    Push(e,&s);
    StackTop(&e,&s);
    Display(e);
    e=2;
    Push(e,&s);
    e=3;
    Push(e,&s);
    e=4;
    Push(e,&s);
    e=5;
    Push(e,&s);
    e=6;
    Push(e,&s);
    Pop(&e,&s);
    Pop(&e,&s);
    TraverseStack(&s,&Display);
}