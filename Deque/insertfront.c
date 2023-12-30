#include <stdio.h>
# define n 10
int deque[n], front=-1,rear=-1;
void insert_front(){
    int element;
    printf("Enter Element : ");
    scanf("%d",&element);
    if((front==0 && rear==n-1) || (front==rear+1))
    {
        printf("Overflow");
    }
      else if((front==-1) && (rear==-1))    
    {    
        front=rear=0;    
        deque[front]=element;    
    }    
    else if(front==0)    
    {    
        front=n-1;    
        deque[front]=element;    
    }    
    else    
    {    
        front=front-1;    
        deque[front]=element;    
    }    
}
void display()    
{    
    int i=front;    
    printf("\nElements in a deque are:\n");    
        
    while(i!=rear)    
    {    
        printf("Elements : %d\n",deque[i]);    
        i=(i+1)%n;    
    }    
     printf("Elements : %d",deque[rear]);    
}    
int main(){
    int num;
    printf("Enter Number of Elements : ");
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        insert_front();
    }
    display();
}