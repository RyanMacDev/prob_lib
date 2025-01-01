#include <iostream>
#include <vector>
#include <numeric>
#include "random_generator.h"
#include "distributions.h"

void print_statistics(const std::vector<int>& samples) {
    double mean = std::accumulate(samples.begin(), samples.end(), 0.0) / samples.size();
    double variance = 0.0;
    for (const auto& sample : samples) {
        variance += (sample - mean) * (sample - mean);
    }
    variance /= samples.size();

    std::cout << "Mean: " << mean << "\n";
    std::cout << "Variance: " << variance << "\n";
}

int main() {
    unsigned int seed = 12345; // Seed for PRNG

    // Bernoulli Distribution
    DistributionParams bernoulli_params = {0.5, 0}; // p = 0.7
    std::cout << "Bernoulli Distribution (p = " << bernoulli_params.p << "):\n";

    std::vector<int> bernoulli_samples;
    for (int i = 0; i < 10; ++i) {
        int sample = random_sample(DistributionType::Bernoulli, bernoulli_params, seed);
        bernoulli_samples.push_back(sample);
        std::cout << "Sample " << i + 1 << ": " << sample << "\n";
    }
    print_statistics(bernoulli_samples);

    // Binomial Distribution
    DistributionParams binomial_params = {0.5, 10}; // p = 0.5, n = 10
    std::cout << "\nBinomial Distribution (p = " << binomial_params.p
              << ", n = " << binomial_params.n << "):\n";

    std::vector<int> binomial_samples;
    for (int i = 0; i < 10; ++i) {
        int sample = random_sample(DistributionType::Binomial, binomial_params, seed);
        binomial_samples.push_back(sample);
        std::cout << "Sample " << i + 1 << ": " << sample << "\n";
    }
    print_statistics(binomial_samples);

    // Display Binomial PMF
    std::cout << "\nBinomial PMF (n = " << binomial_params.n << ", p = " << binomial_params.p << "):\n";
    for (int k = 0; k <= binomial_params.n; ++k) {
        std::cout << "P(X = " << k << ") = " << pmf_binomial(k, binomial_params.n, binomial_params.p) << "\n";
    }

    return 0;
}
