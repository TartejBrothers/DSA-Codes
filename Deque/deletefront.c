#include <stdio.h>
# define n 10
int deque[n], front=-1,rear=-1;
void insert_rear(){
    int element;
    printf("Enter Element : ");
    scanf("%d",&element);
    if((front==0 && rear==n-1) || (front==rear+1))
    {
        printf("Overflow");
    }
      else if((front==-1) && (rear==-1))    
    {    
        rear=0;    
        deque[rear]=element;    
    }    
    else if(rear==n-1)    
    {    
        rear=0;    
        deque[rear]=element;    
    }    
    else    
    {    
        rear=rear+1;
        deque[rear]=element;    
    }    
}
void display() {
    if (front == -1 && rear == -1) {
        printf("\nDeque is empty\n");
    }
    printf("\nElements in a deque are:\n");
    for (int i = front+1; i <= rear; i++) {
        printf("Element: %d\n", deque[i]);
    }
}
void delete_front(){
    if(front==-1 && rear==-1){
        printf("Empty Deque");
    }
    else if(front==0 && rear==0){
        rear=-1;
        front=-1;
    }
    else if(front==n-1)    
     {       
         front=0;    
     }    
     else    
     {    
          front=front+1;    
     }  
     printf("After Deletion:\n");
     display();
}
int main(){
    int num;
    printf("Enter Number of Elements : ");
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        insert_rear();
    }
    display();
    delete_front();
}