/**
 * Deletes the last node from a doubly linked circular list.
 *
 * @param head Pointer to the head node of the list.
 * @return Pointer to the new head node after deletion.
 */
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void display(struct node *head)
{
    struct node *ptr = head;
    // We use do while here so that it goes ahead once and then continues
    do
    {
        printf("Element = %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head && ptr != NULL);
}
struct node * delete(struct node *head, int element)
{
    struct node *ptr = head;
    struct node *ref;

    if (head == NULL)
    {
        printf("Empty List\n");
        return NULL;
    }
    else if (head->data == element)
    {
        head=head->next;
        if (head != NULL){
            head->prev = NULL;
    }
        free(ptr);
        return head;
    }
    else
    {
       while(ptr->data!=element){
        ptr=ptr->next;
        if(ptr->next==NULL){
            printf("Element Not Found\n");
            return head;
        }
    }
        ref=ptr->prev;
        ref->next = ptr->next;
        free(ptr);
        return head;
    }
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    head->data = 2;
    second->data = 3;
    third->data = 4;
    head->next = second;
    second->next = third;
    third->next = NULL;
    head->prev = NULL;
    second->prev = head;
    third->prev = second;
    display(head);
    int element;
    printf("Enter Element: ");
    scanf("%d", &element);
    head = delete (head, element);
    printf("After Deletion\n");
    display(head);
    return 0;
}
