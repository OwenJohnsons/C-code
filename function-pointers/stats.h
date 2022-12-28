#ifndef STATS_H_5BZQYSIS
#define STATS_H_5BZQYSIS

void portfolio_sums(double const * vals, double *const port_vals, const int dim, const int num_sims);
double calculate_mean(double const *const val, const int n);
double calculate_variance(double const *const val, const int n);

#endif /* end of include guard: STATS_H_5BZQYSIS */
