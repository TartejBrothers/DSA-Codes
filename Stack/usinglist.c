#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * next;
};

void display(struct node * head){
    if (head == NULL)
       return;
    display(head->next);
    printf("Element : %d\n", head->data);
}

struct node * push(struct node * ptr, int element){
 
    struct node * new;
    new =(struct node *) malloc(sizeof(struct node));

    new->next=ptr;
    new->data=element;
    return new;   
}
struct node * pop(struct node * head){
    struct node * ptr = head;
    struct node * ref= head->next;

    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return NULL; 
    }
    while(ref->next!=NULL){
        ptr=ptr->next;
        ref=ref->next;

    }
    ptr->next=NULL;
    free(ref);
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
