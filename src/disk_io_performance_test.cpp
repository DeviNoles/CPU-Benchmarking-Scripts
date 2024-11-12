#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <string>
#include <sys/stat.h>

const size_t FILE_SIZE_MB = 100; // 100 MB file
const std::string FILENAME = "disk_test_file.bin";

// Helper function to check if the file exists
bool file_exists(const std::string& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

// Function to write the header and row to CSV if necessary
void write_to_csv(const std::string& test_name, double write_time = -1, double read_time = -1) {
    std::ofstream file;
    const std::string filename = "../cpu_benchmark_results.csv";

    // Check if the file exists; if not, write the header
    if (!file_exists(filename)) {
        file.open(filename, std::ios::app);
        file << "Test Name,Write Time,Read Time\n";
    }
    else {
        file.open(filename, std::ios::app);
    }

    // Write the test data row
    file << test_name << "," << write_time << "," << read_time << "\n";
    file.close();
}

void disk_io_test() {
    // Create a buffer of 100 MB for write/read test
    std::vector<char> data(FILE_SIZE_MB * 1024 * 1024, 'a'); // 100 MB data block

    // Write test
    std::ofstream file(FILENAME, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Unable to open file for writing.\n";
        return;
    }

    auto start_time = std::chrono::high_resolution_clock::now();
    file.write(data.data(), data.size());
    file.close();
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> write_time = end_time - start_time;

    // Read test
    std::ifstream read_file(FILENAME, std::ios::binary);
    if (!read_file) {
        std::cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    start_time = std::chrono::high_resolution_clock::now();
    read_file.read(data.data(), data.size());
    read_file.close();
    end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> read_time = end_time - start_time;

    // Write results to CSV
    write_to_csv("Disk I/O Test", write_time.count(), read_time.count());
    std::cout << "Disk I/O test completed. Write time: " << write_time.count()
        << ", Read time: " << read_time.count() << " seconds" << std::endl;
}

int main() {
    disk_io_test();
    return 0;
}
