#include <stdio.h>
#include <stdlib.h>
#include "datahandling.h"
#include "filtering.h"

int main()
{
    size_t num_csv_rows = 4;
    // read in data
    size_t dataSize = 0;
    datarow *data = readData("FIR_Data.csv", &dataSize); // call readdata function

    if (data == NULL)
    {
        fprintf(stderr, "Failed to read data\n");
        return EXIT_FAILURE;
    }

    printf("Total data read: %zu\n", dataSize);

    // add the noise onto the original signal

    // write data
    const char *outputFilename = "output_data.csv"; // create output file  name for time and signal
    // create array of pointers to data

    double **arrays = malloc(num_csv_rows * sizeof(double *)); // allcoate memory for data file
    if (arrays == NULL)
    {
        perror("memory allocation failed");
        free(data);
        return EXIT_FAILURE;
    }

    // Allocate memory for each array
    for (size_t i = 0; i < num_csv_rows; i++)
    {
        arrays[i] = malloc(dataSize * sizeof(double));
        if (arrays[i] == NULL)
        {
            perror("memory allocation failed");
            free(data);
            for (size_t j = 0; j < i; j++)
            {
                free(arrays[j]);
            }
            free(arrays);
            return EXIT_FAILURE;
        }
    }

    // fill data arrays
    for (size_t i = 0; i < dataSize; i++)
    {
        arrays[0][i] = data[i].time;
        arrays[1][i] = data[i].signal;
        arrays[2][i] = data[i].noise;
        arrays[3][i] = data[i].signal + data[i].noise;
    }

    // do three point average and write to csv file

    double *array_3pt_mov_avg = moving_avg3pt(arrays[3], dataSize); // find 3pt moving average for signal+noise array
    if (array_3pt_mov_avg == NULL)
    {
        perror("memory not allocated");
    }
    else
    {
        const char *mov_avg_3ptFilename = "three_point_mov_avg.csv";                 // write three point mvving average
        writeSingleArrayToCSV(mov_avg_3ptFilename, array_3pt_mov_avg, dataSize - 2); // make sure first and last row removeed hence dataSize -2
    }

    double *array_5pt_mov_avg = moving_avg5pt(arrays[3], dataSize); // finnd 5pt moving average
    if (array_5pt_mov_avg == NULL)
    {
        perror("memory not allocated properly");
        free(array_5pt_mov_avg);
    }
    else
    {
        const char *moving_avg5ptFilename = "five_point_mov_avg.csv";
        writeSingleArrayToCSV(moving_avg5ptFilename, array_5pt_mov_avg, dataSize - 4);
    }
    double *array_7pt_mov_avg = moving_avg7pt(arrays[3], dataSize); // finnd 5pt moving average
    if (array_7pt_mov_avg == NULL)
    {
        perror("memory not allocated properly");
        free(array_7pt_mov_avg);
    }
    else
    {
        const char *moving_avg7ptFilename = "seven_point_mov_avg.csv";
        writeSingleArrayToCSV(moving_avg7ptFilename, array_7pt_mov_avg, dataSize - 6);
    }

    /* Binomial Filtering */

    double *array_3pt_binomial = binomial_filter3pt(arrays[3], dataSize); // find 3pt binomial for signal+noise array
    if (array_3pt_binomial == NULL)
    {
        perror("memory not allocated");
    }
    else
    {
        const char *binomial3pt_filename = "three_point_binomial.csv";                 // write three point mvving average
        writeSingleArrayToCSV(binomial3pt_filename, array_3pt_binomial, dataSize - 2); // make sure first and last row removeed hence dataSize -2
    }
    double *array_5pt_binomial = binomial_filter5pt(arrays[3], dataSize); // finnd 5pt moving average
    if (array_5pt_binomial == NULL)
    {
        perror("memory not allocated properly");
        free(array_5pt_binomial);
    }
    else
    {
        const char *binomial5pt_filename = "five_point_binomial.csv";
        writeSingleArrayToCSV(binomial5pt_filename, array_5pt_binomial, dataSize - 4);
    }
    double *array_7pt_binomial = binomial_filter7pt(arrays[3], dataSize); // finnd 5pt moving average
    if (array_7pt_binomial == NULL)
    {
        perror("memory not allocated properly");
        free(array_7pt_binomial);
    }
    else
    {
        const char *binomial_7ptFilename = "seven_point_binomial.csv";
        writeSingleArrayToCSV(binomial_7ptFilename, array_7pt_binomial, dataSize - 6);
    }

    writeArraysToCSV(outputFilename, arrays, num_csv_rows, dataSize); // write og data array

    // Free dynamically allocated memory
    for (size_t i = 0; i < num_csv_rows; i++)
    {
        free(arrays[i]);
    }
    free(data);
    free(array_3pt_mov_avg);
    free(array_5pt_mov_avg);
    free(array_7pt_mov_avg);

    return EXIT_SUCCESS;
}
