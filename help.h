#ifndef HELP_H
#define HELP_H
#include <string.h>
#include "stack.h"
#include <stdio.h>
int is_terminal(const char *str)
{
    char termianls[11][6] = {
        "if",
        "then",
        "else",
        "begin",
        "print",
        "end",
        ";",
        "id",
        "=",
        "$"
    };

    for(int index = 0;index<10;index++)
    {
        if(strcmp(str,termianls[index]) == 0)
        {
            return index;
        }
    }
    return -1;
}


int non_terminal(const char *str)
{
    char termianls[3][2] = {
        "S",
        "L",
        "E",
    };

    for(int index = 0;index<3;index++)
    {
        if(!strcmp(str,termianls[index]))
        {
            return index;
        }
    }
    return -1;
}


int check_rule(const char* nonT,const char* terminal)
{
    int Tindex = is_terminal(terminal);
    int nTindex = non_terminal(nonT);

    int rules[3][10] = {
        {1,0,0,1,1,0,0,0,0,0},
        {0,0,0,1,0,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,0,0},
    };
    if(rules[nTindex][Tindex])
    {
        return(1);
    }
    return(0);
}

int get_rule(char *nonT,char *terminal)
{
    int Tindex = is_terminal(terminal);
    int nTindex = non_terminal(nonT);

    int rules[3][10] = {
        {1,0,0,2,3,0,0,0,0,0},
        {0,0,0,5,0,4,6,0,0,0},
        {0,0,0,0,0,0,0,7,0,0},
    };
    if(rules[nTindex][Tindex])
    {
        return(rules[nTindex][Tindex]);
    }
    return(0);
}

int push_rule(stack* st,int rule)
{
    switch(rule)
    {
        case 1:
            {
                push(st,"S");
                push(st,"else");
                push(st,"S");
                push(st,"then");
                push(st,"E");
                push(st,"if");
            }break;
        case 2:
            {
                push(st,"L");
                push(st,"S");
                push(st,"begin");
            }break;
        case 3:
            {
                push(st,"E");
                push(st,"print");
            }break;
        case 4:
            {
                push(st,"end");
            }break;
        case 5:
            {
                push(st,"L");
                push(st,"S");
                push(st,"begin");
            }break;
        case 6:
            {
                push(st,"L");
                push(st,"S");
                push(st,";");
            }break;
        case 7:
            {
                push(st,"id");
                push(st,"=");
                push(st,"id");
            }break;
        default:
            return(-1);
    }
    return(0);
}


#endif

