//
// Created by ziv on 8/2/15.
//

#ifndef EX2_LINESEPARATOR_H
#define EX2_LINESEPARATOR_H
#define READ_MODE "r"
#define MAX_DIM 150
#define MAX_DOUBLES 75
#define DIM_SEPERATOR ","
/**
 * Main linear sperator method. pass path to data file as argument.
 */
void linearSeparator(char *pString);

/**
 * struct describing data vector with tag.
 */
typedef struct VectWithTag VectWithTag;
VectWithTag newVector(char *pString);

#endif //EX2_LINESEPARATOR_H
