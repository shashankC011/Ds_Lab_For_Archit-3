#include<stdio.h>
struct student{
    char name[100];
    int rollno;
    char grade;
};

void read(struct student studs[],int studCount){
    int i;
    for(i = 0; i<studCount;i++){
        printf("Enter name for student %d: ",i+1);

        // Use getchar() to consume any leftover newline character from previous input
        getchar(); // This is important to clear the newline left by scanf
        // Read name using gets
        gets(studs[i].name);

        printf("Enter roll no for student %d: ",i+1);
        scanf("%d",&studs[i].rollno);
        // Consume the newline character left by scanf
        getchar();
        printf("Enter grade for student %d: ",i+1);
        scanf("%c",&studs[i].grade);
    }
}

void display(struct student studs[],int studCount){
    int i;
    for(i = 0;i<studCount;i++){
        printf("Name of the student is: %s \n",studs[i].name);
        printf("Roll no of the student is: %d \n",studs[i].rollno);
        printf("Grade of the student is: %c \n",studs[i].grade);
    }
}

void sort(struct student studs[],int studCount){
    int i,j;
    struct student temp;
    for(i = 0; i<studCount-1;i++){
        for(j=0; j<studCount-i-1;j++){
            if(studs[j].rollno>studs[j+1].rollno){
                 temp = studs[j];
                studs[j] = studs[j+1];
                studs[j+1] = temp;
            }
        }
    }
}

int main(){
    int studCount;
    printf("Enter number of students: ");
    scanf("%d",&studCount);
    struct student studs[studCount];
    read(studs,studCount);
    sort(studs,studCount);
    display(studs,studCount);
    return 0;
}
