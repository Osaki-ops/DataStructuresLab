#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"Stack_adt.h"

struct Student
{
    int rollNo;
    char name[50];
    float midMarks;
};

struct Student* Rev_student(struct Student* student, int size)
{
    struct stack* Stack;
    Stack = (struct stack*)malloc(sizeof(struct stack));
    Stack = create_stack();

    for (int i = 0; i < size; i++)
    {
        pushStack(Stack, student[i].rollNo);
    }

    struct Student* Rev_stu;
    Rev_stu = (struct Student*)malloc(size * sizeof(struct Student));

    for (int i = 0; i < size; i++)
    {
        int val = popStack(Stack);
        Rev_stu[i] = student[val - 1];
    }

    return Rev_stu;
}

void Disp_StudentL(struct Student* Rev_stu, int size)
{
    printf("Displaying Student List:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Name of the Student: %s\n", Rev_stu[i].name);
        printf("Student's Roll Number: %d\n", Rev_stu[i].rollNo);
        printf("Mid Semester marks of the student: %.2f\n", Rev_stu[i].midMarks);
        
    }
}

int main()
{
    int size;

    printf("Enter the number of students: ");
    scanf("%d", &size);

    struct Student* student = (struct Student*)malloc(size * sizeof(struct Student));

    for (int i = 0; i < size; i++)
    {
        printf("\nEnter the %d Student's Name: ", i + 1);
        scanf("%s", student[i].name);

        printf("Enter the Roll Number of %d student: ", i + 1);
        scanf("%d", &student[i].rollNo);

        printf("Enter the Mid Semester marks of %d student: ", i + 1);
        scanf("%f", &student[i].midMarks);
    }

    printf("Reversing the list of students....\n");

    struct Student* rev_student = Rev_student(student, size);
    Disp_StudentL(rev_student, size);

    free(student);
    free(rev_student);
    return 0;
}
