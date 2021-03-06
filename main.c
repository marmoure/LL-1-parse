#include<stdio.h>
#include "stack.h"
#include "help.h"

int
main(void)
{

    char* start = (char*)malloc(sizeof(char)*10);
    strcpy(start,"S");
    //for the user input
    char* next = (char*)malloc(sizeof(char)*10);
    memset(next,0,sizeof(next));
    FILE* fp = fopen("input","r");
    int oef = 0;

    //for the parser stack
    stack st;
    st.head = NULL;
    push(&st,start);

    //str value
    char* top = (char*)malloc(sizeof(char)*10);

    get_next(fp,&oef,next);
    do
    {
        memset(top,0,sizeof(top));
        strcpy(top,pop(&st));

        if(is_terminal(top)!= -1 && !strcmp(top,next))
        {
            memset(next,0,sizeof(next));
            get_next(fp,&oef,next);
        } else if(non_terminal(top)!= -1 && check_rule(top,next))
        {
            push_rule(&st,get_rule(top,next));
        } else
        {
            goto doom;
        }
    }while(!is_empty(&st) && !oef);
    printf("valid input\n");
    fclose(fp);

    return(0);
doom:
    fclose(fp);
    printf("the input sucks and so are *******\n");
    return(-1);
}

