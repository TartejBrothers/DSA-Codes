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
struct node * insert(struct node * head, int index, int element){
    struct node * ptr= head;

    struct node * new=(struct node *) malloc(sizeof(struct node ));

    for(int i=0; i<index-1;i++){
        ptr=ptr->next;
    }
    // ptr->data = item;  
    //    ptr->next = temp->next;  
    //    ptr -> prev = temp;  
    //    temp->next = ptr;  
    //    temp->next->prev=ptr;  
    // temp=ptr;  ptr=new;
    new->data=element;
    new->next=ptr->next;
    new->prev=ptr;
    ptr->next=new;
    ptr->next->prev=new;
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
    int element,index;
    printf("Enter Element: ");
    scanf("%d", &element);
    printf("Enter Index: ");
    scanf("%d", &index);
    head=insert(head,index, element);
    printf("After Insertion: \n");
    display(head);
    return 0;
}