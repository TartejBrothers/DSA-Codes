#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * next;
    struct node * prev;
};
void display(struct node * head){
    struct node * ptr=head;
    while(ptr!=NULL ){
        printf("Elements are : %d\n", ptr->data);
        ptr=ptr->next;
    }
}
struct node * insert(struct node * head, struct node * second, int element){
    struct node * ptr= head;
    struct node * new=(struct node *) malloc(sizeof(struct node ));
    while (ptr->next!=second){
        ptr=ptr->next;
    }
    ptr->next=new;
    new->data=element;
    new->prev=ptr;
    new->next=second;
    return head;
}
int main(){
    struct node * head= (struct node *) malloc(sizeof(struct node ));
    struct node * second= (struct node *) malloc(sizeof(struct node ));
    struct node * third= (struct node *) malloc(sizeof(struct node ));
    head->data=2;
    second->data=3;
    third->data=4;
    head->next=second;
    second->next=third;
    third->next=NULL;
    head->prev=NULL;
    second->prev=head;
    third->prev=second;
    display(head);
    int element;
    printf("Enter Element: ");
    scanf("%d", &element);

    head=insert(head,second, element);
    printf("After Insertion: \n");
    display(head);
    return 0;
}