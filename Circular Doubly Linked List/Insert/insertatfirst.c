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
        ptr=ptr->next;}
    }while(ptr!=head && ptr!=NULL);
}
struct node * insert(struct node * head, int element){
    struct node * new=(struct node *)malloc(sizeof(struct node));
    struct node * ptr=head;
    new->data=element;
    if(head==NULL){
        new->prev=new;
        new->next=new;
        head=new;
        return head;
    }
    else if (head->next==head){
        head->next=new;
        new->prev=head;
        new->next=head;
        head->prev=new;
        return new;
    }
    else{
        new->prev=head->prev;
        new->next=head->next;
        while (ptr!=head){
            ptr=ptr->next;
        }
        head->prev=new;
        ptr->next=new;
        return new;
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
    head=insert(head,element);
    display(head);
    return 0;
}
