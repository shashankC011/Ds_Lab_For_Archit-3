#include<stdio.h>
int main(){
    int row1,col1,row2,col2,row3,col3,i,j;
    printf("Enter number of rows and columns for first array: ");
    scanf("%d %d",&row1,&col1);
    int a[row1][col1];
    for(i = 0; i <row1; i++){
            for(j = 0;j<col1;j++){
                printf("Enter element R%d C%d: ", i+1, j+1);
                scanf("%d",&a[i][j]);
            }
    }

    printf("Enter number of rows and columns for second array: ");
    scanf("%d %d",&row2,&col2);
    int b[row2][col2];
    for(i = 0; i <row2; i++){
            for(j = 0;j<col2;j++){
                printf("Enter element R%d C%d: ", i+1, j+1);
                scanf("%d",&b[i][j]);
            }
    }
    if(row1>row2){
        row3 = row1;
    }

    else{
        row3 = row2;
    }

        if(col1>col2){
        col3 = col1;
    }

    else{
        col3 = col2;
    }
    int c[row3][col3];

    for(i = 0; i<row3;i++){
        for(j = 0; j<col3; j++){
                if(a[i][j]>b[i][j]){
                    c[i][j] = a[i][j];
                }
                else{
                    c[i][j]=b[i][j];
                }
        }
    }

    printf("The final array is: \n");
     for(i = 0; i<row3;i++){
        for(j = 0; j<col3; j++){
                printf("%d \t",c[i][j]);
        }
        printf("\n");
     }
}

