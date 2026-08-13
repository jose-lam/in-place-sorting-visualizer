#ifndef VISUALIZER_API_HPP
#define VISUALIZER_API_HPP

#include <vector>
#include <string>
#include <cstddef>

namespace VisualizerApi {

    struct AlgorithmResult {
        std::string name;
        double elapsedMicroseconds;
        long long theoreticalOperations;
        long long realOperations;
        bool skipped;
        std::string skipReason;
    };

    void run();

    std::size_t requestArraySize();

    std::vector<int> generateRandomData(std::size_t n);

    std::vector<AlgorithmResult> executeAlgorithms(const std::vector<int>& originalData);

    long long computeTheoreticalOperations(const std::string& algorithmName, std::size_t n);

    void renderDashboard(const std::vector<AlgorithmResult>& results, std::size_t n);

}

#endif
