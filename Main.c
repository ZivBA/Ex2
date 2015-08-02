//
// Created by ziv on 8/2/15.
//


#include <stdio.h>
#include "MyString.h"

int main()
{
	char string1[] = "aaeeaaa\0";
	char string2[] = "aa\0";
	char string3[] = "aaeeaae\0";

	printf("Result is: %d\n", countSubStr((const char *) string1, (const char *) string2, 0));
	printf("Result is: %d\n", countSubStr((const char *) string1, (const char *) string3, 1));

}