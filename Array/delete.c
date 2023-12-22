#include <stdio.h>
void display(int arr[], int n){
    printf("Elements in the Array are:\n");
    for (int i=0;i<n;i++){
        printf("Element at index %d = %d\n", i, arr[i]);
    }
}
int Delete(int arr[], int size, int cap, int index){
    if (size>=cap){
        printf("Invalid");
        return -1;
    }
    else{
        for (int i=index; i<=size-1;i++){
            arr[i]=arr[i+1];
        }
        return 1;
    }

}
int main(){
    int arr[100]={20,50,60,40};
    int size=4;
    int cap=100;
    int index=2;
    int element=70;
    Delete(arr, size, cap, index);
    display(arr, size-1);
}