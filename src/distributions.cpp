#include "distributions.h" // Corresponding header file
#include <stdexcept>       // For exception handling

// Probability Mass Function (PMF) for Bernoulli distribution
double pmf_bernoulli(double x, double p) {
    // Validate the probability parameter
    if (p < 0.0 || p > 1.0) {
        throw std::invalid_argument("Probability p must be in the range [0, 1]");
    }

    // Check if x is valid (0 or 1)
    if (x != 0.0 && x != 1.0) {
        return 0.0; // Invalid outcomes have zero probability
    }

    // Return the probability for the given outcome
    return (x == 1.0) ? p : (1.0 - p);
}
