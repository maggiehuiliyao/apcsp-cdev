#include <stdio.h>
#include <string.h>

// student structure
//struct Student...
struct Student {
  char firstName[100];
  char lastName[100];
  int age;
  int id;
};



void printStudent(struct Student* student)
{
  printf("Name: %s %s \n", student->firstName, student->lastName);
  printf("Age: %d\n", student->age);
  printf("ID: %d\n\n",student->id );
}



void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
  for(int i = 0; i <num; i ++)
  {
    printf("----- Student -----\n");
    printStudent(&students[i]);
  }
}



int main()
{

  // an array of students
  //xxx students;

  struct Student arr_students[256];

  int numStudents = 0;
  while (1)
  {
    char c;
    char input[256];

    char firstName[100];
    char lastName[100];
    int age;
    int id;

    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q')
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(arr_students, numStudents);
      continue;
    }
    else if (c == 'a')
    {

     struct Student newStudent;

      // enter a new student
      char input[256];
      printf("First Name: ");
      fgets(input, 256, stdin);
      sscanf(input, "%s", &firstName);
      strcpy(newStudent.firstName, firstName);


      printf("\nLast Name: ");
      fgets(input, 256, stdin);
      sscanf(input, "%s", &lastName);
      strcpy(newStudent.lastName, lastName);

      printf("\nAge: ");
      fgets(input, 256, stdin);
      sscanf(input, "%d", &age);
      newStudent.age = age;

      printf("\nID: ");
      fgets(input, 256, stdin);
      sscanf(input, "%d", &id);
      newStudent.id = id;

      arr_students[numStudents] = newStudent;

      numStudents++;
    }
  }

  printf("\nGoodbye!\n");
}
