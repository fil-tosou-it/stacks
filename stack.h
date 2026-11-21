#ifndef stack_h
#define stack_h

typedef struct{

int* array;
int top;
int max_size;

} stack;

typedef struct node{
    int data;
    struct node* next;
} node;

int init(stack*,int);
int push(stack*,int);
void print_stack(const stack);
int pop(stack*); 

node* init_list();
int push_list(node**,int);
void print_list();
int pop_list(node**);

#endif