#include<stdio.h>
void bubbleSort(int arr[],int len){
    int i,j,temp;
    for(i = 0; i <len-1;i++){
        for(j = 0; j < len-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int len,i,j;
    printf("Enter length of array: ");
    scanf("%d",&len);
    int a[len];
    for(i = 0; i <len; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d",&a[i]);
    }
    bubbleSort(a,len);
    printf("Sorted array is: \n");
    for(i = 0;i < len; i++){
        printf("%d \t",a[i]);
    }
}



