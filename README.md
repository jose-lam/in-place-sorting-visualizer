# In-Place Sorting Visualizer

![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![CMake](https://img.shields.io/badge/build-CMake-064F8C.svg)
![CI](https://github.com/jose-lam/in-place-sorting-visualizer/actions/workflows/ci.yml/badge.svg)

A console-based C++17 project that implements and benchmarks three in-place sorting algorithms — **Shell Sort**, **Heap Sort**, and **Insertion Sort** — against randomly generated data, comparing their theoretical (Big-O) and real instrumented operation counts.

---

## Demo

<!-- DEMO_GIF_PLACEHOLDER: Insert a demonstration GIF here showing the program running for a sample n value. -->

---

## Features

- Runtime-configurable input size `n` (10 ≤ n ≤ 10,000,000).
- Random data generation via `std::uniform_int_distribution`.
- Each algorithm runs on an independent copy of the same original dataset.
- Automatic safeguard: Insertion Sort is skipped for `n > 100,000` to avoid excessive runtime, with a warning shown on the dashboard.
- ASCII dashboard reporting execution time, theoretical operation count, and real (instrumented) operation count per algorithm.
- Automated correctness tests validating output against `std::sort`, including a large-scale case (`n = 10,000,000`).
- Continuous Integration via GitHub Actions (build + test on every push/PR).

---

## Project Structure

```
in-place-sorting-visualizer/
├── include/           # Header files (class declarations)
├── src/                # Implementation files
├── tests/              # Correctness tests
├── .github/workflows/  # CI configuration
├── main.cpp            # Minimal entry point
└── CMakeLists.txt      # Build configuration
```

---

## Build Instructions

Requirements: CMake ≥ 3.2 and a C++17-compliant compiler (GCC, Clang, or MSVC).

```bash
git clone https://github.com/jose-lam/in-place-sorting-visualizer.git
cd in-place-sorting-visualizer
cmake -B build -S .
cmake --build build
./build/in-place-sorting-visualizer
```

### Running Tests

```bash
cd build
ctest --output-on-failure
```

---

## Theoretical vs. Real Operations

The dashboard reports two operation counts side by side:

- **Theoretical Operations**: the raw Big-O expression evaluated for the given `n` (e.g., `n log₂ n` for Heap Sort), computed with an implicit constant of 1.
- **Real Operations**: the actual number of element comparisons and shifts/swaps performed, instrumented directly inside each algorithm.

| Algorithm      | Big-O (average case) | Typical relationship (real vs. theoretical) | Why |
|----------------|----------------------|----------------------------------------------|-----|
| Shell Sort     | O(n^1.5) (Knuth gaps) | Real tends to be lower than the raw formula | The n^1.5 bound is a loose upper estimate for Knuth's gap sequence; actual comparisons per pass are fewer since most elements are already close to their position after each pass. |
| Heap Sort      | O(n log n)            | Real tends to be noticeably higher than the raw formula | The raw `n log₂ n` formula hides a constant factor: `heapify` can perform up to two comparisons per level (left and right child), and this happens both during build-heap and during every one of the `n-1` extraction steps. |
| Insertion Sort | O(n²) (worst case)    | Real tends to be well below n² | O(n²) represents the *worst case* (reverse-sorted input). With uniformly random data, the expected number of comparisons is closer to n²/4, since on average an element only needs to move about halfway back through the sorted prefix. |

**Key takeaway:** Big-O notation describes the *order of growth*, not an exact operation count — it deliberately hides constant factors and assumes worst-case or idealized conditions. This project intentionally shows the raw, uncalibrated theoretical formula next to the real instrumented count to make that gap visible, rather than artificially tuning constants to make the numbers match.

---

## Algorithms Implemented

| Algorithm      | Time Complexity (avg) | Space Complexity | Stable |
|----------------|------------------------|-------------------|--------|
| Shell Sort     | O(n^1.5)               | O(1)               | No     |
| Heap Sort      | O(n log n)             | O(1)               | No     |
| Insertion Sort | O(n²)                  | O(1)               | Yes    |

## Developer's Note
 
The sorting algorithms and their core logic were implemented and studied by me. For the project infrastructure (CMake configuration, GitHub Actions CI, and the console dashboard), I used AI assistance to speed up development and apply good C++ project structuring practices.
