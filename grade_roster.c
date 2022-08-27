/*
Bishal Giri
This program will make all sorts of changes to a set of 2d arrays
*/

#include <stdio.h>

#define MAX_STUDENTS 10
#define MAX_EXAMS 4

void load_default(int st_no, int exam_no, int scores[][exam_no]);   //1//
void print_table(int st_no, int exam_no, int scores[][exam_no]);    //2//
void print_student(int stID, int st_no, int exam_no, int scores[][exam_no]);    //3//
void print_exam(int exam_ID, int st_no, int exam_no, int scores[][exam_no]);     //4//
void grade_alert_all(int exam_ID, int st_no, int exam_no, int scores[][exam_no]);   //5//
void add_value(int exam_ID, int value, int st_no, int exam_no, int scores[][exam_no]);      //6//
void replace(int st_ID, int exam_ID, int new_grade, int st_no, int exam_no, int scores[][exam_no]);     //7

int main()
{
    int choice=-1, st_ID=1;
    int exam_choice, added_score, replaced_score;
    int num_st=10;
    int num_exams=4;

    int scores[num_st][num_exams];  //scores[10][4] == 10 rows with 4 columns

    printf("This program simulates a grade roster for 10 students with 4 exams.\n");
    do
    {
        printf("\n0-exit\n");
        printf("1-load\n");
        printf("2-print all\n");
        printf("3-print student info (given studentID, prints all exam grades and average exam grade)\n");
        printf("4-print by exam(give Exam ID, prints all grades for this exam)\n");
        printf("5-low grade alert (give exam ID, prints all students who have below 60 in this exam\n");
        printf("6-add value (given exam ID and value to be added, adds that value to that exam for all students)\n");
        printf("7-replace(given exam ID, student ID and new grade, replaces the old grade with the new one)\n");


        printf("\n---Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            break; // exit the switch, wile exit the loop because of condition.
        case 1:
            load_default(num_st, num_exams, scores);
            printf("The data was successfully loaded.\n");
            break;
        case 2:
            print_table(num_st, num_exams, scores);
            break;
        case 3:
            printf("Please enter the student ID (0-%d): ", num_st-1);
            scanf("%d", &st_ID);

            if (st_ID<num_st && st_ID>=0)
            {
                print_student(st_ID, num_st, num_exams, scores);
            }
            else
            {
                printf("Invalid student ID. No action is taken.\n");
            }
            break;
        case 4:
            printf("Please enter the exam ID (1-%d): ", num_exams);
            scanf("%d", &exam_choice);
            if (exam_choice >=1 && exam_choice<=num_exams)
            {
                print_exam(exam_choice, num_st, num_exams, scores);
            }
            else
            {
                printf("Invalid exam ID. No action is taken.\n");
            }
            break;
        case 5:
            printf("Please enter the exam ID (1-4): ");
            scanf("%d", &exam_choice);
            if (exam_choice >=1 && exam_choice<=num_exams)
            {
                grade_alert_all(exam_choice, num_st, num_exams, scores);
            }
            else
            {
                printf("Invalid exam ID. No action is taken.\n");
            }
            break;
        case 6:
            printf("Please enter the exam ID and the value to be added: ");
            scanf("%d%d", &exam_choice, &added_score);

            if (exam_choice<=num_exams && exam_choice>=1)
            {
                add_value(exam_choice, added_score, num_st, num_exams, scores);
            }
            else
            {
                printf("Invalid exam ID. No action is taken.\n");
            }


            break;
        case 7:
            printf("Please enter studentID, examID and new grade (in this order): ");
            scanf("%d%d%d", &st_ID, &exam_choice, &replaced_score);

            if ((exam_choice >=1 && exam_choice<=num_exams)&&(st_ID<=num_st && st_ID>=0))
            {
                replace(st_ID, exam_choice, replaced_score, num_st, num_exams, scores );
            }
            else
            {
                printf("Invalid exam ID. No action is taken.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
        }
    }
    while (choice!=0);
    printf("\nGood bye!\n");
    return 0;
}

//THIS FUNCTION WILL LOAD THE TABLE {1} //It is done//
void load_default(int st_no, int exam_no, int scores[][exam_no])
{
    int hardcoded[MAX_STUDENTS][MAX_EXAMS] =
    {
        {58, 67, 0,	0},
        {72, 67, 56, 65},
        {65, 50, 20, 30},
        {62, 48, 80, 32},
        {35, 0,	0, 0},
        {89, 60, 90, 86},
        {67, 70, 96, 100},
        {100, 90, 66, 100},
        {100, 59, 100, 97},
        {70, 89, 34, 79}
    };
    int st, exam;
    for(st=0; st<st_no; st++)
    {
        for(exam=0; exam<exam_no; exam++)
        {
            scores[st][exam] = hardcoded[st][exam];
        }
    }
}

//THIS FUNCTION WILL PRINT THE TABLE {2} //It is done//
void print_table(int st_no, int exam_no, int scores[][exam_no])
{
    printf("\n---------------------------------------\n");
    printf("|stID | Exam1 | Exam2 | Exam3 | Exam4 |\n");
    printf("---------------------------------------\n");

    for (int i=0; i<st_no; i++)
    {
        printf("|%4d |%6d |%6d |%6d |%6d |\n",i, scores[i][0], scores[i][1],scores[i][2],scores[i][3]);
        printf("---------------------------------------\n");
    }
}

//THIS FUNCTION WILL PRINT THE TABLE {3} //It is done//
void print_student(int stID, int st_no, int exam_no, int scores[][exam_no])
{
    printf("\n---------------------------------------\n");
    printf("|stID | Exam1 | Exam2 | Exam3 | Exam4 |\n");
    printf("---------------------------------------\n");
    printf("|%4d |%6d |%6d |%6d |%6d |\n",stID, scores[stID][0], scores[stID][1],scores[stID][2],scores[stID][3]);
    printf("---------------------------------------\n");
    printf("Average exam score: %.2f\n", (((float)scores[stID][0]+ scores[stID][1]+scores[stID][2]+scores[stID][3])/4));
}

//THIS FUNCTION WILL PRINT THE TABLE {4} //It is done//
void print_exam(int exam_ID, int st_no, int exam_no, int scores[][exam_no])
{
    printf("\nExam %d grades:\n", exam_ID);
    printf("|stID | Exam%d |\n", exam_ID);

    for (int i =0; i<st_no; i++)
    {
        printf("|%4d |%6d |\n", i, scores[i][exam_ID-1]);

    }
}

//THIS FUNCTION WILL PRINT THE TABLE {5} //It is done//
void grade_alert_all(int exam_ID, int st_no, int exam_no, int scores[][exam_no])
{
    printf("\nExam %d ALERT grades lower than 60: \n", exam_ID);
    printf("|stID | Exam%d |\n", exam_ID);

    for (int i=0; i<st_no; i++)
    {
        if (scores[i][exam_ID-1]<60)
        {
            printf("|%4d |%6d |\n", i, scores[i][exam_ID-1]);
        }
    }

}

//THIS FUNCTION WILL PRINT THE TABLE {6} //It is done//
void add_value(int exam_ID, int value, int st_no, int exam_no, int scores[][exam_no])
{
    printf("\nExam%d change all grades by adding %d: \n", exam_ID, value);
    printf("|stID |  old  |  new  |\n");

    for (int i=0; i<st_no; i++)
    {
        printf("|%4d |%6d |%6d |\n", i, scores[i][exam_ID-1], (scores[i][exam_ID-1])+value);
        scores[i][exam_ID-1]+=value;
    }

}

//THIS FUNCTION WILL PRINT THE TABLE {7} //It is done//
void replace(int st_ID, int exam_ID, int new_grade, int st_no, int exam_no, int scores[][exam_no])
{
    scores[st_ID][exam_ID-1] = new_grade;
}
