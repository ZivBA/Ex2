//
// Created by rooty on 8/5/15.
//

#include "LineSeperator.h"


// pseudo sign checker - if smaller than precision limit, for tagging puposes its neg.
#define PRECISE_ZERO(num) (num < 0.00001 ? -1 : 1)

/**
 * initialize a Vector object with a certain dimension. zero it's tag and array values.
 */
void initVector(int dim, Vector *pVector)
{
    pVector->dataArray = (double*) malloc(sizeof(double) * dim);
    pVector->dim = dim;
    pVector->tag = 0;
    for (int i = 0; i < dim; ++i)
    {
        pVector->dataArray[i] = 0;
    }
}

void parseLineToVect(Vector *pVector, char *curLine)
{
    int pos = 0; // current position while iterating over the entry tokens

    for (curLine = strtok(curLine, VEC_SEP); curLine != NULL; curLine = strtok(NULL, VEC_SEP))
    {
        if (pos < pVector->dim)
        {
            pVector->dataArray[pos] = atof(curLine);
        } else
        {
            pVector->tag = atoi(curLine);
        }
        pos++;
        assert(pos <= pVector->dim+1); // check that the dataset is the expected size

    }

}

double innerProd(Vector *vec1, const Vector *vec2)
{
    double sum = 0;
    for (int i = 0; i < vec1->dim; ++i)
    {
        sum += (vec1->dataArray[i] * vec2->dataArray[i]);
    }
    return sum;
}


int testData(Vector *linSep, const Vector *testData)
{
    return (PRECISE_ZERO(innerProd(linSep, testData)));
}

void trainLinSep(Vector *linSep, const Vector *trainerVector)
{

    innerProd(linSep, trainerVector);
    if (PRECISE_ZERO(innerProd(linSep, trainerVector)) != trainerVector->tag)
    {
        for (int i = 0; i < linSep->dim; ++i)
        {
            linSep->dataArray[i] += (trainerVector->tag * trainerVector->dataArray[i]);
        }
    }

}

void processFile(FILE *inputFile)
{
    Vector linSep, trainAndTest;
    int n, m, counter = 0;


    if (inputFile == NULL)
    {
        printf("Error opening input file");
        exit(0);
    }
    //declare currentline here, as it's a temp var and is useless if file is null.
    char currentLine[MAX_CHARS_PER_LINE];
    assert(currentLine); // check that the line was read OK from file
    n = atoi(fgets(currentLine, MAX_CHARS_PER_LINE, inputFile)); // read dim (First line)
    m = atoi(fgets(currentLine, MAX_CHARS_PER_LINE, inputFile)); // read train set size (Sec line)
    initVector(n, &linSep);
    initVector(n, &trainAndTest);

    //train the seperator ove 'm' entries
    while (counter < m)
    {       // update Train vector
        parseLineToVect(&trainAndTest, fgets(currentLine, MAX_CHARS_PER_LINE, inputFile));
        trainLinSep(&linSep, &trainAndTest); // update linSep according to trainAndTest vector
        counter++;
    }


    //check rest of entries against seperator
    while (fgets(currentLine, MAX_CHARS_PER_LINE, inputFile))
    {       // update Test vector
        parseLineToVect(&trainAndTest, currentLine);
        int currentResult = testData(&linSep, &trainAndTest);
        printf("%d\n",currentResult);

    }


}

int main(int argc, char *argv[])
{

    FILE *inputFile = fopen(argv[1], READ_MODE);
    assert(inputFile != NULL);
    processFile(inputFile);

    return 0;
}