#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int init(stack* p_stack, int n){
if(n<=0){
    return 0;
}
p_stack->top=0;
p_stack->max_size=n;
p_stack->array=malloc(n*sizeof(int));
if(p_stack->array==NULL){
    return 0;
}
return 1;

}

int push(stack* p_stack,int n){
    if((p_stack->top)==p_stack->max_size){
        return 0;
    }
    p_stack->array[p_stack->top+1]=n;
    p_stack->top++;

}

int pop(stack* p_stack,int n){
    if((p_stack->top)==0){
        
        return 0;
    }
    p_stack->top--;


}