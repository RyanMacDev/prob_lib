#include "distributions.h" // Corresponding header file
#include <cmath>
#include <stdexcept>       // For exception handling

// Helper: Compute factorial
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Helper: Compute binomial coefficient
unsigned long long binomial_coefficient(int n, int k) {
    if (k > n) return 0;
    return factorial(n) / (factorial(k) * factorial(n - k));
}

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

double pmf_binomial(int k, int n, double p) {
    if (p < 0.0 || p > 1.0) {
        throw std::invalid_argument("Probability p must be in the range [0, 1]");
    }
    if (k < 0 || k > n) {
        return 0.0; // Invalid number of successes
    }
    return binomial_coefficient(n, k) * pow(p, k) * pow(1 - p, n - k);
}


