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
struct node * delete(struct node * head, int element){
    struct node * ptr=head;
    struct node * ref;
    if(head==NULL){
        printf("Empty List\n");
        return NULL;
    }
    else if (head->next==NULL){
        return NULL;
    }
    else{
        while (ptr->data != element) {
            ref = ptr;
            ptr = ptr->next;
        }

        ref->next = ptr->next;
        ptr->next->prev = ref;
        if (ptr == head) {
            head = ref->next;
        }
        free(ptr);
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
    printf("Enter Element : ");
    scanf("%d", &element);
    head=delete(head, element);
    printf("After Deletion:\n ");
    display(head);
    return 0;
}
