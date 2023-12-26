#include <stdio.h>
#define n 100
int stack[n],top=-1;
void push(){
        top++;
        printf("Enter Element: ");
        scanf("%d",&stack[top]);
}
void display(){
    if (top==-1){
        printf("Stack is Empty : ");
    }
    else{ 
        for (int i=top;i>=0;i--){
            printf("Enter Element: %d\n", stack[i]);
        }
    }
}
void pop(){
    top=top-1;
}
int main(){
    int elements;
    printf("Enter Number of Elements : ");
    scanf("%d", &elements);
    for (int i=0;i<elements;i++){
        push(); 
    }
    pop();
    display();
    return 0;
}