#include<stdio.h>
#include<stdlib.h>    //provid the abs() function to calculate absolute difference

typedef struct Time
{
    int hour;
    int min;
    int sec;
}Time;

Time* addTime(Time *t1, Time *t2, Time *result){
    int totalSec = ((t1->hour)*3600) + ((t1->min)*60)+(t1->sec) +((t2->hour)*3600) + ((t2->min)*60)+(t2->sec);
    result-> hour = totalSec/3600;
    result->min = (totalSec%3600)/60;
    result->sec = totalSec%60;
    return result;
}

Time* TimeDiff(Time *t1, Time *t2, Time *result){
    int totalSec1 = ((t1->hour)*3600) + ((t1->min)*60)+(t1->sec);
    int totalSec2 = ((t2->hour)*3600) + ((t2->min)*60)+(t2->sec);
    int diffSec = abs(totalSec1-totalSec2);
    result-> hour = (diffSec)/3600;
    result->min = (diffSec%3600)/60;
    result->sec = diffSec%60;
    return result;
}

void display_Time(Time *t1){
    printf("%d:%d:%d\n",t1->hour,t1->min,t1->sec );
}

void read_Time(Time *t1){
    printf("Enter hours: ");
    scanf("%d",&t1->hour);
    printf("Enter min: ");
    scanf("%d",&t1->min);
    printf("Enter sec: ");
    scanf("%d",&t1->sec);
    printf("\n");
}

int main(){
    Time t1, t2,result;
    read_Time(&t1);
    read_Time(&t2);
    printf("Time object 1: ");
    display_Time(&t1);
    printf("Time object 2: ");
    display_Time(&t2);
    addTime(&t1,&t2,&result);
    printf("The result after submission: ");
    display_Time(&result);
    TimeDiff(&t1,&t2,&result);
    printf("The result after difference: ");
    display_Time(&result);
    return 0;
}
