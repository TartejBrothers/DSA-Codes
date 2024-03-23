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
struct node * delete (struct node * head, int val){
    struct node * ptr= head;
    struct node * ref=head->next;
    if (head->data==val && head->next==NULL){
        ptr=NULL;
        free(head);
        return ptr;
    }
    else if(head==NULL){
        return NULL;
    }
    else{
        int c=0;
        while(ptr!=NULL){
        ptr=ptr->next;
        c=c+1;
    }
    int arr[c];
    int len=0;
    for (int i=0; i<c-1; i++){
        if(ref->data==val){
        arr[len]=i;
        }
        else{
            ptr=ptr->next;
            ref=ref->next;
        }
    for (int i=0; i<len; i++){
      ptr=head; 
      ref=head->next;
      for (int j=0; j<arr[len]-1; j++){
          ptr->next=ref->next;
          free(ref);
          ptr=head;
          ref=head->next;
          for (int k=0; k<arr[len]-1; k++){
                arr[len]=arr[len]-1;
          }
      }
    }
    return head;
}
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
    struct node * fourth=(struct node *) malloc(sizeof(struct node));
    head-> data=2;
    head->next=second;
    second->data=4;
    second->next=third;
    third-> data=4;
    third->next=fourth;
    fourth-> data=5;
    fourth->next=NULL;
    display(head);
    int val;
    printf("Enter Element: ");
    scanf("%d", &val);
    head = delete(head, val);
    printf("After Deletion\n");
    display(head);
    return 0;
}
