#include <chrono>
using namespace std;

struct timer {
    using T = chrono::high_resolution_clock::time_point;
    timer() : start(chrono::high_resolution_clock::now()) {}
    double now() {
        T end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        return static_cast<double>(duration) / 1000;
    }
private:
    T start;
};