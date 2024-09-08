#include<stdio.h>
#include<math.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int strLength(char a[]){
    int i,length = 0;
    for(i = 0;a[i]!='\0';i++){
        length++;
    }
    return length;
}

void strConcat(char dest[],char a[],char b[] ){
    int i,j;
    for(i = 0;a[i]!= '\0';i++){
        dest[i] = a[i];
    }
    for(j = 0;b[j] != '\0';j++){
        dest[i+j] = b[j];
    }
    dest[i+j] = '\0';
}

int strComp(char a[],char b[]){
    int i;
    int len1 = strLength(a);
    int len2 = strLength(b);
    int len = MIN(len1,len2);
    int disSimilar = 0;
    for(i = 0;i<len;i++){
        if(a[i] == b[i]){
            disSimilar = 1;
        }
        else if(a[i]>b[i]){
            return 1;
        }
        else{
            return -1;
        }
    }
    if(disSimilar == 1){
        return 0;
    }
}

int main(){
    char str1[100];
    printf("Enter a string: ");
     if (fgets(str1, 100, stdin) != NULL) {
        //To Remove newline character(because fgets takes \n from the input as well)

        int len = strLength(str1);
        if (len > 0 && str1[len - 1] == '\n') {
            str1[len - 1] = '\0';
        }
        printf("Length of the string: %d\n", strLength(str1));
    } else {
        printf("Error or end-of-file reached.\n");
    }

    char str2[100];
    printf("Enter another string: ");
    if (fgets(str2, 100, stdin) != NULL) {
        int len = strLength(str2);
        if (len > 0 && str2[len - 1] == '\n') {
            str2[len - 1] = '\0';
        }
        else {
        printf("Error or end-of-file reached.\n");
    }
    char result[200];
    strConcat(result,str1,str2);
    printf("The concat of the two strings is: %s \n",result);
    printf("The comparison of the two strings is: %d \n",strComp(str1,str2));
    return 0;
    }
}
