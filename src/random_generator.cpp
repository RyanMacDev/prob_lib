#include "random_generator.h"
#include <cstdint>
#include <stdexcept>
#include <iostream>

// Parameters for the LCG
const uint64_t a = 1664525;
const uint64_t c = 1013904223;
const uint64_t m = 4294967296; // 2^32

// Linear Congruential Generator (LCG)
unsigned int lcg(unsigned int seed) {
    return (a * seed + c) % m;
}

// Generate random numbers in [0, 1)
double my_random(unsigned int& seed) {
    seed = lcg(seed);
    return static_cast<double>(seed) / m;
}
int random_sample(DistributionType type, const DistributionParams& params, unsigned int& seed) {
    double rand_num;

    switch (type) {
    case DistributionType::Bernoulli:
        // Validate probability
        if (params.p < 0.0 || params.p > 1.0) {
            throw std::invalid_argument("Probability p must be in the range [0, 1]");
        }
        rand_num = my_random(seed);
        return (rand_num < params.p) ? 1 : 0;

    case DistributionType::Binomial: {
        // Validate probability and number of trials
        if (params.p < 0.0 || params.p > 1.0) {
            throw std::invalid_argument("Probability p must be in the range [0, 1]");
        }
        if (params.n < 0) {
            throw std::invalid_argument("Number of trials n must be non-negative");
        }

        // Binomial calculation
        int successes = 0;
        for (int i = 0; i < params.n; ++i) {
            rand_num = my_random(seed);
            if (rand_num < params.p) {
                successes++;
            }
        }
        return successes;
    }

    default:
        throw std::invalid_argument("Unsupported distribution type");
    }
}
