#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <string.h>


typedef struct node {
    char word[10];
    struct node* next;  
}node;

typedef struct stack {
    node* head;
}stack;

void push(stack* st,const char* word)
{
    if(!st) exit(99);
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->word,word);
    if(!st->head)
        new_node->next = NULL;
    else
        new_node->next = st->head;
    st->head = new_node; 
}

char* pop(stack* st)
{
    node* temp = st->head;
    st->head = st->head->next;
    temp->next = NULL;
    char *s = (char*)malloc(sizeof(char)*10);
    strcpy(s,temp->word);
    free(temp);
    return s;
}

int is_empty(stack* st)
{
   if(!st || !st->head) return 1;
   return 0;
}

char* peek(stack* st)
{
    return(st->head->word);   
}

#endif

