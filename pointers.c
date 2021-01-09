#include <stdio.h>

int main()
{

  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);

  /*work starts here for activity */
  float d = 12.345;
  float e = 6.78;
  printf("The value of d is %f\n", d);
  printf("The address of d is %p\n", (void*)&d);
  printf("The value of e is %f\n", e);
  printf("The address of e is %p\n", (void*)&e);

  float* ptrtod = &d;
  float* ptrtoe = &e;

  float temp = *ptrtod;
  *ptrtod = e;
  *ptrtoe = temp;

  /*activity didn't ask for this section, but it's to check that the variables were actually swapped*/
  printf("The value of d is %f\n", d);
  printf("The value of e is %f\n", e);

}
