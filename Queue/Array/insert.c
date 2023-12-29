#include <stdio.h>
#define max 5
int queue[max];
int front=-1,rear=-1;
void insert(){
    int element;
    printf("Enter Element : ");
    scanf("%d", &element);
    if(rear==max-1){
        printf("Overflow");
    }
    else{
        if(front==-1 && rear==-1){
            front=0;
            rear=0;
        }
        else{
            rear=rear+1;
        }
        queue[rear]=element;
    }
}
void display(){
    int i;  
    if(rear == -1)  
    {  
        printf("Empty queue\n");  
    }  
    else{ 
        for(i=front;i<=rear;i++)  
        {  
            printf("Element : %d\n",queue[i]);  
        }     
    }  
}
int main(){
    int n;
    printf("Enter Number Of Elements : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        insert();
    }
    printf("After Insertion\n");
    display();
}