#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <stdexcept>
#include <variant>
#include <string>

// Enum for distribution types
enum class DistributionType {
    Bernoulli,
    Binomial
};

// Struct for distribution parameters
struct DistributionParams {
    double p; // Success probability (for Bernoulli and Binomial)
    int n;    // Number of trials (for Binomial only, optional for Bernoulli)
};

// Generalized random sampler
int random_sample(DistributionType type, const DistributionParams& params, unsigned int& seed);

#endif // RANDOM_GENERATOR_H
