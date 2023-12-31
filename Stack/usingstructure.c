#include <stdio.h>
#include <stdlib.h>

struct stack{
    int top;
    int size;
    int * arr;
};
int isEmpty(struct stack* ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack* ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack* ptr){
    int element;
    printf("Enter Element: ");
    scanf("%d", &element);
    if(isFull(ptr)){
        printf("Stack Full");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=element;
    }
  
}
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Empty");
        return 0;
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
void display(struct stack* ptr){
    for (int i=ptr->top;i>=0;i--){
        printf("Element : %d\n", ptr->arr[i]);
    }
}
void peek(struct stack* ptr, int index){
    if (ptr->top-index-1<0){
        printf("Position is invalid\n");
    }
    else{
    printf("Element at position %d is : %d\n",index, ptr->arr[(ptr->top-index+1)]);
    }
}
int stackTop(struct stack* ptr){
    return ptr->arr[ptr->top];
}
int stackBottom(struct stack *ptr){
    return ptr->arr[0];
}
int main(){
    struct stack * s=(struct stack *) malloc(sizeof(struct stack));
    s->top=-1;
    s->size=100;
    s->arr=(int *)malloc(s->size* sizeof(int));
    int num;
    printf("Enter Number Of elements : ");
    scanf("%d",&num);
    for (int i=0;i<num;i++){
        push(s);
    }
    display(s);
    int a=pop(s);
    printf("Popped Element : %d\n", a);
    
    printf("After Popping: \n");
    display(s);
    peek(s,1);
    int t=stackTop(s);
    int b=stackBottom(s);
    printf("Top:%d\n",t);
    printf("Bottom:%d\n",b);
    return 0;
}