#include <stdio.h>
#include "MyString.h"

#define NULLCHAR 0

int main()
{
	char string1[] = "aaeeaaa\0";
	char string2[] = "aa\0";
	char string3[] = "aaeeaae\0";

	printf("Result is: %d\n", countSubStr((const char *) string1, (const char *) string2, 0));
	printf("Result is: %d\n", countSubStr((const char *) string1, (const char *) string3, 1));

}
/**
 * get the length of a char array given pointer to it's first memory address.
 * iterate over the memory addresses until NULL is found.
 * returns
 */
unsigned short getActualArrayLength(const char *pStr)
{
	unsigned short temp = 0;
	while (*(pStr + temp) != NULL)
	{
		temp++;

		//dont go infi
		if (temp == 1024)
		{
			break;
		}
	}
	return temp;
}
///**
// * given two memory addresses (pointer to source, pointer to dest) and an array length, copy all data from src to dest.
// */
//void populateArray(char *dest, unsigned int length, const char *src)
//{
//	for (int j = 0; j < length; ++j)
//	{
//		*(dest + j) = *(src + j);
//	}
//
//}
/**
 * get two pointers to a String and a Word. find how many occurrances of the word are in the string.
 * 3rd argument "isCyclic" determines whether to wrap back at the end of the string.
 */
unsigned int countSubStr(const char *str1, const char *str2, int isCyclic)
{
	unsigned short counter = 0, strIndex = 0, matchIndex = 0, str1Length = 0, str2Length = 0;

	str1Length = getActualArrayLength(str1);
	str2Length = getActualArrayLength(str2);

//	char actualString1[str1Length];
//	char actualString2[str2Length];

//	populateArray(actualString1, str1Length, str1);
//	populateArray(actualString2, str2Length, str2);

	// end making arrays.

	for (int i = 0; i < str1Length;i++)

	{
		for (int j = 0; j < str2Length;)
		{
			if (*(str1 +i + j) == NULLCHAR && isCyclic)
			{
				i = -j;
				isCyclic = 0;
			}

			if (*(str1 +i + j) == *(str2+j))
			{
				j++;

				if (j == str2Length)
				{
					counter++;
				}

			} else{
				break;
			}



		}


	}
	printf("counter is at: %d\n", counter);


}