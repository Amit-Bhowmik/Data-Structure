#include <stdio.h>

typedef struct Student
{
    int id;
    int age;
    int batch;
    char name[20];
    char dept[20];
} st;

int main()
{
    int t;
    printf("Enter the number of students: ");
    scanf("%d", &t);

    st student[t];

    for (int i = 0; i < t; i++)
    {
        printf("\nEnter the information of student %d\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", &student[i].name);

        printf("ID: ");
        scanf("%d", &student[i].id);

        printf("AGE: ");
        scanf("%d", &student[i].age);

        printf("Batch: ");
        scanf("%d", &student[i].batch);

        printf("Department: ");
        scanf(" %[^\n]", &student[i].dept);
    }

    int serial;
    while (1)
    {
        printf("\nEnter the serial number of the student whose information you want to view (0 to exit): ");
        scanf("%d", &serial);

        if (serial == 0)
        {
            break;
        }
        else if (serial > 0 && serial <= t)
        {
            serial--;
            printf("\nInformation of student %d\n", serial + 1);
            printf("Name: %s\n", student[serial].name);
            printf("ID: %d\n", student[serial].id);
            printf("AGE: %d\n", student[serial].age);
            printf("Batch: %d\n", student[serial].batch);
            printf("Department: %s\n", student[serial].dept);
        }
        else
        {
            printf("Invalid student number...\n");
        }
    }

    return 0;
}
