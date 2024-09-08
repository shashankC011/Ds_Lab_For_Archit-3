#include <stdio.h>
void selectionSort(int a[],int len){
    int i,j,minIndex,temp;
    for(i = 0; i<len-1;i++){
            minIndex = i;
        for(j = i + 1 ; j <len;j++){
            if(a[j]<a[minIndex]){
                minIndex = j;
            }
        }
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
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
    selectionSort(a,len);
    printf("Sorted array is: \n");
    for(i = 0;i < len; i++){
        printf("%d \t",a[i]);
    }
    return 0;
}
