//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};

void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  Student* st = (Student*)malloc(sizeof(Student));

  st->firstName = (char*)malloc(sizeof(char) * (strlen(fname) + 1));
  strcpy(st->firstName, fname);

  st->lastName = (char*)malloc(sizeof(char) * (strlen(lname) + 1));
  strcpy(st->lastName, lname);

  st->age = age;
  st->id = id;

  students[numStudents] = st;
  numStudents++;
}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
  free(student->firstName);
  free(student->lastName);
  free(student);
}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0
  if (numStudents > 0)
  {
    for(int i = 0; i < numStudents; i++)
    {
      deleteStudent(students[i]);
      students[i] = 0;
     }
  }

  numStudents = 0;
}

void saveStudents(int key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234
  //       james dean 21 2345
  //       katy jones 18 4532
  FILE* fp = fopen(STUFILE, "w");
  if (fp)
  {
    char fullStdStr[512];

    for (int i = 0; i < numStudents; i ++)
    {
      sprintf(fullStdStr, "%s %s %d %ld", students[i]->firstName, students[i]->lastName, students[i]->age, students[i]->id);

      if (key != 0)      
	caesarEncrypt(fullStdStr, key);

      printf("saving: %s\n", fullStdStr);
      fprintf(fp, "%s\n", fullStdStr);
    }

    fclose(fp);
    printf("saved %d students\n", numStudents);
  }
}

void loadStudents(int key)
{
  if (numStudents > 0)
    deleteStudents();

  FILE* fp = fopen(STUFILE, "r");
  if (fp)
  {
    char firstName[100];
    char lastName[100];
    char strAge[16];
    char strId[16];
    int age;
    int id;

    while (1)
    {
      // if using fscanf directly against the line containing "4b" with "%d" for age or id
      // matching it will stop so I need to get the line string first then parse out the
      // number part of "4b" as 4
      char fullStdStr[256];
      if (fscanf(fp, "%s %s %s %s", firstName, lastName, strAge, strId) == 4)
      {
	sprintf(fullStdStr, "%s %s %s %s", firstName, lastName, strAge, strId);

	if (key != 0)
	  caesarDecrypt(fullStdStr, key);

	sscanf(fullStdStr, "%s %s %s %s", firstName, lastName, strAge, strId);

    	for (int i = 0; i < strlen(strAge); i++)
  	{
	  // if it is A-Z or a-z then set it as the string ending char '\0'
	  if ((strAge[i] >= 65 && strAge[i] <= 90) || (strAge[i] >= 97 && strAge[i] <= 122))
 	  {
	    strAge[i] = '\0';
	  }
	  sscanf(strAge, "%d", &age);
	}

	for (int i = 0; i < strlen(strId); i++)
        {
          // if it is A-Z or a-z then set it as the string ending char '\0'
          if ((strId[i] >= 65 && strId[i] <= 90) || (strId[i] >= 97 && strId[i] <= 122))
          {
             strId[i] = '\0';
          }
          sscanf(strId, "%d", &id);
        }

	createStudent(firstName, lastName, age, id);
      }
      else
        break;
    }
    printf("loaded %d students\n", numStudents);
    fclose(fp);
  }
}



void printStudent(Student* student)
{
  if (numStudents > 0)
  {
    printf("  Student: %s %s\n", student->firstName, student->lastName);
    printf("    age: %d\n", student->age);
    printf("    id: %ld\n", student->id); 
  }
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}
