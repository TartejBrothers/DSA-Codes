#include <stdio.h>
void display(int arr[], int n){
    printf("Elements in the Array are:\n");
    for (int i=0;i<n;i++){
        printf("Element at index %d = %d\n", i, arr[i]);
        
    }
}
int main(){
    int arr[100]={20,50,60};
    int cap=100;
    int element=70;
    
    display(arr, 4);
}