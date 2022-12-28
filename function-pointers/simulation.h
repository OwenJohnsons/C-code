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

#endif /* end of include guard: SIMULATION_H_WKIRHZEZ */
