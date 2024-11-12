#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>

// Helper function to check if the file exists
bool file_exists(const std::string& filename) {
   struct stat buffer;
   return (stat(filename.c_str(), &buffer) == 0);
}

// Function to write the header and row to CSV if necessary
void write_to_csv(const std::string& test_name, double write_time = -1, double read_time = -1) {
   std::ofstream file;
   const std::string filename = "../cpu_benchmark_results.csv";

   if (!file_exists(filename)) {
       file.open(filename, std::ios::app);
       file << "Test Name,Write Time,Read Time\n";
   }
   else {
       file.open(filename, std::ios::app);
   }

   file << test_name << "," << write_time << "," << read_time << "\n";
   file.close();
}

void memory_bandwidth_test() {
   const size_t size = 50 * 1024 * 1024; // Reduced array size to 50 MB for testing
   std::vector<int> data(size, 1);

   auto start_time = std::chrono::high_resolution_clock::now();
   for (size_t i = 0; i < size; ++i) {
       data[i] = i;
   }
   auto end_time = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> write_time = end_time - start_time;

   volatile int sum = 0;
   start_time = std::chrono::high_resolution_clock::now();
   for (size_t i = 0; i < size; ++i) {
       sum += data[i];
   }
   end_time = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> read_time = end_time - start_time;

   write_to_csv("Memory Bandwidth Test", write_time.count(), read_time.count());
   std::cout << "Memory bandwidth test completed. Write time: " << write_time.count()
       << ", Read time: " << read_time.count() << " seconds" << std::endl << std::flush;
}

int main() {
   memory_bandwidth_test();
   return 0;
}
