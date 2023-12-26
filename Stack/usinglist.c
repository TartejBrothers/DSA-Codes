#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * next;
};

void display(struct node * ptr){
    while(ptr!=NULL){
        printf("Element = %d\n", ptr->data);
        ptr=ptr->next;
    }
}
struct node * push(struct node * ptr, int element){
 
    struct node * new;
    new =(struct node *) malloc(sizeof(struct node));

    new->next=ptr;
    new->data=element;
    return new;   
}
struct node * pop(struct node * head){
    struct node * ptr=head;
    head = head->next;
    free(ptr);
    return head;
}
int main(){
    struct node * head;
    struct node * second;
    struct node * third;

    // They are dyanmic, so their data is in the heap.
    head=NULL;
    head=(struct node *) malloc(sizeof(struct node));
    second=(struct node *) malloc(sizeof(struct node));
    third=(struct node *) malloc(sizeof(struct node));

    head-> data=2;
    head->next=second;
    second->data=3;
    second->next=third;
    third-> data=4;
    third->next=NULL;
    display(head);
    int element;
    printf("Enter Element : ");
    scanf("%d",&element);
    printf("After Insertion:\n");
    head= push(head,element);
    display(head);
    printf("After Deletion:\n");
    head=pop(head);
    display(head);
    return 0;
}
