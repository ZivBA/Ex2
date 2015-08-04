//
// Created by ziv on 8/2/15.
//

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "LineSeparator.h"


struct VectWithTag {
    double * vector[];
    int * tag;
} VectWithTag;

VectWithTag newVector(char *pString){
    VectWithTag returnVector;
    pString = strtok(pString,DIM_SEPERATOR);
    returnVector.tag = atoi(pString);
    double *tempArr = malloc(MAX_DOUBLES*sizeof(double));

    int counter = 0;
    while (pString != NULL)
    {
        pString = strtok (NULL, DIM_SEPERATOR);
        *(tempArr+(counter*sizeof(double)))= strtod(pString,DIM_SEPERATOR);
        counter++;
    }
    tempArr = (double[]) realloc(tempArr, (size_t) counter-1);
    returnVector.vector = tempArr;

    return returnVector;

}


double innerProd(double pDouble[], VectWithTag vector)
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

void linearSeparator(char *pString)
{

    FILE *dataSet = fopen(pString[0],READ_MODE);

    //ensure valid file.
    assert (dataSet!=NULL);

    unsigned int m; // number of training vectors.
    unsigned int n; // dimension

    fscanf(dataSet,"%d",m);
    fscanf(dataSet,"%d",n);

    //create zeroed vector of size n, initialize with zeros.
    double linSepVect[n]; // the actual linear seperator vector
    memset(linSepVect, 0, n);
    char* templine = (char *) malloc(MAX_DIM*sizeof(char));

    //train segment
    for (int i = 0; i < m; ++i)
    {
        templine = fgets(templine,MAX_DIM,dataSet);
        VectWithTag * currentTrainVector = newVector(templine);

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

    linearSeparator(argv[0]);


}