#include <stdio.h>

int main()
{
    int n,i,ele,pos = -1;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
                printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }
    printf(" What to search? ");
    scanf("%d",&ele);
    for(i=0;i<n;i++){
        if(a[i]==ele)
        {
            pos = ele;
        }
    }
    if( pos != -1)
        printf("Position of element is: %d" ,pos);
    else
        printf("Element not found");
}

