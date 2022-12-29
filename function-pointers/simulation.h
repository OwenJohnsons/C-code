/**
 * @file simulation.h
 * @brief Header file for simulation related functions for MAP5613 Assignment 5 2022
 * @author R. Morrin
 * @version 2.0
 * @date 2022-11-26
 */
#ifndef SIMULATION_H_WKIRHZEZ
#define SIMULATION_H_WKIRHZEZ

#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <mkl_types.h>
#include <mkl_cblas.h>
#include "mkl.h"
#include <string.h>

unsigned long get_seed_from_random_device();
void populate_std_gaussian_rvs(double *const rngs, const long long int n);
void build_corr_mat(double *const mat, const double rho, const int dim);
void transform_to_correlated(double const *const C, double *const correlated, const int dim);
void cholesky_decompose(double *const matrix_data, const int dim);

/* Function Definitions */

get_seed_from_random_device()
{
    FILE *fp;
    unsigned long seed;
    fp = fopen("/dev/urandom", "r");
    fread(&seed, sizeof(seed), 1, fp);
    fclose(fp);
    return seed;
}

void populate_std_gaussian_rvs(double *const rngs, const long long int n)
{
    gsl_rng *r = gsl_rng_alloc(gsl_rng_mt19937);
    gsl_rng_set(r, get_seed_from_random_device());
    for (int i = 0; i < n; ++i) {
        rngs[i] = gsl_ran_ugaussian(r);
    }
    gsl_rng_free(r);
}

build_corr_mat(double *const mat, const double rho, const int dim)
{
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            if (i == j) {
                mat[i * dim + j] = 1.0;
            } else {
                mat[i * dim + j] = rho;
            }
        }
    }
}

transform_to_correlated(double const *const C, double *const correlated, const int dim)
{
    double *L = (double *)malloc(dim * dim * sizeof(double));
    memcpy(L, C, dim * dim * sizeof(double));
    cholesky_decompose(L, dim);
    double *rngs = (double *)malloc(dim * sizeof(double));
    populate_std_gaussian_rvs(rngs, dim);
    cblas_dgemv(CblasRowMajor, CblasNoTrans, dim, dim, 1.0, L, dim, rngs, 1, 0.0, correlated, 1);
    free(L);
    free(rngs);
}

cholesky_decompose(double *const matrix_data, const int dim)
{
    int info;
    LAPACKE_dpotrf(LAPACK_ROW_MAJOR, 'U', dim, matrix_data, dim);
}

#endif /* end of include guard: SIMULATION_H_WKIRHZEZ */
