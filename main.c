#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <time.h>

stack copy_stack(const stack);
node* copy_list(const node*);
int main(){
srand(time(NULL));

stack st1;
printf("select stack size:\n");
int n;
scanf("%d",&n);
init(&st1,n);
printf("How many elements do you want to add?\n");
scanf("%d",&n);
for(int i=0;i<n;i++){
    if(!push(&st1,rand()%100)){
    printf("Could not add the %dth element\n",i+1);
    }
}
print_stack(st1);
printf("making a copy....\n");
stack st2=copy_stack(st1);

printf("Removing 5 elements from the original\n");
for(int i=0;i<5;i++){
    pop(&st1);
}
print_stack(st1);
print_stack(st2);
printf("\n");
printf("Making a list.....\n");
node* l=init_list();
for(int i=0;i<20;i++){
    push_list(&l,rand()%10);
}

print_list(l);

return 0;
}



stack copy_stack(const stack p_stack){
    stack tmp;
    init(&tmp,p_stack.max_size+1);
    for(int i=0;i<=p_stack.top;i++){
        push(&tmp,p_stack.array[i]);
    }
    return tmp;
}

node* copy_list(const node* p_list){
    node* tmp=init_list();
    while (p_list!=NULL)
    {
        push_list(&tmp,p_list->data);
        p_list=p_list->next;
        tmp=tmp->next;
    }
    
    return tmp;
}