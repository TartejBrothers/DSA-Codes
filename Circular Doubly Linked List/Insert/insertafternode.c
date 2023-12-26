#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

void display(struct node * head){
    struct node * ptr=head;
    // We use do while here so that it goes ahead once and then continues
    do{
        if(head!=NULL){
        printf("Element = %d\n", ptr->data);
        ptr=ptr->next;
        }
    }while(ptr!=head && ptr!=NULL);
}
struct node * insert(struct node * head, struct node * second, int element){
    struct node * new=(struct node *)malloc(sizeof(struct node));
    struct node * ptr=head;
    int len=0;
    do{
        if(head!=NULL){
        len=len+1;
        ptr=ptr->next;
        }
    }while(ptr!=head && ptr!=NULL);
    if (len>2){
    new->data=element;
        new->next=second->next;
        second->next=new;
        new->prev=second;
        return head;
    }
    else{
        return head;
    }
}
int main(){
    struct node * head;
    struct node * second;
    struct node * third;

    // They are dyanmic, so their data is in the heap.
    head=(struct node *) malloc(sizeof(struct node));
    second=(struct node *) malloc(sizeof(struct node));
    third=(struct node *) malloc(sizeof(struct node));

    head->data=2;
    head->next=second;
    second->data=3;
    second->next=third;
    third-> data=4;
    third->next=head;
    head->prev=third;
    second->prev=head;
    third->prev=second;
    display(head);
    int element;
    printf("Enter Element: ");
    scanf("%d",&element);
    head=insert(head,second, element);
    display(head);
    return 0;
}
