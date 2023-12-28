#include <stdio.h>
int main(){
    int a_row=3;
    int a_col=3;
    int b_row=3;
    int b_col=3;
    int a[3][3]={{1,2,3},{5,6,7},{8,9,0}};
    int b[3][3]={{1,2,3},{5,6,7},{8,9,0}};
    int c[3][3],sum;
    for (int i=0;i<a_row;i++){
        for(int j=0;j<b_col;j++){
            sum=0;
            for(int k=0;k<a_col;k++){
                sum=sum+(a[i][k]*b[k][j]);
                c[i][j]=sum;
            }
        }
    }
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}