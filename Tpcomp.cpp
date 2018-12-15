#include<stdio.h>
#include "stack.h"
#include "help.h"




/*
next <- first token of the input
stack <- START_SYMBOL
do {
    top <- stack.pop()
    if (top is a terminal and top == next) {
        next <- next token of the input
    } else if (top is a non terminal and PARSING_TABLE[top, next] exists) {
        stack.push(PARSING_TABLE[top, next]);
    } else {
         return invalid input;
    }
} while (stack is not empty);
return valid input;
*/

int
main(void)
{

    char* start = (char*)malloc(sizeof(char)*10);
    strcpy(start,"S");
    //for the user input
    char* next = (char*)malloc(sizeof(char)*10);
    memset(next,0,sizeof(next));
    stack input;
    input.head = NULL;
    push(&input,"id");
    push(&input,"=");
    push(&input,"id");
    push(&input,"print");
    push(&input,"else");
    push(&input,"end");
    push(&input,"id");
    push(&input,"=");
    push(&input,"id");
    push(&input,"print");
    push(&input,";");
    push(&input,"id");
    push(&input,"=");
    push(&input,"id");
    push(&input,"print");
    push(&input,"begin");
    push(&input,"then");
    push(&input,"id");
    push(&input,"=");
    push(&input,"id");
    push(&input,"if");


    //for the parser stack
    stack st;
    st.head = NULL;
    push(&st,start);

    //str value
    char* top = (char*)malloc(sizeof(char)*10);
    memset(next,0,sizeof(next));
    strcpy(next,pop(&input));

    do
    {
        memset(top,0,sizeof(next));
        strcpy(top,pop(&st));

        if(is_terminal(top)!= -1 && !strcmp(top,next))
        {
            memset(next,0,sizeof(next));
            strcpy(next,pop(&input));
        } else if(non_terminal(top)!= -1 && check_rule(top,next))
        {
            push_rule(&st,get_rule(top,next));
        } else
        {
            goto doom;
        }
    }while(!is_empty(&st) && !is_empty(&input));
    printf("fucking valid input\n");

    return(0);
doom:
    printf("the input sucks and so are you a**hole\n");
    return(-1);
}

