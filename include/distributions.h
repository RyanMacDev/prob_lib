#ifndef DISTRIBUTIONS_H
#define DISTRIBUTIONS_H

// Discrete distributions
double pmf_bernoulli(double x, double p);
double pmf_binomial(int k, int n, double p);
double pmf_geometric(int k, double p);
double pmf_poisson(int k, double lambda);

// Continuous distributions
double pdf_uniform(double x, double a, double b);
double pdf_normal(double x, double mean, double stddev);
double pdf_exponential(double x, double lambda);

#endif // DISTRIBUTIONS_H
