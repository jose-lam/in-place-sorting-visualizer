#ifndef VISUALIZER_API_HPP
#define VISUALIZER_API_HPP

#include <vector>
#include <cstddef>

namespace VisualizerApi {
    void run();

    std::size_t requestArraySize();

    std::vector<int> generateRandomData(std::size_t n);

}

#endif
