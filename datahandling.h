#ifndef DATAHANDLING_H
#define DATAHANDLING_H

typedef struct
{
    double time;
    double signal;
    double noise;
} datarow;

datarow *readData(const char* filename, size_t* size);
void writeArraysToCSV(const char *filename, double **arrays, size_t numArrays, size_t numRows);
void writeSingleArrayToCSV(const char *filename, double *array, size_t size);

#endif