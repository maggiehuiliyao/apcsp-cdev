#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{

  int arg1;
  int arg2;
  char input[256];
  int found;

  if (argc == 1)
  {
    printf("please input lower: ");
    fgets(input, 256, stdin);
    found = sscanf(input, "%d", &arg1);
    while (found !=1)
    {
      printf("lower is not an integer, input lower: \n");
      fgets(input, 256, stdin);
      found = sscanf(input, "%d", &arg1);
    }

    printf("please input upper: ");
    fgets(input, 256, stdin);
    found = sscanf(input, "%d", &arg2);
    while (found !=1)
    {
      printf("upper is not an integer, input upper: \n");
      fgets(input, 256, stdin);
      found = sscanf(input, "%d", &arg2);
    }
  }

  else if (argc == 2)
  {
    found = sscanf(argv[1], "%d", &arg1);
    while (found != 1)
    {
      printf("lower is not an integer, enter lower\n");
      fgets(input, 256, stdin);
      found = sscanf(input, "%d", &arg1);
    }

    printf("please input upper: ");
    fgets(input, 256, stdin);
    found = sscanf(input, "%d", &arg2);
    while (found != 1)
    {
      printf("upper is not an integer, input upper: \n");
      fgets(input, 256, stdin);
      found = sscanf(input, "%d", &arg2);
    }
  }

  else if (argc == 3)
  {
    found = sscanf(argv[1], "%d", &arg1);
    if (found != 1)
    {
      printf("first arg is not an integer, enter two ints\n");
      return 1;
    }

    found = sscanf(argv[2], "%d", &arg2);
    if (found != 1)
    {
      printf("second arg is not an integer, enter two ints\n");
      return 1;
    }
  }

  else
  {
    printf("%s : expected 2 args, please enter two integers\n", argv[0]);
    return 1;
  }

  if (arg1 >= arg2)
  {
    printf("the second number should be greater than the first number\n");
    return 1;
  }

  if (arg1 <=0 || arg2 <=0)
  {
    printf("the two numbers should both be positive\n");
    return 1;
  }

  // OK - at this stage the user input is validated and we can proceed...

  float areaOfCircle(int a) {
    float area = M_PI*a*a;
    return area;
  }

  printf("calculating area of circle starting at %d and ending at %d\n", arg1, arg2);

  int currentRadius = arg1;

  for (int i = 0; i <= arg2 - arg1; i ++)
  {
    printf("the area of a circle with radius %d is %f\n", currentRadius, areaOfCircle(currentRadius));
    currentRadius++;
  }
}
