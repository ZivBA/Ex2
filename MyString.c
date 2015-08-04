#include <stdio.h>
#include "MyString.h"

/**
 * get the length of a char array given pointer to it's first memory address.
 * iterate over the memory addresses until NULL is found, or 1024 chars are reached. cuz that's just too many anyways.
 * returns the number of chars counted.
 */
unsigned short getActualArrayLength(const char *pStr)
{
	unsigned short temp = 0;
	while (*(pStr + temp) != '\0')
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
/**
 * get two pointers to a String and a Word. find how many occurrances of the word are in the string.
 * 3rd argument "isCyclic" determines whether to wrap back at the end of the string.
 */
unsigned int countSubStr(const char *str1, const char *str2, int isCyclic)
{
	unsigned short counter = 0, strIndex = 0, matchIndex = 0, str1Length = 0, str2Length = 0;

	str1Length = getActualArrayLength(str1);
	str2Length = getActualArrayLength(str2);

	for (int i = 0; i < str1Length;i++)

	{
		for (int j = 0; j < str2Length;)
		{
			if (*(str1 +i + j) == '\0' && isCyclic)
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
	return counter;

}