#include <stdio.h>
#include <stdlib.h>

#include "simpleDB.h"

Node* start = NULL;


int main()
{
    CreateList();
    printf("\n");
    uint8 choice,num,size,ID,counter;
    bool checkerr;


    while (1){


    printf ("\nplease select a choice of the following :\n\n");

    printf ("1)  is the database full?\n");
    printf ("2)  show the number of students in the database\n");
    printf ("3)  add a student to the database \n");
    printf ("4)  delete a student from the database\n");
    printf ("5)  show the info of a student\n");
    printf ("6)  check if a specific student exist in the database or not\n");
    printf ("7)  display all the info of the students in the database\n");
    printf ("8)  show the number of the students and their ids in the database\n");
    printf ("9)  exit the program\n\n");

    printf ("your choice is :");
    scanf("%d",&choice);
    printf ("\n");


    if (choice == 1){

        num = SDB_IsFull();

        if (num == true) {
            printf("it is full\n");
        }
        else {
            printf("it is not full\n");
        }


    }
    else if (choice == 2){


       size = SDB_GetUsedSize();
       printf ("the number of students is %d\n",size);

    }
    else if (choice == 3){

        num = SDB_IsFull();

        if (num == true) {
            printf("sorry the database is full\n");
        }
        else {

                uint8 student__id;
                uint8 student__year;

                courses_id thecourses;
                courses_grade thegrades;




            printf ("enter the id of the student\n");
            scanf ("%d",&student__id);
            printf ("enter the student year\n");
            scanf ("%d",&student__year);

            printf ("enter the id of the first course \n");
            scanf ("%d",&thecourses.c1_id);
            printf ("enter the grade of the first course \n");
            scanf ("%d",&thegrades.c1_grade);

            printf ("enter the id of the second course \n");
            scanf ("%d",&thecourses.c2_id);
            printf ("enter the grade of the second course \n");
            scanf ("%d",&thegrades.c2_grade);

            printf ("enter the id of the third course \n");
            scanf ("%d",&thecourses.c3_id);
            printf ("enter the grade of the third course \n");
            scanf ("%d",&thegrades.c3_grade);

            checkerr = InsertAtEnd(student__id,student__year,&thecourses,&thegrades);

            if (checkerr == true){
                printf("student added successfully\n");
            }
            else{
                printf("student not added\n");
            }


        }


    }
    else if (choice == 4){

        printf ("enter the id of the student you wanna remove from the database\n");
        scanf ("%d",&ID);
        SDB_DeleteEntry(ID);
    }
    else if (choice == 5){

        printf ("enter the id of the student you wanna know his info\n");
        scanf ("%d",&ID);
        checkerr = SDB_ReadEntry (ID);

    }
    else if (choice == 6){

        printf ("enter the id of the student you wanna know if he/she exists in the database or not \n");
        scanf ("%d",&ID);
        checkerr = SDB_IsIdExist (ID);

    }
    else if (choice == 7){
        DisplayList ();
    }
    else if (choice == 8){

        uint8 listt[10];

        SDB_GetIdList (&counter,listt);

        printf ("number of ids :%d\n",counter);
        printf ("list of ids :\n");
        for (int i=0;i<counter;i++){
            printf("%d ",listt[i]);

            }

    }
    else if (choice > 9 || choice < 1){
            printf ("you your choice is out of range \n\n");

    }
    else {
        break;
    }


    }



    return 0;
}
