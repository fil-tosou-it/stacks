#ifndef stack_h
#define stack_h

typedef struct{

int* array;
int top;
int max_size;

} stack;

int init(stack*,int);
int push(stack*,int);
int pop(stack*); 


#endif