/**
 * \file matrix_utils.h
 * \brief Header file for some matrix utility functions for MAP55613 Assignment 5 2022
 * \author Owen A. Johnson
 * \version 1.0
 * \date 2022-12-24
 */
#ifndef MATRIX_IO_H_IMA05IJX
#define MATRIX_IO_H_IMA05IJX

void zero_out_upper(double *const x, int const dim);
void print_flat_matrix(double const *const x, int const dim);

/* Function Definitions */
void zero_out_upper(double *const x, int const dim) // 
{
    for (int i = 0; i < dim; ++i) {
        for (int j = i + 1; j < dim; ++j) {
            x[i * dim + j] = 0.0;
        }
    }
}

void print_flat_matrix(double const *const x, int const dim)
{
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            printf("%f ", x[i * dim + j]);
        }
        printf("\n");
    }
}

#endif /* end of include guard: MATRIX_IO_H_IMA05IJX */
