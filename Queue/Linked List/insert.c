#include <stdio.h>
#include <stdlib.h>
struct node{
    int data; 
    struct node * next;
};
struct node * front;
struct node * rear;
void insert(){
    struct node * new=(struct node *)malloc(sizeof(struct node));
    if (new==NULL){
        printf("Overflow");
    }
    else{
        printf("Enter Element : ");
        scanf("%d", &new->data);
        new->next=NULL;
        if (front==NULL){
            front=new;
            rear=new;
        }
        else{
            rear->next=new;
            rear=new;
        }
    }
}
void display(){
    struct node * ptr=front;
    if(front==NULL){
        printf("Empty Queue");
    }
    else{
        while(ptr!=NULL){
            printf("Element : %d\n", ptr->data);
            ptr=ptr->next;
        }
    }
}
int main(){
    int n;
    printf("Enter Number Of Elements: ");
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        insert();
    }
    printf("After Insertion:\n");
    display();
}