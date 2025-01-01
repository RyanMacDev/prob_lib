#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

// PRNG function
unsigned int lcg(unsigned int seed);

// Generate random numbers in [0, 1)
double my_random(unsigned int& seed);

// Generate Bernoulli random variable
int random_bernoulli(double p, unsigned int& seed);

#endif // RANDOM_GENERATOR_H
