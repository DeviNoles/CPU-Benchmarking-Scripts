#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <sys/stat.h>

const int ARRAY_SIZE = 10 * 1024 * 1024; // 10 MB array

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


void cache_test() {
   int* data = new int[ARRAY_SIZE];
   auto start_time = std::chrono::high_resolution_clock::now();
   for (int i = 0; i < ARRAY_SIZE; ++i) {
       data[i] = i;
   }
   auto end_time = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> write_time = end_time - start_time;

   write_to_csv("Cache Performance Test", write_time.count());
   delete[] data;
   std::cout << "Cache performance test completed. Time: " << write_time.count() << " seconds" << std::endl;
}

int main() {
   cache_test();
   return 0;
}
