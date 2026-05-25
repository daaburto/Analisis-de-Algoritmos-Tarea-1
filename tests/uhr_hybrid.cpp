#include <cstdint>
#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "../uhr/utils.cpp"
#include "../src/hybrid.hpp"
#include "../src/matriz.hpp"

int main(int argc, char *argv[])
{
    // argv: <filename> <runs> <lower> <upper> <step> <instancia> <n0>
    std::string filename = argv[1];
    std::int64_t runs = std::stoll(argv[2]);
    std::int64_t lower = std::stoll(argv[3]);
    std::int64_t upper = std::stoll(argv[4]);
    std::int64_t step = std::stoll(argv[5]);
    std::string instancia = argv[6];
    int n0 = std::stoi(argv[7]);

    std::int64_t total_runs_multiplicative = runs * (floor(log(upper / double(lower)) / log(step)) + 1);
    std::vector<double> times(runs);
    std::vector<double> q;
    double mean_time, time_stdev, dev;
    auto begin_time = std::chrono::high_resolution_clock::now();
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> elapsed_time = end_time - begin_time;

    std::ofstream time_data;
    time_data.open(filename);
    time_data << "n,t_mean,t_stdev,t_Q0,t_Q1,t_Q2,t_Q3,t_Q4" << std::endl;

    std::cerr << "\033[0;36mRunning tests...\033[0m" << std::endl << std::endl;
    std::int64_t executed_runs = 0;

    for (std::int64_t n = lower; n <= upper; n *= step) {
        mean_time  = 0;
        time_stdev = 0;

        auto A = load_matrix("matrices/" + instancia + "/A_" + std::to_string(n) + ".txt");
        auto B = load_matrix("matrices/" + instancia + "/B_" + std::to_string(n) + ".txt");

        for (std::int64_t i = 0; i < runs; i++) {
            display_progress(++executed_runs, total_runs_multiplicative);

            begin_time = std::chrono::high_resolution_clock::now();
            auto C = hybrid(A, B, n0);
            end_time = std::chrono::high_resolution_clock::now();

            elapsed_time = end_time - begin_time;
            times[i] = elapsed_time.count();
            mean_time += times[i];
        }

        mean_time /= runs;

        for (std::int64_t i = 0; i < runs; i++) {
            dev = times[i] - mean_time;
            time_stdev += dev * dev;
        }

        time_stdev /= runs - 1;
        time_stdev = std::sqrt(time_stdev);

        quartiles(times, q);

        time_data << n << "," << mean_time << "," << time_stdev << ",";
        time_data << q[0] << "," << q[1] << "," << q[2] << "," << q[3] << "," << q[4] << std::endl;
    }

    std::cerr << std::endl << std::endl;
    std::cerr << "\033[1;32mDone!\033[0m" << std::endl;

    time_data.close();
    return 0;
}