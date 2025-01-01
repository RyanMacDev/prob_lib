#include "random_generator.h"
#include <stdexcept>  // Include for std::invalid_argument
#include <cstdint>    // Include for uint64_t

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

// Generate Bernoulli random variable
int random_bernoulli(double p, unsigned int& seed) {
    if (p < 0.0 || p > 1.0) {
        throw std::invalid_argument("Probability p must be in the range [0, 1]");
    }
    double rand_num = my_random(seed);
    return (rand_num < p) ? 1 : 0;
}
