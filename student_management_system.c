#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stu
{
    int roll;
    char name[50];
    int age;
    float marks;
};

void addStu();
void showStu();
void searchStu();
void updateStu();
void deleteStu();
void totalStu();
void topper();
void clearData();

int main()
{
    int ch;

    while (1)
    {
        printf("\n====================================\n");
        printf("   STUDENT MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Total Students\n");
        printf("7. Show Topper\n");
        printf("8. Clear All Records\n");
        printf("9. Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addStu();
            break;

        case 2:
            showStu();
            break;

        case 3:
            searchStu();
            break;

        case 4:
            updateStu();
            break;

        case 5:
            deleteStu();
            break;

        case 6:
            totalStu();
            break;

        case 7:
            topper();
            break;

        case 8:
            clearData();
            break;

        case 9:
            printf("\nThank You!\n");
            exit(0);

        default:
            printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}

void addStu()
{
    FILE *fp;

    struct Stu s, t;

    int f = 0;

    fp = fopen("student.txt", "ab+");

    printf("\nRoll : ");
    scanf("%d", &s.roll);

    rewind(fp);

    while (fread(&t, sizeof(t), 1, fp))
    {
        if (t.roll == s.roll)
        {
            f = 1;
            break;
        }
    }

    if (f)
    {
        printf("\nRoll Number Already Exists!\n");
        fclose(fp);
        return;
    }

    printf("Name : ");
    scanf(" %[^\n]", s.name);

    printf("Age : ");
    scanf("%d", &s.age);

    printf("Marks : ");
    scanf("%f", &s.marks);

    fseek(fp, 0, SEEK_END);

    fwrite(&s, sizeof(s), 1, fp);

    fclose(fp);

    printf("\nStudent Added Successfully!\n");
}

void showStu()
{
    FILE *fp;

    struct Stu s;

    fp = fopen("student.txt", "rb");

    if (fp == NULL)
    {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\n----------------------------------------\n");

    while (fread(&s, sizeof(s), 1, fp))
    {
        printf("\nRoll  : %d\n", s.roll);
        printf("Name  : %s\n", s.name);
        printf("Age   : %d\n", s.age);
        printf("Marks : %.2f\n", s.marks);
    }

    fclose(fp);
}

void searchStu()
{
    FILE *fp;

    struct Stu s;

    int roll, f = 0;

    fp = fopen("student.txt", "rb");

    printf("\nEnter Roll : ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.roll == roll)
        {
            printf("\nStudent Found\n");

            printf("Name : %s\n", s.name);
            printf("Age : %d\n", s.age);
            printf("Marks : %.2f\n", s.marks);

            f = 1;
        }
    }

    if (f == 0)
    {
        printf("\nRecord Not Found!\n");
    }

    fclose(fp);
}

void updateStu()
{
    FILE *fp, *tp;

    struct Stu s;

    int roll, f = 0;

    fp = fopen("student.txt", "rb");
    tp = fopen("temp.txt", "wb");

    printf("\nEnter Roll : ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.roll == roll)
        {
            printf("\nEnter New Name : ");
            scanf(" %[^\n]", s.name);

            printf("Enter New Age : ");
            scanf("%d", &s.age);

            printf("Enter New Marks : ");
            scanf("%f", &s.marks);

            f = 1;
        }

        fwrite(&s, sizeof(s), 1, tp);
    }

    fclose(fp);
    fclose(tp);

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (f)
        printf("\nRecord Updated Successfully!\n");
    else
        printf("\nRecord Not Found!\n");
}

void deleteStu()
{
    FILE *fp, *tp;

    struct Stu s;

    int roll, f = 0;

    fp = fopen("student.txt", "rb");
    tp = fopen("temp.txt", "wb");

    printf("\nEnter Roll : ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.roll != roll)
        {
            fwrite(&s, sizeof(s), 1, tp);
        }
        else
        {
            f = 1;
        }
    }

    fclose(fp);
    fclose(tp);

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (f)
        printf("\nRecord Deleted Successfully!\n");
    else
        printf("\nRecord Not Found!\n");
}

void totalStu()
{
    FILE *fp;

    struct Stu s;

    int c = 0;

    fp = fopen("student.txt", "rb");

    while (fread(&s, sizeof(s), 1, fp))
    {
        c++;
    }

    fclose(fp);

    printf("\nTotal Students : %d\n", c);
}

void topper()
{
    FILE *fp;

    struct Stu s, top;

    int f = 0;

    fp = fopen("student.txt", "rb");

    while (fread(&s, sizeof(s), 1, fp))
    {
        if (f == 0 || s.marks > top.marks)
        {
            top = s;
            f = 1;
        }
    }

    fclose(fp);

    if (f)
    {
        printf("\nTopper Details\n");

        printf("Roll : %d\n", top.roll);
        printf("Name : %s\n", top.name);
        printf("Marks : %.2f\n", top.marks);
    }
    else
    {
        printf("\nNo Records Found!\n");
    }
}

void clearData()
{
    FILE *fp;

    fp = fopen("student.txt", "wb");

    if (fp == NULL)
    {
        printf("\nUnable to Clear Records!\n");
        return;
    }

    fclose(fp);

    printf("\nAll Records Cleared Successfully!\n");
}