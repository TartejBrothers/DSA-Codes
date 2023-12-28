#include <stdio.h>
void insert(int arr[],int n){
    int i, key, j;  
    for (i = 1; i < n; i++) {  
        key = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > key) {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}
void display(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("Element : %d\n",arr[i]);
    }
}
int main(){
    int n;
    printf("Enter Number of Elements to be Added: ");
    scanf("%d",&n);
    int arr[n]; 
    for (int i=0;i<n;i++){
        printf("Enter Element :");
        scanf("%d",&arr[i]);       
    }
    int size=sizeof(arr)/sizeof(arr[0]);
    insert(arr,size);
    display(arr,n);
}