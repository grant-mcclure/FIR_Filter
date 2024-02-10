#ifndef FILTERING_H
#define FILTERING_H

double* moving_avg3pt(double *array1, int arraySize);
double *moving_avg5pt(double *array1, int arraySize);
double *moving_avg7pt(double *array1, int arraySize);
double *binomial_filter3pt(double *array1, int arraySize);
double *binomial_filter5pt(double *array1, int arraySize);
double *binomial_filter7pt(double *array1, int arraySize);

#endif