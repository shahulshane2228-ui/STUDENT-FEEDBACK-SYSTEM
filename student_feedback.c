#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAX_FEEDBACK 100

struct Feedback
{
    char name[50];
    char course[50];
    char comments[200];
    int rating;
};

struct Feedback feedback[MAX_FEEDBACK];
int count = 0;

void clear_input()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void submit_feedback()
{
    if (count >= MAX_FEEDBACK)
    {
        printf("\nFeedback storage is full!\n");
        return;
    }

    printf("\nEnter Student Name: ");
    if (fgets(feedback[count].name, 50, stdin) == NULL)
        return;
    feedback[count].name[strcspn(feedback[count].name, "\n")] = '\0';

    printf("Enter Course Name: ");
    if (fgets(feedback[count].course, 50, stdin) == NULL)
        return;
    feedback[count].course[strcspn(feedback[count].course, "\n")] = '\0';

    if (strlen(feedback[count].name) == 0 ||
        strlen(feedback[count].course) == 0)
    {
        printf("\nName and course cannot be empty!\n");
        return;
    }

    printf("Enter Rating (1-5): ");

    char input[50];
    if (fgets(input, sizeof(input), stdin) == NULL)
        return;

    char *end;
    errno = 0;
    long rating = strtol(input, &end, 10);

    while (isspace((unsigned char)*end))
        end++;

    if (errno != 0 || end == input || *end != '\0' ||
        rating < 1 || rating > 5)
    {
        printf("\nInvalid rating! Enter a number from 1 to 5.\n");
        return;
    }

    feedback[count].rating = (int)rating;

    printf("Enter Your Comments: ");
    if (fgets(feedback[count].comments, 200, stdin) == NULL)
        return;
    feedback[count].comments[
        strcspn(feedback[count].comments, "\n")] = '\0';

    count++;

    printf("\nFeedback submitted successfully!\n");
}

void view_feedback()
{
    if (count == 0)
    {
        printf("\nNo feedback available!\n");
        return;
    }

    printf("\n========== STUDENT FEEDBACK ==========\n");

    for (int i = 0; i < count; i++)
    {
        printf("\nFeedback %d\n", i + 1);
        printf("Student Name : %s\n", feedback[i].name);
        printf("Course Name  : %s\n", feedback[i].course);
        printf("Rating       : %d/5\n", feedback[i].rating);
        printf("Comments     : %s\n", feedback[i].comments);
    }
}

void calculate_average()
{
    if (count == 0)
    {
        printf("\nNo feedback available to calculate average!\n");
        return;
    }

    int total = 0;

    for (int i = 0; i < count; i++)
    {
        total += feedback[i].rating;
    }

    printf("\nTotal Feedback : %d\n", count);
    printf("Average Rating: %.2f/5\n",
           (float)total / count);
}

int main()
{
    int choice;
    char input[50];

    do
    {
        printf("\n======= STUDENT FEEDBACK SYSTEM =======\n");
        printf("1. Submit Feedback\n");
        printf("2. View All Feedback\n");
        printf("3. Calculate Average Rating\n");
        printf("4. Exit\n");

        printf("\nEnter Your Choice: ");

        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        char *end;
        errno = 0;
        long value = strtol(input, &end, 10);

        while (isspace((unsigned char)*end))
            end++;

        if (errno != 0 || end == input || *end != '\0' ||
            value < 1 || value > 4)
        {
            printf("\nInvalid choice! Please select 1-4.\n");
            continue;
        }

        choice = (int)value;

        switch (choice)
        {
            case 1:
                submit_feedback();
                break;

            case 2:
                view_feedback();
                break;

            case 3:
                calculate_average();
                break;

            case 4:
                printf("\nThank you for using Student Feedback System!\n");
                break;
        }

    } while (choice != 4);

    return 0;
}