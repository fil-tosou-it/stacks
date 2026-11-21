#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//ΑΡΧΙΚΟΠΟΙΕΙ ΤΗΝ ΣΤΟΙΒΑ ΜΕ ΤΗΝ ΧΡΗΣΗ POINTER
int init(stack* p_stack, int n){
if(n<=0){
    return 0;
}
p_stack->top=-1;
p_stack->max_size=n-1;
p_stack->array=malloc(n*sizeof(int));
if(p_stack->array==NULL){
    return 0;
}
return 1;

}


//ΠΡΟΣΘΕΤΕΙ ΕΝΑ ΣΤΟΙΧΕΙΟ ΣΤΟ ΤΕΛΟΣ ΤΗΣ ΛΙΣΤΑΣ 
//ΕΚΤΟΣ ΑΝ Ο ΠΙΝΑΚΑΣ ΕΙΝΑΙ ΓΕΜΑΤΟΣ ΤΟΤΕ ΕΠΙΣΤΡΕΦΕΙ 0
//ΤΟ P_STACK->ARRAY ΔΕΙΧΝΕΙ ΣΤΟ ΠΙΝΑΚΑ ΤΟΥ STRUCT STACK
//ΤΟ [P_STACK->TOP+1] ΔΕΙΧΝΕΙ ΣΤΟ ΠΡΩΤΟ ΚΕΝΟ ΣΤΟΙΧΕΙΟ ΤΟΥ ΠΙΝΑΚΑ

int push(stack* p_stack,int n){
    if((p_stack->top)==p_stack->max_size){
        return 0;
    }
    p_stack->array[p_stack->top+1]=n;
    p_stack->top++;
    return 1;
}
void print_stack(const stack p_stack){
printf("----------PRINTING STACK----------\n");
if(p_stack.top==-1){
    printf("EMPTY STACK\n");
    return;
}    

for(int i=0;i<=p_stack.top;i++){
    printf("[%d]",p_stack.array[i]);
}
printf("\n");

}

int pop(stack* p_stack){
    if((p_stack->top)==-1){
        free(p_stack->array);
        p_stack->array=NULL;
        return 0;
    }
    p_stack->top--;
    return 1;


}

//ΑΡΧΙΚΟΠΟΙΕΙ ΤΗΝ ΛΙΣΤΑ. ΤΟ ΠΡΩΤΟ ΣΤΟΙΧΕΙΟ ΤΗΣ ΛΙΣΤΑΣ ΔΕΝ ΕΧΕΙ ΔΕΔΟΜΕΝΑ ΓΙΑ ΝΑ ΕΠΙΤΡΕΠΕΤΑΙ Η ΔΗΜΙΟΥΡΓΙΑ ΑΔΕΙΑΣ ΛΙΣΤΑΣ. 
//ΤΟ ΣΤΟΙΧΕΙΟ ΠΑΡΑΜΕΝΕΙ ΠΑΝΤΑ ΚΕΝΟ ΚΑΙ ΜΟΝΟ ΚΑΝΕΙ POINT ΣΤΟ ΠΡΑΓΜΑΤΙΚΟ ΠΡΩΤΟ ΣΤΟΙΧΕΙΟ
node* init_list(){
    node* tmp=malloc(sizeof(node));
    tmp->next=NULL;
    return tmp;
}

int push_list(node** p_list,int n){
    node* new_element=malloc(sizeof(node));
    if(new_element==NULL){
        return 0;
    }
    
    new_element->data=n;
    new_element->next=NULL;
    
    
    node* tmp=*p_list;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=new_element;
    return 1;
}
//ΕΚΤΥΠΩΝΕΙ ΤA ΔΕΔΟΜΕΝΑ ΤΟΥ ΕΠΟΜΕΝΟΥ ΣΤΟΙΧΕΙΟΥ ΤΗΣ ΛΙΣΤΑΣ
//ΠΡΩΤΑ ΔΕΙΧΝΕΙ ΣΤΟ ΠΡΩΤΟ ΣΤΟΙΧΕΙΟ ΜΕΣΟΥ ΤΟΥ ΚΕΦΑΛΕΙΟΥ
//ΣΕ ΚΑΘΕ LOOP ΤΣΕΚΑΡΕΙ ΕΑΝ ΤΟ ΕΠΟΜΕΝΟ ΣΤΟΙΧΕΙΟ ΕΙΝΑΙ NULL
//ΕΑΝ ΟΧΙ ΤΟΤΕ ΕΚΤΥΠΩΝΕΙ ΤΑ ΔΕΔΟΜΕΝΑ ΤΟΥ ΕΠΟΜΕΝΟΥ ΚΑΙ Ο POINTER ΠΡΟΧΩΡΑΕΙ ΣΤΟ ΕΠΟΜΕΝΟ ΣΤΟΙΧΕΙΟ
void print_list(node* p_list){
    int i=1;
    printf("----------PRINTING LIST----------\n");
    while(p_list->next!=NULL){
        printf("[%d]",p_list->next->data);
        p_list=p_list->next;
        i++;
    }
    printf("\n");
}


int pop_list(node** p_list){
    node* tmp=*p_list;
    if(tmp->next==NULL){
        return 1;
    }
    while(tmp->next->next!=NULL){
        tmp=tmp->next;
    }
    free(tmp->next);
    tmp->next=NULL;
    return 1;
}