/**
 * @file assignment5.c
 * @brief main() function for MAP55613 Assignment 5. 
 * 	This file contains the main() function for MAP55613 Assignment 5.
 * 	The purpose of this assignment is to generate correlated random
 * 	numbers and perform a simple simulation using these numbers.
 * @author R. Morrin
 * @version 2.0
 * @date 2022-11-26
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <mkl_types.h>
#include <mkl_cblas.h>
#include "mkl.h"

#include "stats.h"
#include "simulation.h"
#include "matrix_utils.h"

int main(void)
{
    const unsigned long long int num_sims = 10000000; 	/* number of simulations */
    const lapack_int dim = 4; 				/* number of variates */
    double rhos[] = {0.01, 0.99, -0.33}; 		/* correlations we will use */

    double *rvs = mkl_malloc(sizeof *rvs * num_sims * dim, 64); /* holds rvs. Note sizeof(*rvs) */
    populate_std_gaussian_rvs(rvs, num_sims*dim); 		/* Populate independent rvs */

    double *corr = mkl_malloc(sizeof *corr * dim * dim, 64); 	/* hold correlation matrix */
    double *port = mkl_malloc(sizeof *port * num_sims, 64); 	/* Hold array of portfolio totals */
    //
    // NOTE: Remember to explicitly free up the memory allocated above
    // before the program exits. You will need to consider what is 
    // happening to the memory when the process forks. 
    //


    const int NUM_CHILDREN = 2;
    int pipefd[NUM_CHILDREN][2]; 	/* 2D array to hold file descriptors for pipes */

    //
    // Open a pipe to communicate with first child
    //
    // Remember to close the appropriate ends of the 
    // pipe in the parent and child processes
    //

    //
    //  Note: Remember to add error checking for fork etc.
    //
    pid_t pid = fork();  	/* Fork first child 	*/
    if(pid==0){ 		/* Child                */

	build_corr_mat(corr, rhos[1], dim); 	/* Build corr matrix for rhos[1] */
	cholesky_decompose(corr, dim); 		/* Find Cholesky decomposition for this matrix */

	double *ptr = rvs; 	/* Pointer to keep track of location we are working on in rvs */
        //  
        // Use the above ptr as an argument when calling 
        // transform_to_correlated(...) in a loop in order to  
        // transform all of the random variates to correlated.
        // You will transform each set of 4 at a time. So you 
        // will have num_sims iterations.
        // (You can use pointer arithmetic with ptr.) 
        //  


	portfolio_sums(rvs, port, dim, num_sims); 	/* Calculate the array of portfolio totals */

	double mean = calculate_mean(port, num_sims); 	/* Calculate the mean of the portfolio totals */
	double variance = calculate_variance(port, num_sims); /* Calculate variance of portfolio totals */

	//
	// Write the following quantitites back to the parent process
	//  (1) Lower trangular matrix from Cholesky
	//  (2) Calculated mean
	//  (3) Calculated Variance
	//
	// Then clean up and exit child process
    }


    //
    // Do the same procedure as above to fork a second process which 
    // will calculate the simulation for rhos[2]. You will obviously
    // need a second pipe. Don't forget error checking
    //

    pid_t pid2 = fork();
    if(pid2==0){ 		/* Second Child                	 */
	//
	// You need to write code here
	//
    }

    
    /* Do the calculation in the parent process for rhos[0] */
    
    build_corr_mat(corr, rhos[0], dim);
    cholesky_decompose(corr, dim);

    double *ptr = rvs;
    //
    // Transform for rhos[0]
    // Use a loop a ptr the same as for first child process
    //


    portfolio_sums(rvs, port, dim, num_sims); /* Calculate portfolio totals */

    double mean = calculate_mean(port, num_sims);
    double var = calculate_variance(port, num_sims);


    /* Print parent process data to screen */
    zero_out_upper(corr, dim);
    printf("-------------- rho = %0.2lf --------------\nOriginal Matrix:\n", rhos[0]);
    printf("Cholesky lower:\n");
    print_flat_matrix(corr, dim);
    printf("Expected value =  %lf\n", mean );
    printf("Variance =  %lf\n\n", var );

    //
    // Now Read values from both child processes and 
    // print. You can overwrite the memory used to store
    // corr/mean/var above. i.e. Read from first child
    // and then print to screen. Then read from second 
    // child and print to screen. Then tidy up any 
    // allocated memory before exiting.
    //

    return 0;
}
