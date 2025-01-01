#include <iostream>
#include "random_generator.h"

int main() {
    unsigned int seed = 12345;  // Seed for the random number generator
    double p = 0.7;            // Probability of success
    int num_trials = 10;       // Number of trials

    std::cout << "Simulating Bernoulli trials with p = " << p << ":\n";
    for (int i = 0; i < num_trials; ++i) {
        try {
            int result = random_bernoulli(p, seed);
            std::cout << "Trial " << i + 1 << ": " << result << "\n";
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << "\n";
            return 1;
        }
    }

    return 0;
}
