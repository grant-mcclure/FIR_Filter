#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datahandling.h"

datarow *readData(const char *filename, size_t *size)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("error opening file");
        return NULL;
    }

    size_t capacity = 1000; // set arbitrary number of memory that needs to be allocated then need to realloc

    datarow *data = malloc(capacity * sizeof(datarow)); // dynamically allocate memory for data row struct

    if (data == NULL)
    {
        perror("memory allocation failed!");
        return NULL;
    }

    char line[1024];
    *size = 0; // start from zero

    while (fgets(line, sizeof(line), file))
    {
        if (*size >= capacity)
        {
            capacity *= 2;
            datarow *temp = realloc(data, capacity * sizeof(datarow));

            if (temp == NULL)
            {
                perror("memory allocation failed");
                free(data);
                fclose(file);
                return NULL;
            }
            data = temp;
        }

        if (sscanf(line, "%lf,%lf,%lf", &data[*size].time, &data[*size].signal, &data[*size].noise) == 3)
        {
            (*size)++; // Only increment size if the line was successfully read
        }
    }
    fclose(file);
    return data;
}

void writeArraysToCSV(const char *filename, double **arrays, size_t numArrays, size_t numRows)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("error opening file");
        return;
    }

    // Write data to CSV
    for (size_t i = 0; i < numRows; i++)
    {
        for (size_t j = 0; j < numArrays; j++)
        {
            fprintf(file, "%.6lf", arrays[j][i]);
            if (j != numArrays - 1)
            {
                fprintf(file, ",");
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Data has been written to %s successfully!\n", filename);
}

void writeSingleArrayToCSV(const char *filename, double *array, size_t size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (size_t i = 0; i < size; i++) {
        fprintf(file, "%lf\n", array[i]);
    }

    fclose(file);
    printf("Data has been written to %s successfully!\n", filename);

    
}
