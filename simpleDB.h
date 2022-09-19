#ifndef SIMPLEDB_H_INCLUDED
#define SIMPLEDB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef unsigned int uint8;

typedef struct courses_id{

    uint8 c1_id;
    uint8 c2_id;
    uint8 c3_id;

}courses_id;

typedef struct courses_grade{

    uint8 c1_grade;
    uint8 c2_grade;
    uint8 c3_grade;

}courses_grade;

typedef struct simpleDB {

    uint8 student_id;
    uint8 student_year;

    courses_id subjects;
    courses_grade grades;

    struct simpleDB *link;

}Node;

extern Node* start;


bool SDB_AddEntry  (uint8 id,uint8 year,courses_id *subject,courses_grade *grade);

bool InsertAtEnd (uint8 id,uint8 year,courses_id *subject,courses_grade *grade); /*additional function*/

void CreateList (void); /*additional function*/



void   DisplayList (void); /*additional function*/

void SDB_DeleteEntry (uint8 id );

bool SDB_ReadEntry (uint8 id);

bool SDB_IsIdExist (uint8 id);

uint8 SDB_GetUsedSize(void);

bool SDB_IsFull(void);

void SDB_GetIdList (uint8 *Count ,uint8 *List );







#endif // SIMPLEDB_H_INCLUDED


