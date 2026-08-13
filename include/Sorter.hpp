#ifndef SORTER_HPP
#define SORTER_HPP

#include <string>
#include <vector>

class Sorter {
public:
    explicit Sorter(std::string algorithmName);
    virtual ~Sorter() = default;

    virtual void sort(std::vector<int>& arr) = 0;

    const std::string& getName() const;
    long long getOperations() const;

protected:
    std::string name;
    long long operations;
};

#endif
