# CPU Benchmarking Scripts

A collection of C++ benchmarking scripts to evaluate various CPU and system performance characteristics. This project includes tests for multithreading efficiency, memory bandwidth, cache performance, floating-point calculations, and disk I/O throughput.
## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Benchmark Descriptions](#benchmark-descriptions)
- [Contributing](#contributing)
- [License](#license)
## Overview

The CPU Benchmarking Scripts project is designed to test the performance capabilities of modern x64 CPUs by measuring critical metrics such as processing power, memory throughput, and disk read/write speeds. Results are saved to a CSV file for easy comparison and analysis.
## Features

- **Multithreading Test**: Measures CPU performance across multiple threads.
- **Cache Performance Test**: Benchmarks cache speed using sequential access patterns.
- **Memory Bandwidth Test**: Evaluates RAM read/write bandwidth.
- **Floating-Point Calculation Test**: Assesses floating-point calculation throughput.
- **Disk I/O Performance Test**: Measures sequential disk read and write speeds.

## Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/DeviNoles/cpu-benchmarking-scripts.git
   cd cpu-benchmarking-scripts

2. **Build the Project**:
   * ##### Using Visual Studio: 
        * Open CPU-Benchmark.sln in Visual Studio.
        * Build the solution by going to Build > Build Solution.
        
    * ##### Using CMake
    ````bash
        mkdir build
        cd build
        cmake ..
        cmake --build .

3. **Dependencies**
    * #### C++11 or later is required to compile the scripts.
    * #### CMake (optional) for cross-platform builds.

## Usage

Each script can be run individually from the command line or directly from your IDE.

1. Run a Benchmark:

   - In Visual Studio, right-click on any script (e.g., `multithreading_test.cpp`) in the `src` folder and select `Set as Startup Item`.
   - Press **F5** to compile and run the selected benchmark.

2. Output:

   - Each benchmark appends its results to `cpu_benchmark_results.csv` located in the project root.
   - The CSV file format:
     ```
     Test Name,Write Time,Read Time
     Multithreading Test,0.55,-1,
     Cache Performance Test,1.35,-1,
     Memory Bandwidth Test,0.8,0.5
     Floating-Point Calculation Test,1.1,-1,
     Disk I/O Test,0.75,0.65
     ```

## Benchmark Descriptions

### 1. Multithreading Test
Tests the CPU's multithreading capability by calculating prime numbers across multiple threads.

- **Output**: Total computation time in seconds.

### 2. Cache Performance Test
Measures data access speeds in different cache levels by sequentially accessing elements in a large array.

- **Output**: Access latency in seconds.

### 3. Memory Bandwidth Test
Evaluates the maximum bandwidth of your system's RAM by performing sequential read and write operations on a large array.

- **Outputs**:
  - **Write Time**: Time taken to write data.
  - **Read Time**: Time taken to read data.

### 4. Floating-Point Calculation Test
Performs intensive floating-point operations to assess the CPU’s floating-point unit (FPU) performance.

- **Output**: Calculation time in seconds.

### 5. Disk I/O Performance Test
Measures the performance of your storage device by writing and reading a 100 MB binary file.

- **Outputs**:
  - **Write Time**: Time taken to write data.
  - **Read Time**: Time taken to read data.

## Contributing

Contributions are welcome! To contribute:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes and commit them (`git commit -m 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a Pull Request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
