#include <stdio.h>
#include <stdlib.h>
#include "filtering.h"

double *moving_avg3pt(double *array1, int arraySize)
{

    float quotient = 1.0 / 3.0;
    double *moving_avg = malloc(sizeof(double) * (arraySize - 2));

    if (moving_avg == NULL)
    {
        perror("memory not allocated");
        return NULL;
    }

    for (int i = 1; i < arraySize - 1; i++)
    {

        moving_avg[i - 1] = quotient * (array1[i - 1] + array1[i] + array1[i + 1]);
    }

    return moving_avg;
}

double *moving_avg5pt(double *array1, int arraySize)
{
    float quotient = 1.0 / 5.0;
    double *moving_avg = malloc(sizeof(double) * (arraySize - 4));

    if (moving_avg == NULL)
    {
        perror("memory not allocated properly");
        return NULL;
    }

    for (int i = 2; i < arraySize - 2; i++)
    {
        moving_avg[i - 2] = quotient * (array1[i - 2] + array1[i - 1] + array1[i] + array1[i + 1] + array1[i + 2]);
    }

    return moving_avg;
}

double *moving_avg7pt(double *array1, int arraySize)
{
    float quotient = 1.0 / 7.0;

    double *moving_avg = malloc(sizeof(double) * (arraySize - 6));

    if (moving_avg == NULL)
    {
        perror("memory not allocated properly");
        return NULL;
    }

    for (int i = 3; i < arraySize - 3; i++)
    {
        moving_avg[i - 3] = quotient * (array1[i - 3] + array1[i - 2] + array1[i - 1] + array1[i] + array1[i + 1] + array1[i + 2] + array1[i + 3]);
    }

    return moving_avg;
}

double *binomial_filter3pt(double *array1, int arraySize)
{
    float quotient = 1.0 / 4.0;
    double *binomial_filter = malloc(sizeof(double) * (arraySize - 2));

    if (binomial_filter == NULL)
    {
        perror("memory not allocated");
        return NULL;
    }

    for (int i = 1; i < arraySize - 1; i++)
    {

        binomial_filter[i - 1] = quotient * (array1[i - 1] + 2 * array1[i] + array1[i + 1]);
    }

    return binomial_filter;
}
double *binomial_filter5pt(double *array1, int arraySize)
{
    float quotient = 1.0 / 16.0;
    double *binomical_filter = malloc(sizeof(double) * (arraySize - 4));

    if (binomical_filter == NULL)
    {
        perror("memory not allocated properly");
        return NULL;
    }

    for (int i = 2; i < arraySize - 2; i++)
    {
        binomical_filter[i - 2] = quotient * (array1[i - 2] + 4 * array1[i - 1] + 6 * array1[i] + 4 * array1[i + 1] + array1[i + 2]);
    }

    return binomical_filter;
}
double *binomial_filter7pt(double *array1, int arraySize)
{
    float quotient = 1.0 / 64.0;

    double *binomial_filter = malloc(sizeof(double) * (arraySize - 6));

    if (binomial_filter == NULL)
    {
        perror("memory not allocated properly");
        return NULL;
    }

    for (int i = 3; i < arraySize - 3; i++)
    {
        binomial_filter[i - 3] = quotient * (array1[i - 3] + 16 * array1[i - 2] + 15 * array1[i - 1] + 20 * array1[i] + 15 * array1[i + 1] + 6 * array1[i + 2] + array1[i + 3]);
    }

    return binomial_filter;
}