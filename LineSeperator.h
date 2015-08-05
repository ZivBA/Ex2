//
// Created by rooty on 8/5/15.
//

#ifndef EX2_LINESEPERATOR_H
#define EX2_LINESEPERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//symbolic constants given exercise description
#define MAX_CHARS_PER_LINE 150
#define VEC_SEP ","

// read mode for file opener
#define READ_MODE "r"

//data structures for this library
/**
 * the Vector struct (+typedef) defines a processing vector. </br>
 * it holds the seperator tag, the dimension of the vector, and a pointer to the data array where
 * the vector coordinates are stored. </br>
 * it is implied, and should be enforced, that sizeof(*dataArray) = sizeof(double)*dim
 */
struct vector
{
    int tag;
    int dim;
    double *dataArray;
};
typedef struct vector Vector;


// methods for this library
/**
 * this method trains the linear seperator with training data. </br>
 * it receives a pointer to the linearSeperator which is the vector being trained, and a const
 * pointer to the data being processed (training data).
 */
void trainLinSep(Vector *linSep, const Vector *trainerVector);

/**
 * this method uses the trained linearSeperator to test a given vector. </br>
 * it gets the two const pointers for the seperator
 * and the tetData vectors.
 */
int testData(Vector *linSep, const Vector *testData);

/**
 * linear seperator "driver". </br>
 * used on a properly formatted input file to initiate the training and testing process.
 *
 */
void processFile(FILE *inputFile);


#endif //EX2_LINESEPERATOR_H
