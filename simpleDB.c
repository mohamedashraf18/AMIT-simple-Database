#include "simpleDB.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



bool SDB_AddEntry  (uint8 id,uint8 year,courses_id *subject,courses_grade *grade ){ /* working */

    Node* temp =(Node*) malloc(sizeof(Node));

	if(temp != NULL)
	{
		temp ->student_id  = id ;
		temp ->student_year  = year ;

		temp ->subjects.c1_id  = subject->c1_id ;
		temp ->subjects.c2_id  = subject->c2_id ;
		temp ->subjects.c3_id  = subject->c3_id ;

		temp->grades.c1_grade  = grade->c1_grade;
        temp->grades.c2_grade  = grade->c2_grade;
        temp->grades.c3_grade  = grade->c3_grade;


		temp -> link = start;
		start = temp;
		return true;
	}

    return false;

}
/*---------------------------------------------------------------------------------------------------------------------------------------------------*/
void SDB_DeleteEntry  (uint8 id){ /*working*/


    Node * p = start;


	if(start == NULL)
	{
		printf("List is empty \n");
		return ;
	}


	if(start->student_id == id)
	{

		start = start->link;
		free(p);
		printf("student is removed successfully\n");
		return ;
	}


	Node * ptr = start;
	while(ptr->link != NULL)
	{
		if(ptr->link->student_id == id)
		{
			p = ptr->link;
			break;
		}
		ptr = ptr->link;
	}

	if(ptr->link == NULL)
	{
		printf("Element of the value %d is not in the List\n",id);
	}
	else
	{
		ptr->link = p -> link;
		free(p);
		printf("student is removed successfully\n");
	}

}
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
bool SDB_ReadEntry (uint8 id){ /* working */

    if(start == NULL)
	{
		printf("List is empty\n");
		return false;
	}
	Node* ptr = start;
	while(ptr!=NULL)
	{
		if (ptr->student_id==id ){
                printf ("the student year is : %d\n",ptr->student_year);

                printf ("the first course id is : %d\n",ptr->subjects.c1_id);
                printf ("the first course grade is : %d\n",ptr->grades.c1_grade);

                printf ("the second course id is : %d\n",ptr->subjects.c2_id);
                printf ("the second course grade is : %d\n",ptr->grades.c2_grade);

                printf ("the third course id is : %d\n",ptr->subjects.c3_id);
                printf ("the third course grade is : %d\n",ptr->grades.c3_grade);

                return true;
		}
		ptr = ptr->link;
	}
	printf ("the student id can't found in the database\n");
	return false;

}
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
bool SDB_IsIdExist (uint8 id){ /* working */

    if(start == NULL)
	{
		printf("List is empty\n");
		return false;
	}

	Node* ptr = start;

	while(ptr!=NULL)
	{
		if (ptr->student_id==id){
                printf ("the id exists\n");
                return true;

		}
		ptr = ptr->link;
	}
	printf("the id doesn't exist\n");
	return false;


}
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
uint8 SDB_GetUsedSize(void){ /* working */

    uint8 num_of_entries=0;

    if(start == NULL)
	{
		printf("List is empty\n");
		return num_of_entries;
	}

	Node* ptr = start;


	while(ptr!=NULL)
	{
		num_of_entries++;
		ptr = ptr->link;
	}
	return num_of_entries;

}
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
bool SDB_IsFull(void){ /* working */

    uint8 num_of_entries=0;

    if(start == NULL)
	{
		printf("List is empty\n");
		return false;
	}

	Node* ptr = start;


	while(ptr!=NULL)
	{
		num_of_entries++;
		ptr = ptr->link;
	}
	if (num_of_entries==10){

        return true;
	}
	else{
        return false;
	}

}
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
void SDB_GetIdList (uint8 *Count ,uint8 *List ){  /*working*/

        *Count = SDB_GetUsedSize();
        uint8 i=0;

        if(start == NULL)
	{
		return;
	}

	Node* ptr = start;

	while(ptr!=NULL)
	{
		List[i]=ptr->student_id;
		ptr = ptr->link;
		i++;
	}

}
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
bool InsertAtEnd (uint8 id,uint8 year,courses_id *subject,courses_grade *grade){ /* working */

        Node* temp =(Node*) malloc(sizeof(Node));
        if(temp != NULL)
        {
            Node* ptr = start;

            while(ptr->link != NULL)
            {
                ptr = ptr->link;
            }

            temp ->student_id  = id ;
            temp ->student_year  = year ;

            temp ->subjects.c1_id  = subject->c1_id ;
            temp ->subjects.c2_id  = subject->c2_id ;
            temp ->subjects.c3_id  = subject->c3_id ;

            temp->grades.c1_grade  = grade->c1_grade;
            temp->grades.c2_grade  = grade->c2_grade;
            temp->grades.c3_grade  = grade->c3_grade;

            temp->link  = NULL;

            ptr->link   = temp;

            return true;
        }
        return false;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------*/

void CreateList (void){ /*working*/

    uint8 numberOfstudents;

    uint8 student_id;
    uint8 student_year;

    courses_id courses;
    courses_grade grades;

	uint8 counter;
	bool checker;

	printf("Enter the number of students :\n");
	scanf("%d",&numberOfstudents);



        if ( 0 == numberOfstudents || numberOfstudents>10 )
        {
            return ;
        }



    printf ("enter the id of the student\n");
    scanf ("%d",&student_id);
    printf ("enter the student year\n");
    scanf ("%d",&student_year);

	printf ("enter the id of the first course \n");
    scanf ("%d",&courses.c1_id);
    printf ("enter the grade of the first course \n");
    scanf ("%d",&grades.c1_grade);

    printf ("enter the id of the second course \n");
    scanf ("%d",&courses.c2_id);
    printf ("enter the grade of the second course \n");
    scanf ("%d",&grades.c2_grade);

    printf ("enter the id of the third course \n");
    scanf ("%d",&courses.c3_id);
    printf ("enter the grade of the third course \n");
    scanf ("%d",&grades.c3_grade);


	checker = SDB_AddEntry(student_id,student_year,&courses,&grades);
	if (checker == true){
        printf("student added successfully\n");
    }
    else{
        printf("student not added\n");
    }


	for(counter = 1; counter <numberOfstudents ; counter++)
	{
		printf ("enter the id of the next student\n");
        scanf ("%d",&student_id);
        printf ("enter his/her student year\n");
        scanf ("%d",&student_year);

        printf ("enter the id of the first course \n");
        scanf ("%d",&courses.c1_id);
        printf ("enter the grade of the first course \n");
        scanf ("%d",&grades.c1_grade);

        printf ("enter the id of the second course \n");
        scanf ("%d",&courses.c2_id);
        printf ("enter the grade of the second course \n");
        scanf ("%d",&grades.c2_grade);

        printf ("enter the id of the third course \n");
        scanf ("%d",&courses.c3_id);
        printf ("enter the grade of the third course \n");
        scanf ("%d",&grades.c3_grade);

		checker = InsertAtEnd(student_id,student_year,&courses,&grades);
		if (checker == true){
            printf("student added successfully\n");
            }
        else{
                printf("student not added\n");
            }

	}

}
/*---------------------------------------------------------------------------------------------------------------------------------------------*/

void   DisplayList (void){  /* working */

    if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}

	Node* ptr = start;

	printf("\n List is : \n\n");

	for (int i=1 ; ptr!=NULL ; i++)
	{
		printf ("the id of the student number %d is %d\n",i,ptr->student_id);
        printf ("the student year is %d\n",ptr->student_year);

        printf ("the id of the first course is %d \n",ptr->subjects.c1_id);
        printf ("the grade of the first course is %d \n",ptr->grades.c1_grade);

        printf ("the id of the second course is %d\n",ptr->subjects.c2_id);
        printf ("the grade of the second course is %d \n",ptr->grades.c2_grade);


        printf ("the id of the third course is %d \n",ptr->subjects.c3_id);
        printf ("the grade of the third course is %d \n\n",ptr->grades.c3_grade);


		ptr = ptr->link;

	}


}
/*----------------------------------------------------------------------------------------------------------------*/









