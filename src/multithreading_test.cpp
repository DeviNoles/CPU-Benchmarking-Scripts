#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>
#include <sys/stat.h>

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

void calculate_primes(int start, int end, int thread_id, int& result_count) {
   int count = 0;
   for (int num = start; num <= end; ++num) {
       bool is_prime = true;
       for (int i = 2; i * i <= num; ++i) {
           if (num % i == 0) {
               is_prime = false;
               break;
           }
       }
       if (is_prime) count++;
   }
   result_count = count;
}

int main() {
   int num_threads = std::thread::hardware_concurrency();
   int range_per_thread = 100000 / num_threads;
   std::vector<std::thread> threads;
   std::vector<int> results(num_threads);

   auto start_time = std::chrono::high_resolution_clock::now();

   for (int i = 0; i < num_threads; ++i) {
       int start = i * range_per_thread + 1;
       int end = (i + 1) * range_per_thread;
       threads.emplace_back(calculate_primes, start, end, i + 1, std::ref(results[i]));
   }

   for (auto& t : threads) {
       t.join();
   }

   auto end_time = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> elapsed = end_time - start_time;

   write_to_csv("Multithreading Test", elapsed.count());
   std::cout << "Multithreading test completed. Time: " << elapsed.count() << " seconds" << std::endl;
   return 0;
}
