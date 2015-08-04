//
// Created by ziv on 8/2/15.
//

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "LineSeparator.h"




double innerProd(double pDouble[], char *string)
{
    string = strtok(string,DIM_SEPERATOR);
    int i =0;
    double sum =0;
    while (string != NULL)
    {
        string = strtok (NULL, DIM_SEPERATOR);
        sum = pDouble[i] * strtod(string,NULL);
    }
    return sum;

}

void actualMainToKeppMainShort(char *pString[])
{

    FILE *dataSet = fopen(pString[0],READ_MODE);

    //ensure valid file.
    assert (dataSet!=NULL);

    unsigned int m; // number of training vectors.
    unsigned int n; // dimension

    fscanf(dataSet,"%d",m);
    fscanf(dataSet,"%d",n);

    //create zeroed vector of size n, initialize with zeros.
    double linSepVect[n];
    memset(linSepVect, 0, n);
    char* templine = (char *) malloc(MAX_DIM*sizeof(char));
    //train segment
    for (int i = 0; i < m; ++i)
    {
        templine = fgets(templine,MAX_DIM,dataSet);
        assert(templine!= NULL);

        if (innerProd(linSepVect, templine) > 0{

        }
    };
    /**
     * do data processing.
     */
    while (fscanf(dataSet,) != EOF) {

    }



}

static int main(int argc, char *argv[])
{

    /**
     * check if number of args is valid.
     *//*
    assert(argc == 1);
    */

    if (argc != 1)
    {
        printf("Number of arguments must be 1");
        exit(1);
    }

   actualMainToKeppMainShort(argv);


}