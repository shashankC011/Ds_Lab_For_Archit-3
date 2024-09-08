#include<stdio.h>
void insertionSort(int arr[], int n) {
    int i, j, key;

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


int main(){
    int len,i,j;
    printf("Enter length of array: ");
    scanf("%d",&len);
    int a[len];
    for(i = 0; i <len; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d",&a[i]);
    }
    insertionSort(a,len);
    printf("Sorted array is: \n");
    for(i = 0;i < len; i++){
        printf("%d \t",a[i]);
    }
    return 0;
}

