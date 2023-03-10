#ifndef STATS_H_5BZQYSIS
#define STATS_H_5BZQYSIS

void portfolio_sums(double const * vals, double *const port_vals, const int dim, const int num_sims);
double calculate_mean(double const *const val, const int n);
double calculate_variance(double const *const val, const int n);

/* Function Definitions */
void portfolio_sums(double const * vals, double *const port_vals, const int dim, const int num_sims)
{
    for (int i = 0; i < num_sims; ++i) { // Loop over simulations
        double sum = 0.0;                  
        for (int j = 0; j < dim; ++j) {  // Sum of portfolio values
            sum += vals[i * dim + j]; 
        }
        port_vals[i] = sum;
    }
}

double calculate_mean(double const *const val, const int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += val[i];
    }
    return sum / n;
}

double calculate_variance(double const *const val, const int n)
{
    double mean = calculate_mean(val, n); // Calling back mean function
    double sum = 0.0; // Sum of squares
    for (int i = 0; i < n; ++i) {
        sum += (val[i] - mean) * (val[i] - mean); // (x - mean)^2
    }
    return sum / n;
}

#endif /* end of include guard: STATS_H_5BZQYSIS */
