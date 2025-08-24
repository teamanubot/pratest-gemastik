#ifndef MONITORING_H
#define MONITORING_H

#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

namespace monitoring {
    static std::chrono::high_resolution_clock::time_point _start_time, _end_time;
    static long _memory_used_kb = 0;

    inline void start_monitoring() {
        _start_time = std::chrono::high_resolution_clock::now();
    }

    inline void stop_monitoring() {
        _end_time = std::chrono::high_resolution_clock::now();

        // Baca penggunaan memori dari /proc/self/status (Linux)
        std::ifstream status_file("/proc/self/status");
        std::string line;
        while (std::getline(status_file, line)) {
            if (line.rfind("VmRSS:", 0) == 0) {
                std::sscanf(line.c_str(), "VmRSS: %ld kB", &_memory_used_kb);
                break;
            }
        }
    }

    inline void print_monitoring() {
        auto duration_us = std::chrono::duration_cast<std::chrono::microseconds>(_end_time - _start_time).count();
        std::cerr << "Execution time: " << duration_us << " µs\n";
        std::cerr << "Memory used: " << _memory_used_kb << " KB\n";

        const long TIME_LIMIT_US = 1'000'000;  // 1 detik
        const long MEM_LIMIT_KB  = 32 * 1024;  // 32 MB

        if (duration_us <= TIME_LIMIT_US && _memory_used_kb <= MEM_LIMIT_KB) {
            std::cerr << "✅ Constraints met: <= 1s and <= 32MB\n";
        } else {
            std::cerr << "❌ Constraints NOT met\n";
        }
    }
}

using monitoring::start_monitoring;
using monitoring::stop_monitoring;
using monitoring::print_monitoring;

#endif // MONITORING_H