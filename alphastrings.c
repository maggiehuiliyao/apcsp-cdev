#include <stdio.h>
#include <string.h>

int main()
{
	char firstString[27];

	for (int i=97; i<=122; i++)
	{
		firstString[i-97] = i;
	}
	firstString[26] = '\0';
	char secondString[27] = "abcdefghijklmnopqrstuvwxyz";

	if (strcmp(firstString, secondString) == 0)
		printf("the strings are identical\n");
	else
		printf("the strings are different\n");

	for (int j = 0; j < 26; j ++)
	{
		firstString[j] -= 32;
	}

	if (strcmp(firstString, secondString) == 0)
		printf("the strings are identical\n");
	else
		printf("the strings are different\n");

	char thirdString[54];

	strcpy(thirdString, firstString);
	strcat(thirdString, secondString);

	printf("the first string is %s, the second string is %s, and the third string is %s\n", firstString, secondString, thirdString);
}
