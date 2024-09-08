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


int binarySearch(int a[], int len,int ele){
    int low =0,mid,high = len -1;
    while(low <=high){
        mid = (low+high)/2;
        if(a[mid] == ele){
        return mid;
        }
        else if(a[mid]<ele){
            low = mid +1;
        }
        else{
            high = mid -1;
        }
    }

}

int main(){
    int len,i,j,ele;
    printf("Enter length of array: ");
    scanf("%d",&len);
    int a[len];
    for(i = 0; i <len; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter the number to be searched: ");
    scanf("%d",&ele);
    bubbleSort(a,len);
    int pos = binarySearch(a,len,ele);
    if( pos != -1){
        printf("The position of the element is: %d",pos+1);
    }
    else{
        printf("Element not found");
    }
    return 0;
}




